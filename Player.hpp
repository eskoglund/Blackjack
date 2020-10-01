#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

class Player
{
private:
  std::string name;
  int sum;
  int money;

public:
  Player(std::string name = "Player", int money = 0);
  ~Player();

  std::string getName() const;
  int getSum() const;
  void addScore(int score);
  int getMoney() const;
  void betMoney(int bet);
  void wonMoney(int amount);

};
#endif
