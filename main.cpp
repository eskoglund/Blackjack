#include "Player.hpp"
#include "Player.cpp"
#include "Dealer.hpp"
#include "Dealer.cpp"
#include "Cards.hpp"
#include "Cards.cpp"
#include "Game.hpp"
#include "Game.cpp"

int main() {
  Player player("Henry");
  Dealer dealer("Dealer");

  std::cout << player.getName() << std::endl;
  player.setup();
  std::cout << std::endl << dealer.getName() << std::endl;
  dealer.setup();
  std::cout << std::endl << player.getName() << std::endl;
  player.keepPlaying();
  std::cout << std::endl << dealer.getName() << std::endl;
  dealer.checkResult(player.getSum());
  Game winner(player.getSum(), dealer.getSum());
  winner.checkWinner();

  return 0;
}
