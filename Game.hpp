#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include "Cards.hpp"
#include "Player.hpp"

class Game
{
private:
  Cards deck;
  Player* *player;
  Player dealer;
  int nrOfPlayers;

public:
  Game();
  ~Game();

  void addPlayer(std::string name);
  void playerSetup();
  void play();
  void dealerResult();
  void checkScore(int sum);
  void checkWinner();

};
#endif
