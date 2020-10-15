GameHandler::GameHandler()
{
  this->game.addPlayer("George"/*, 100*/);
  this->game.addPlayer("Sarah"/*, 100*/);
  this->game.addPlayer("Henry"/*, 100*/);
  this->game.playerSetup();
  this->game.play();
  this->game.dealerResult();
  this->game.checkWinner();
}

GameHandler::~GameHandler()
{
}
