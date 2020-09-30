#include "Game.hpp"

Game::Game()
{
}
Game::~Game()
{
}

void Game::playerSetup()
{
  std::cout << player.getName() << " starting hand:" << std::endl;
  for (int i = 0; i < 2; i++)
  {
    this->player.addScore(this->deck.drawCard(this->player.getSum()));
  }
  checkScore(this->player.getSum());
}

void Game::dealerSetup()
{
  std::cout << dealer.getName() << " starting hand:" << std::endl;
  this->dealer.addScore(this->deck.drawCard(this->dealer.getSum()));
  checkScore(this->dealer.getSum());
}

void Game::keepPlaying()
{
  char decision;
  std::cout << std::endl << this->player.getName() << std::endl;
  checkScore(this->player.getSum());
  while (this->player.getSum() < 21)
  {
    std::cout << "Hit(h) or stand(s)?" << std::endl;
    std::cin >> decision;
    if (decision == 'h')
    {
      this->player.addScore(this->deck.drawCard(this->player.getSum()));
      checkScore(this->player.getSum());
    }
    else if (decision == 's')
    {
      checkScore(this->player.getSum());
      break;
    }
  }
}

void Game::dealerResult()
{
  std::cout << std::endl << this->dealer.getName() << std::endl;
  if (this->player.getSum() > 21)
  {
    std::cout << this->dealer.getName() << " wins." << std::endl;
  }
  else
  {
    while (this->dealer.getSum() < 17)
    {
      this->dealer.addScore(this->deck.drawCard(this->dealer.getSum()));
    }
    checkScore(this->dealer.getSum());
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
  if (this->player.getSum() <= 21 && this->dealer.getSum() > 21)
  {
    std::cout << this->player.getName() << " wins." << std::endl;
  }
  if (this->player.getSum() <= 21 && this->dealer.getSum() <= 21)
  {
    if (this->player.getSum() > this->dealer.getSum())
    {
      std::cout << this->player.getName() << " wins." << std::endl;
    }
    else if (this->dealer.getSum() > this->player.getSum())
    {
      std::cout << this->dealer.getName() << " wins." << std::endl;
    }
    else
    {
      std::cout << "Stand off!" << std::endl;
    }
  }
}
