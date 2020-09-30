#include "Dealer.hpp"

Dealer::Dealer(std::string name)
{
  this->name = name;
  this->sum = 0;
}

Dealer::~Dealer()
{
}

std::string Dealer::getName() const
{
  return this->name;
}

int Dealer::getSum() const
{
  return this->sum;
}

void Dealer::addScore(int score)
{
  this->sum += score;
}
