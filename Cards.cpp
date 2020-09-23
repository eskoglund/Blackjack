#include "Cards.hpp"

Cards::Cards()
{
  this->currentCard = 0;
  this->ace = 0;
}

Cards::~Cards()
{
}

int Cards::drawCard()
{
  srand(time(0));
  this->currentCard = rand() % 11 + 1;
  if (this->currentCard == 11 && ace > 0)
  {
    this->currentCard = 1;
  }
  if (this->currentCard == 11)
  {
    ace++;
  }
  
  return this->currentCard;
}
