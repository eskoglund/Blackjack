#ifndef CARDS_HPP
#define CARDS_HPP
#include <ctime>

class Cards
{
private:
  int currentCard;

public:
  Cards();
  ~Cards();

  int drawCard();
};
#endif
