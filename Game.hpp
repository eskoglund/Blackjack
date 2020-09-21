#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>

class Game
{
private:
  int result;

public:
  Game(int result = 0);
  ~Game();

  void checkScore(int sum);
  void checkWinner(int sum);
};
#endif
