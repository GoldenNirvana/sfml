#include "Game.hpp"

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

#include "Scroll.hpp"
#include "Button.hpp"

using namespace sf;

const int SCROLL_TIME = 5;

void Game::play()
{
  std::srand(std::time(nullptr));
  RenderWindow window(sf::VideoMode(800, 600), "Joy Casino!");

  Texture backgroung;
  backgroung.loadFromFile("D:/Projects/ClionProjects/sfml/src/cas.jpg");
  Sprite back;
  back.setTexture(backgroung);
  back.setOrigin(300, 100);


  std::vector<Scroll> scrolls;
  createScrolls(scrolls);
  std::vector<Button> buttons;
  createButtons(buttons);

  Clock clock;
  Time time = clock.getElapsedTime();

  bool isWin = false;

  while (window.isOpen())
  {
    // Scrolling
    if (gameState_.getState() == GameState::State::Running)
    {
      for (auto &item: scrolls)
      {
        item.setTextureRect(item.getPositionInRect());
      }
      for (auto &item: scrolls)
      {
        item.toScroll(time.asMilliseconds());
      }
    }

    // Keyboards
    Event event{};
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
      if ((buttons[0].isClicked(window) || Keyboard::isKeyPressed(Keyboard::E)) &&
          gameState_.getState() == GameState::State::Waiting)
      {
        gameState_.doNext();
        clock.restart();
        buttons[0].setColor(Color::Red);
      }
      if ((buttons[1].isClicked(window) || Keyboard::isKeyPressed(Keyboard::Space)) &&
          gameState_.getState() == GameState::State::Running)
      {
        gameState_.doNext();
        stopGame(scrolls, isWin);
        buttons[0].setColor(Color::Blue);
      }
      if (Keyboard::isKeyPressed(Keyboard::W) && gameState_.getState() == GameState::State::Exiting)
      {
        isWin = false;
        gameState_.doNext();
      }
    }

    // Else logic
    time = clock.getElapsedTime();
    if (time.asSeconds() > SCROLL_TIME && gameState_.getState() == GameState::State::Running)
    {
      gameState_.doNext();
      stopGame(scrolls, isWin);
      buttons[0].setColor(Color::Blue);
    }

    // Display

    window.clear();
    window.draw(back);
    drawObjects(window, scrolls);
    drawObjects(window, buttons);
    if (gameState_.getState() == GameState::State::Exiting)
    {
      showGameResult(window, isWin);
    }
    window.display();
    std::cout << gameState_.getState() << '\n';
  }
}

bool Game::checkWin(const std::vector<Scroll> &scrolls)
{
  for (int i = 0; i < scrolls.size() - 1; ++i)
  {
    if (scrolls[i] != scrolls[i + 1])
    {
      return false;
    }
  }
  return true;
}

void Game::createScrolls(std::vector<Scroll> &vector)
{
  Scroll *scroll1 = new Scroll("titles.png", 100, 100, 300, 100);
  Scroll *scroll2 = new Scroll("titles.png", 300, 100, 300, 100);
  Scroll *scroll3 = new Scroll("titles.png", 500, 100, 300, 100);
  float firstPositionByX = 55.0f;
  vector.push_back(*scroll1);
  vector.push_back(*scroll2);
  vector.push_back(*scroll3);
  for (auto &item: vector)
  {
    item.rotate(-90);
    item.setPosition(firstPositionByX, 420);
    firstPositionByX += 135;
  }
}

void Game::createButtons(std::vector<Button> &vector)
{
  Button *start_button = new Button("button.jpg", 70, 130, 230, 68);
  start_button->setPosition(500, 100);
  Button *stop_button = new Button("button.jpg", 420, 130, 230, 68);
  stop_button->setPosition(500, 400);
  start_button->setColor(Color::Blue);
  vector.push_back(*start_button);
  vector.push_back(*stop_button);
}

void Game::drawObjects(sf::RenderWindow &window, std::vector<Button> &vector)
{
  for (auto &item: vector)
  {
    window.draw(item.getSprite());
  }
}

void Game::drawObjects(RenderWindow &window, std::vector<Scroll> &vector)
{
  for (auto &item: vector)
  {
    window.draw(item.getSprite());
  }
}

void Game::stopGame(std::vector<Scroll> &vector, bool &isWin)
{
  for (auto &item: vector)
  {
    item.setPositionInRect(item.getPositionInRect() / 100 * 100);
    item.setTextureRect(item.getPositionInRect());
  }
  if (checkWin(vector))
  {
    isWin = true;
    score_++;
    vector[0].setPositionInRect(vector[0].getPositionInRect() + 100); // unable to win twice
  }
}

void Game::showGameResult(sf::RenderWindow &window, bool &isWin)
{
  Font font;
  font.loadFromFile("D:/Projects/ClionProjects/sfml/fonts/CyrilicOld.TTF");
  Text text("", font, 40);
  text.setFillColor(Color::Black);
  text.setStyle(Text::Bold | Text::Underlined);

  Texture winBack;
  winBack.loadFromFile("D:/Projects/ClionProjects/sfml/src/win.png");
  Sprite winSprite;
  winSprite.setTexture(winBack);
  winSprite.scale(0.5, 0.5);
  winSprite.move(70, 100);
  window.draw(winSprite);

  if (!isWin)
  {
    text.setPosition(300, 240);
    text.setString("You lose!");
    window.draw(text);
  }
  else
  {
    std::ostringstream scoreString;
    scoreString << score_;
    text.setString("You won! Number of scores: " + scoreString.str());
    text.setPosition(120, 240);
    window.draw(text);
  }

}

Game::Game()
{
  score_ = 0;
}
