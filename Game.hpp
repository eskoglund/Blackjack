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
  int nrOfPlayers;
  Player plays;

public:
  Game();
  ~Game();

  void addPlayer(std::string name/*, int money*/);
  void playerSetup();
  void play();
  void dealerResult();
  void checkScore(int sum);
  void checkWinner();
  //bool bet(int playerBet);

};
#endif
