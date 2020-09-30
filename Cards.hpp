#ifndef CARDS_HPP
#define CARDS_HPP
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>
//using namespace std;

class Cards
{
private:
  std::vector<int> cardDeck;
  int nrOfAces;

public:
  Cards();
  ~Cards();

  int drawCard(int sum);

};
#endif
