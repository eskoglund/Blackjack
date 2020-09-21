#include "Cards.hpp"

Cards::Cards()
{
  this->currentCard = 0;
}

Cards::~Cards()
{
}

int Cards::drawCard()
{
  srand(time(0));
  this->currentCard = rand() % 11 + 1;
  return this->currentCard;
}
