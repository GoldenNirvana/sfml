#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Button.hpp"

using namespace sf;

int main()
{
  RenderWindow window(sf::VideoMode(800, 600), "Joy Casino!");

  Image image;
  image.loadFromFile("D:/Projects/ClionProjects/sfml/src/titles.png");

  Texture texture;

  Texture backgroung;
  backgroung.loadFromFile("D:/Projects/ClionProjects/sfml/src/cas.jpg");
  Sprite back;
  back.setTexture(backgroung);
  back.setOrigin(300, 100);

  bool isStart = false;
  bool isVictory = false;

  texture.loadFromImage(image);
  Sprite sprite;
  Sprite sprite1;
  Sprite sprite2;
  sprite.setTexture(texture);
  sprite1.setTexture(texture);
  sprite2.setTexture(texture);

  int x = 100;
  int x1 = 300;
  int x2 = 500;
  sprite.setTextureRect(IntRect(x, 100, 300, 100));
  sprite1.setTextureRect(IntRect(x1, 100, 300, 100));
  sprite2.setTextureRect(IntRect(x2, 100, 300, 100));
  sprite.setRotation(-90);
  sprite1.setRotation(-90);
  sprite2.setRotation(-90);

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


  Texture button_start;
  Texture button_stop;
  button_start.loadFromFile("D:/Projects/ClionProjects/sfml/src/button.jpg");
  button_stop.loadFromFile("D:/Projects/ClionProjects/sfml/src/button.jpg");
  Sprite button_sprite_start;
  Sprite button_sprite_stop;

  Button start_button("button.jpg", 70, 130, 230, 68);
  start_button.setPosition(500, 100);
  Button stop_button("button.jpg", 420, 130, 230, 68);
  stop_button.setPosition(500, 400);

  button_sprite_start.setTexture(button_start);
  button_sprite_start.setTextureRect(IntRect(70, 130, 230, 68));
  button_sprite_stop.setTexture(button_stop);
  button_sprite_stop.setTextureRect(IntRect(420, 130, 230, 68));
  button_sprite_start.setPosition(500, 100);
  button_sprite_stop.setPosition(500, 400);

  sprite.setPosition(55, 420);
  sprite1.setPosition(190, 420);
  sprite2.setPosition(325, 420);
  button_sprite_start.setColor(Color::Blue);

  Clock clock;
  Time time = clock.getElapsedTime();
  int score = 0;

  while (window.isOpen())
  {
    Event event{};
    if (isStart)
    {
      sprite.setTextureRect(IntRect(x, 100, 300, 100));
      sprite1.setTextureRect(IntRect(x1, 100, 300, 100));
      sprite2.setTextureRect(IntRect(x2, 100, 300, 100));
      if (x < 700)
      {
        x += 15;
      }
      if (x >= 700)
      {
        x = 100;
      }
      if (x1 < 700)
      {
        x1 += 25;
      }
      if (x1 >= 700)
      {
        x1 = 100;
      }
      if (x2 < 700)
      {
        x2 += 20;
      }
      if (x2 >= 700)
      {
        x2 = 100;
      }
    }
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
      if (IntRect(500, 100, 230, 68).contains(Mouse::getPosition(window)) && Mouse::isButtonPressed(Mouse::Left)
          || Keyboard::isKeyPressed(Keyboard::E))
      {
        isStart = true;
        clock.restart();
        button_sprite_start.setColor(Color::Red);
      }
      if (IntRect(500, 400, 230, 68).contains(Mouse::getPosition(window)) && Mouse::isButtonPressed(Mouse::Left)
          || Keyboard::isKeyPressed(Keyboard::Space))
      {
        isStart = false;
        x = x / 100 * 100;
        x1 = x1 / 100 * 100;
        x2 = x2 / 100 * 100;
        sprite.setTextureRect(IntRect(x, 100, 300, 100));
        sprite1.setTextureRect(IntRect(x1, 100, 300, 100));
        sprite2.setTextureRect(IntRect(x2, 100, 300, 100));
        if (x == x1 && x == x2)
        {
          isVictory = true;
          score++;
        }
        button_sprite_start.setColor(Color::Blue);
      }
    }

    time = clock.getElapsedTime();
    if (time.asSeconds() > 3 && isStart)
    {
      isStart = false;
      x = x / 100 * 100;
      x1 = x1 / 100 * 100;
      x2 = x2 / 100 * 100;
      sprite.setTextureRect(IntRect(x, 100, 300, 100));
      sprite1.setTextureRect(IntRect(x1, 100, 300, 100));
      sprite2.setTextureRect(IntRect(x2, 100, 300, 100));
      if (x == x1 && x == x2)
      {
        isVictory = true;
        score++;
      }
      button_sprite_start.setColor(Color::Blue);
    }

    window.clear();
    window.draw(back);
    window.draw(sprite);
    window.draw(sprite1);
    window.draw(sprite2);
    window.draw(start_button.getSprite());
    window.draw(stop_button.getSprite());
//    window.draw(button_sprite_start);
//    window.draw(button_sprite_stop);
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
