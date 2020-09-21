#include "Player.hpp"

Player::Player(std::string name)
{
  this->name = name;
  this->sum = 0;
}

Player::~Player()
{
}

std::string Player::getName() const
{
  return this->name;
}

// int Player::getSum() const
// {
//   return this->sum;
// }
void Player::setup()
{
  for (size_t i = 0; i < 2; i++)
  {
    this->sum += this->cards.drawCard();
  }
  this->game.checkScore(this->sum);
}

void Player::keepPlaying()
{
  char decision;
  while (this->sum < 21)
  {
    std::cout << "Hit(h) or stay(s)?" << std::endl;
    std::cin >> decision;
    if (decision == 'h')
    {
      this->sum += this->cards.drawCard();
      this->game.checkScore(this->sum);
    }
    else if (decision == 's')
    {
      this->game.checkScore(this->sum);
      break;
    }
  }
}
