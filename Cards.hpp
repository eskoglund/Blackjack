#ifndef CARDS_HPP
#define CARDS_HPP
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>

class Cards
{
private:
  std::vector<int> cardDeck;
  int nrOfDecks;

public:
  Cards(int decks = 1);
  ~Cards();

  int drawCard(int sum);

};
#endif
