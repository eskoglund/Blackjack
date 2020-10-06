#include "Player.hpp"
#include "Player.cpp"
#include "Dealer.hpp"
#include "Dealer.cpp"
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
  game.dealerSetup();
  game.keepPlaying();
  game.dealerResult();
  game.checkWinner();

  return 0;
}
