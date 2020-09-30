#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <string>

class Player
{
private:
  std::string name;
  int sum;

public:
  Player(std::string name = "Player");
  ~Player();

  std::string getName() const;
  int getSum() const;
  void addScore(int score);
  
};
#endif
