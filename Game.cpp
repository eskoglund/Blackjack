#include "Game.hpp"

Game::Game()
{
  this->player[0] = new Player("Dealer");
  this->nrOfPlayers = 0;
}

Game::~Game()
{
  for (int i = 0; i <= this->nrOfPlayers; i++)
  {
    if (this->player[i] != nullptr)
    {
      delete this->player[i];
    }
  }
}

void Game::addPlayer(std::string name/*, int money*/)
{
  this->player[++this->nrOfPlayers] = new Player(name/*, money*/);
}

void Game::playerSetup()
{
  for (int i = this->nrOfPlayers; i >= 0; i--)
  {
    std::cout << this->player[i]->getName() << "'s" << " starting hand:" << std::endl;
    this->player[i]->addScore(this->deck.drawCard(this->player[i]->getSum()));
    checkScore(this->player[i]->getSum());
  }
}

void Game::play()
{
  char decision;
  //int playerBet = 0;

  for (int i = this->nrOfPlayers; i > 0; i--)
  {
    std::cout << std::endl << this->player[i]->getName() << std::endl;
    //std::cout << "How much do you want to bet?" << std::endl;
    //std::cin >> playerBet;
    //std::cin.ignore();
    //if (bet(playerBet))
    //{
    this->player[i]->addScore(this->deck.drawCard(this->player[i]->getSum()));
    checkScore(this->player[i]->getSum());
    while (this->player[i]->getSum() < 21)
    {
      if (this->player[i]->getCards() == 2)
      {
        std::cout << "Hit(h), stand(s) or double down(d)?" << std::endl;
        std::cin >> decision;
      }
      else
      {
        std::cout << "Hit(h) or stand(s)?" << std::endl;
        std::cin >> decision;
      }
      if (decision == 'h')
      {
        this->player[i]->addScore(this->deck.drawCard(this->player[i]->getSum()));
        checkScore(this->player[i]->getSum());
      }
      else if (decision == 'd' && this->player[i]->getCards() == 2)
      {
        this->player[i]->addScore(this->deck.drawCard(this->player[i]->getSum()));
        checkScore(this->player[i]->getSum());
        break;
      }
      else if (decision == 's')
      {
        checkScore(this->player[i]->getSum());
        break;
      }
    }
    //}
  }
}

void Game::dealerResult()
{
  int lost = 0;

  for (int i = 1; i <= this->nrOfPlayers; i++)
  {
    if (this->player[i]->getSum() > 21)
    {
      lost++;
    }
  }

  if(lost != this->nrOfPlayers)
  {
    while (this->player[0]->getSum() < 17)
    {
      this->player[0]->addScore(this->deck.drawCard(this->player[0]->getSum()));
    }
    std::cout << std::endl << this->player[0]->getName() << std::endl;
    checkScore(this->player[0]->getSum());
  }
}

void Game::checkScore(int sum)
{
  if (sum > 21)
  {
    std::cout << "Final result: " << sum << std::endl;
    std::cout << "Bust!" << std::endl;
  }
  else if (sum == 21)
  {
    std::cout << "Final result: " << sum << std::endl;
    std::cout << "Blackjack!" << std::endl;
  }
  else
  {
    std::cout << "Result: " << sum << std::endl;
  }
}

void Game::checkWinner()
{
  for (int i = 1; i <= this->nrOfPlayers; i++)
  {
    if (this->player[i]->getSum() <= 21 && this->player[0]->getSum() > 21)
    {
      std::cout << this->player[i]->getName() << " wins." << std::endl;
    }
    if (this->player[i]->getSum() <= 21 && this->player[0]->getSum() <= 21)
    {
      if (this->player[i]->getSum() > this->player[0]->getSum())
      {
        std::cout << this->player[i]->getName() << " wins." << std::endl;
      }
      else if (this->player[0]->getSum() > this->player[i]->getSum())
      {
        std::cout << this->player[i]->getName() << " loses." << std::endl;
      }
      else
      {
        std::cout << this->player[i]->getName() << " is tied with " << this->player[0]->getName() << "." << std::endl;
      }
    }
  }
}

// bool Game::bet(int playerBet)
// {
//   bool money = false;
//
//   for (int i = this->nrOfPlayers; i > 0; i--)
//   {
//     if (this->player[i]->getMoney() < 0 || playerBet > this->player[i]->getMoney())
//     {
//       std::cout << "Insufficient amount." << std::endl;
//       std::cout << "Remaining amount: " << this->player[i]->getMoney() << std::endl;
//     }
//     else
//     {
//       this->player[i]->betMoney(playerBet);
//       money= true;
//     }
//   }
//
//   return money;
// }
