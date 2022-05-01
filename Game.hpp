#ifndef SFML_GAME_HPP
#define SFML_GAME_HPP

#include "Scroll.hpp"
#include "Button.hpp"
#include "GameState.hpp"

class Game
{
public:
  Game();
  void play();
  bool checkWin(const std::vector<Scroll> &scrolls);
  static void createScrolls(std::vector<Scroll> &vector);
  static void createButtons(std::vector<Button> &vector);
  void drawObjects(sf::RenderWindow &window, std::vector<Button> &vector);
  void drawObjects(sf::RenderWindow &window, std::vector<Scroll> &vector);
  void stopGame(sf::RenderWindow &window, std::vector<Scroll> &vector, bool &isWin);
  void showGameResult(sf::RenderWindow &window, bool &isWin);

private:
  GameState gameState_;
  int score_;
};

#endif
