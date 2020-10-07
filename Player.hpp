#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

class Player
{
private:
  std::string name;
  int sum;
  int nrOfCards;
  //int money;

public:
  Player(std::string name = "Player");
  ~Player();

  std::string getName() const;
  int getSum() const;
  void addScore(int score);
  int getCards() const;
  //int getMoney() const;
  //void betMoney(int bet);
  //void wonMoney(int amount);

};
#endif
