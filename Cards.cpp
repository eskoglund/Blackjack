#include "Cards.hpp"

Cards::Cards(int decks)
{
  this->nrOfDecks = decks;
  for (int i = 2; i < 15; i++)
  {
    for (int k = 0; k < 4 * this->nrOfDecks; k++)
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

  if (*currentCard == 11 && sum + *currentCard > 21)
  {
    *currentCard = 1;
    returnedCard = *currentCard;
  }

  return returnedCard;
}
