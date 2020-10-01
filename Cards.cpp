#include "Cards.hpp"

Cards::Cards()
{
  this->nrOfAces = 0;
  for (int i = 2; i < 15; i++)
  {
    for (int k = 0; k < 4; k++)
    {
      if (i > 11)
      {
        this->cardDeck.push_back(10);
      }
      else
      {
        this->cardDeck.push_back(i);
      }
    }
  }
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(this->cardDeck.begin(), this->cardDeck.end(), std::default_random_engine(seed));
}

Cards::~Cards()
{
}

int Cards::drawCard(int sum)
{
  int returnedCard = 0;
  auto currentCard = this->cardDeck.begin();
  this->cardDeck.erase(currentCard);
  returnedCard = *currentCard;

  if (*currentCard == 11 && this->nrOfAces > 0)
  {
    *currentCard = 1;
    returnedCard = *currentCard;
    this->nrOfAces = 0;
  }
  if (*currentCard == 11)
  {
    this->nrOfAces++;
    if (sum + *currentCard > 21)
    {
      *currentCard = 1;
      returnedCard = *currentCard;
      std::cout << "Over" << std::endl;
    }
  }

  return returnedCard;
}
