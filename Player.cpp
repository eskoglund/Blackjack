#include "Player.hpp"

Player::Player(std::string name, int money)
{
  this->name = name;
  this->money = money;
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

int Player::getMoney() const
{
  return this->money;
}

void Player::betMoney(int bet)
{
  this->money -= bet;
}

void Player::wonMoney(int amount)
{
  this->money += amount;
}
