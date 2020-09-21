#include "Game.hpp"

Game::Game(int result)
{
  this->result = result;
}

Game::~Game()
{
}

void Game::checkScore(int sum)
{
  if (sum > 21)
  {
    std::cout << "Final result: " << sum << std::endl;
    std::cout << "Game over." << std::endl;
  }
  else if (sum == 21)
  {
    std::cout << "Final Result: " << sum << std::endl;
    std::cout << "Blackjack!" << std::endl;
    this->result = sum;
  }
  else
  {
    std::cout << "Result: " << sum << std::endl;
    this->result = sum;
  }
}

void Game::checkWinner(int sum)
{
  if (sum > this->result)
  {
    std::cout << "Player wins." << std::endl;
  }
  else if (this->result > sum)
  {
    std::cout << "Dealer wins." << std::endl;
  }
  else
  {
    std::cout << "It's a tie." << std::endl;
  }
}
