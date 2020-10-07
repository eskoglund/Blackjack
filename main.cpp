#include "Player.hpp"
#include "Player.cpp"
#include "Cards.hpp"
#include "Cards.cpp"
#include "Game.hpp"
#include "Game.cpp"

int main() {

  Game game;
  game.addPlayer("George");
  game.addPlayer("Sarah");
  game.addPlayer("Henry");
  game.playerSetup();
  game.play();
  game.dealerResult();
  game.checkWinner();

  return 0;
}
