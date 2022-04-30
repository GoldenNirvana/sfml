#include <iostream>

#include "Game.hpp"

using namespace sf;

int main()
{
  Game game;
  try
  {
    game.play();
  }
  catch (const std::exception &exception)
  {
    std::cerr << exception.what();
    return 1;
  }
  return 0;
}
