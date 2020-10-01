#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include "Cards.hpp"
#include "Player.hpp"
#include "Dealer.hpp"

class Game
{
private:
  Cards deck;
  Player *player;
  Dealer dealer;

public:
  Game();
  ~Game();

  void playerSetup();
  void dealerSetup();
  void keepPlaying();
  void dealerResult();
  void checkScore(int sum);
  void checkWinner();

};
#endif
