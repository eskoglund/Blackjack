#include "Game.hpp"

Game::Game(int playerResult, int dealerResult)
{
  this->playerResult = playerResult;
  this->dealerResult = dealerResult;
}

Game::~Game()
{
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
  if (this->playerResult <= 21 && this->dealerResult > 21)
  {
    std::cout << "Player wins." << std::endl;
  }
  if (this->playerResult <= 21 && this->dealerResult <= 21)
  {
    if (this->playerResult > this->dealerResult)
    {
      std::cout << "Player wins." << std::endl;
    }
    else if (this->dealerResult > this->playerResult)
    {
      std::cout << "Dealer wins." << std::endl;
    }
    else
    {
      std::cout << "It's a tie." << std::endl;
    }
  }
}
