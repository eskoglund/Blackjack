#ifndef DEALER_HPP
#define DEALER_HPP
#include "Cards.hpp"
#include "Game.hpp"
#include <string>

class Dealer
{
private:
  std::string name;
  int sum;
  Cards cards;
  Game game;

public:
  Dealer(std::string = "Dealer");
  ~Dealer();

  std::string getName() const;
  //int getSum() const;
  void setup();
  void checkTotal();
};
#endif
