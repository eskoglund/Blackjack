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

// int Dealer::getSum() const
// {
//   return this->sum;
// }

void Dealer::setup()
{
  this->sum = this->cards.drawCard();
  this->game.checkScore(this->sum);
}

void Dealer::checkTotal()
{
  this->sum += this->cards.drawCard();
  while (this->sum <= 17 && this->sum < 21)
  {
    this->sum += this->cards.drawCard();
  }
  this->game.checkScore(this->sum);
}
