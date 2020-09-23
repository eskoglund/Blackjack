#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>

class Game
{
private:
  int playerResult;
  int dealerResult;

public:
  Game(int playerResult = 0, int dealerResult = 0);
  ~Game();

  void checkScore(int sum);
  void checkWinner();
};
#endif
