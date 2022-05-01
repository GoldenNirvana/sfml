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
  RenderWindow window(sf::VideoMode(800, 600), "Joy Casino!", Style::Titlebar);

  Texture background;
  background.loadFromFile("../src/cas1.jpg");
  Sprite back;
  back.setTexture(background);
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
        item.toScroll(time.asMilliseconds());
      }
      Time delay = milliseconds(3);
      sf::sleep(delay);
    }

    // Keyboards
    Event event{};
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed ||
          (Keyboard::isKeyPressed(Keyboard::Escape)) && gameState_.getState() == GameState::State::Waiting)
        window.close();
      if ((buttons[0].isClicked(window) || Keyboard::isKeyPressed(Keyboard::E)) &&
          gameState_.getState() == GameState::State::Waiting)
      {
        gameState_.doNext();
        clock.restart();
      }
      if ((buttons[1].isClicked(window) || Keyboard::isKeyPressed(Keyboard::Space)) &&
          gameState_.getState() == GameState::State::Running)
      {
        gameState_.doNext();
        stopGame(window, scrolls, isWin);
      }
      if ((Keyboard::isKeyPressed(Keyboard::Q) ||
           (Mouse::isButtonPressed(Mouse::Left) && IntRect(270, 350, 230, 68).contains(Mouse::getPosition(window))))
          && gameState_.getState() == GameState::State::Exiting)
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
      window.clear();
      window.draw(back);
      drawObjects(window, buttons);
      stopGame(window, scrolls, isWin);
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
  }

  scrolls.clear();
  buttons.clear();
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
  Scroll *scroll1 = new Scroll("../textures/titles.png", 100, 100, 300, 100);
  Scroll *scroll2 = new Scroll("../textures/titles.png", 300, 100, 300, 100);
  Scroll *scroll3 = new Scroll("../textures/titles.png", 500, 100, 300, 100);
  float firstPositionByX = 60.0f;
  vector.push_back(*scroll1);
  vector.push_back(*scroll2);
  vector.push_back(*scroll3);
  for (auto &item: vector)
  {
    item.rotate(-90);
    item.setPosition(firstPositionByX, 440);
    firstPositionByX += 135;
  }
}

void Game::createButtons(std::vector<Button> &vector)
{
  Button *start_button = new Button("button.jpg", 70, 130, 230, 68);
  start_button->setPosition(465, 142);
  Button *stop_button = new Button("button.jpg", 420, 130, 230, 68);
  stop_button->setPosition(465, 370);
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

void Game::stopGame(sf::RenderWindow &window, std::vector<Scroll> &vector, bool &isWin)
{
  for (int i = 0; i < vector.size(); i++)
  {
    int tempX = (vector[i].getPositionInRect() / 100 + 1) * 100;
    while (vector[i].getPositionInRect() < tempX)
    {
      vector[i].setPositionInRect(vector[i].getPositionInRect() + 1);
      vector[i].setTextureRect(vector[i].getPositionInRect());
      window.draw(vector[i].getSprite());
      for (int j = i + 1; j < vector.size(); j++)
      {
        vector[j].toScroll(1);
        window.draw(vector[j].getSprite());
      }
      window.display();
      sleep(Time(milliseconds(3)));
    }
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
  font.loadFromFile("../fonts/CyrilicOld.TTF");
  Text text("", font, 40);
  text.setFillColor(Color::Black);
  text.setStyle(Text::Bold | Text::Underlined);

  Texture winBack;
  winBack.loadFromFile("../src/win.png");
  Sprite winSprite;
  winSprite.setTexture(winBack);
  winSprite.scale(0.5, 0.5);
  winSprite.move(70, 100);
  window.draw(winSprite);

  Button button("button.jpg", 420, 130, 230, 68);
  button.setPosition(270, 350);
  window.draw(button.getSprite());

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
