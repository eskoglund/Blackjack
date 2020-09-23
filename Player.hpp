#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Cards.hpp"
#include "Game.hpp"
#include <string>

class Player
{
private:
  std::string name;
  int sum;
  Cards cards;
  Game game;

public:
  Player(std::string name = "Player");
  ~Player();

  std::string getName() const;
  int getSum() const;
  void setup();
  void keepPlaying();
};
#endif
