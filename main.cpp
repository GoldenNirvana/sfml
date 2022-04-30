#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#include "Button.hpp"
#include "Scroll.hpp"

using namespace sf;

int main()
{
  std::srand(std::time(nullptr));
  RenderWindow window(sf::VideoMode(800, 600), "Joy Casino!");

  Texture backgroung;
  backgroung.loadFromFile("D:/Projects/ClionProjects/sfml/src/cas.jpg");
  Sprite back;
  back.setTexture(backgroung);
  back.setOrigin(300, 100);


  Text text;
//  text.setPosition(200, 300);
  text.setString("You have won!!!");
  text.setFillColor(Color::Cyan);
  text.setCharacterSize(20);
  text.setFont(Font());
  Texture winBack;
  winBack.loadFromFile("D:/Projects/ClionProjects/sfml/src/win.png");
  Sprite winSprite;
  winSprite.setTexture(winBack);
  winSprite.scale(0.5, 0.5);
  winSprite.move(70, 100);


  Scroll scroll1("titles.png", 100, 100, 300, 100);
  Scroll scroll2("titles.png", 300, 100, 300, 100);
  Scroll scroll3("titles.png", 500, 100, 300, 100);
  float firstPositionByX = 55.0f;
  std::vector<Scroll> scrolls;
  scrolls.push_back(scroll1);
  scrolls.push_back(scroll2);
  scrolls.push_back(scroll3);
  for (auto &item: scrolls)
  {
    item.rotate(-90);
    item.setPosition(firstPositionByX, 420);
    firstPositionByX += 135;
  }
  Button start_button("button.jpg", 70, 130, 230, 68);
  start_button.setPosition(500, 100);
  Button stop_button("button.jpg", 420, 130, 230, 68);
  stop_button.setPosition(500, 400);
  start_button.setColor(Color::Blue);

  Clock clock;
  Time time = clock.getElapsedTime();
  int score = 0;
  bool isStart = false;
  bool isVictory = false;

  while (window.isOpen())
  {
    // Scrolling
    if (isStart)
    {
      for (auto &item: scrolls)
      {
        item.setTextureRect(item.getPositionInRect());
      }
      for (auto &item: scrolls)
      {
        if (item.getPositionInRect() < 700)
        {
          int r = std::rand();
          item.setPositionInRect(item.getPositionInRect() + r % 30 + 10);
        }
        else
        {
          item.setPositionInRect(100);
        }
      }
    }

    // Keyboards
    Event event{};
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
      if (start_button.isClicked(window) || Keyboard::isKeyPressed(Keyboard::E))
      {
        isStart = true;
        clock.restart();
        start_button.setColor(Color::Red);
      }
      if (stop_button.isClicked(window) || Keyboard::isKeyPressed(Keyboard::Space))
      {
        isStart = false;
        for (auto &item: scrolls)
        {
          item.setPositionInRect(item.getPositionInRect() / 100 * 100);
          item.setTextureRect(item.getPositionInRect());
        }
        if (scrolls[0].getPositionInRect() == scrolls[1].getPositionInRect() &&
            scrolls[0].getPositionInRect() == scrolls[2].getPositionInRect())
        {
          isVictory = true;
          score++;
        }
        start_button.setColor(Color::Blue);
      }
    }

    time = clock.getElapsedTime();
    if (time.asSeconds() > 3 && isStart)
    {
      isStart = false;
      for (auto &item: scrolls)
      {
        item.setPositionInRect((item.getPositionInRect() / 100) * 100);
        item.setTextureRect(item.getPositionInRect());
      }
      if (scrolls[0].getPositionInRect() == scrolls[1].getPositionInRect() &&
          scrolls[0].getPositionInRect() == scrolls[2].getPositionInRect())
      {
        isVictory = true;
        score++;
      }
      start_button.setColor(Color::Blue);
    }

    window.clear();
    window.draw(back);
    for (auto &item: scrolls)
    {
      window.draw(item.getSprite());
    }
    window.draw(start_button.getSprite());
    window.draw(stop_button.getSprite());
    if (isVictory)
    {
      window.draw(winSprite);
      window.draw(text);
      if (Keyboard::isKeyPressed(Keyboard::Q))
      {
        isVictory = false;
      }
    }
    window.display();
  }
  return 0;
}
