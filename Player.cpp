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

int Player::getSum() const
{
  return this->sum;
}

void Player::addScore(int score)
{
  this->sum += score;
}
