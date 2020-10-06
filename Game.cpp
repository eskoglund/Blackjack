#include "Game.hpp"

Game::Game()
{
  this->player[0] = new Player("Dealer");
  this->nrOfPlayers = 0;
}
Game::~Game()
{
  for (int i = 0; i < this->nrOfPlayers; i++)
  {
    if (this->player[i] != nullptr)
    {
      delete this->player[i];
    }
  }
}

void Game::addPlayer(std::string name)
{
  this->player[++this->nrOfPlayers] = new Player(name);
}

void Game::playerSetup()
{
  for (int i = 1; i <= this->nrOfPlayers; i++)
  {
    std::cout << this->player[i]->getName() << "'s" << " starting hand:" << std::endl;
    this->player[i]->addScore(this->deck.drawCard(this->player[i]->getSum()));
    checkScore(this->player[i]->getSum());
  }
}

void Game::dealerSetup()
{
  std::cout << this->player[0]->getName() << "'s" << " starting hand:" << std::endl;
  this->player[0]->addScore(this->deck.drawCard(this->player[0]->getSum()));
  checkScore(this->player[0]->getSum());
}

void Game::keepPlaying()
{
  char decision;
  for (int i = 1; i <= this->nrOfPlayers; i++)
  {
    std::cout << std::endl << this->player[i]->getName() << std::endl;
    checkScore(this->player[i]->getSum());
    while (this->player[i]->getSum() < 21)
    {
      std::cout << "Hit(h) or stand(s)?" << std::endl;
      std::cin >> decision;
      if (decision == 'h')
      {
        this->player[i]->addScore(this->deck.drawCard(this->player[i]->getSum()));
        checkScore(this->player[i]->getSum());
      }
      else if (decision == 's')
      {
        checkScore(this->player[i]->getSum());
        break;
      }
    }
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
    std::cout << "Final Result: " << sum << std::endl;
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
        std::cout << this->player[i]->getName() << " looses." << std::endl;
      }
      else
      {
        std::cout << this->player[i]->getName() << " is stand off with " << this->player[0]->getName() << "." << std::endl;
      }
    }
  }
}
