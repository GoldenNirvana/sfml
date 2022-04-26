#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
  RenderWindow window(sf::VideoMode(800, 600), "Test!");

  Image image;
  image.loadFromFile("D:/Projects/ClionProjects/sfml/src/titles.png");

  Texture texture;
  texture.loadFromImage(image);

  Sprite sprite;
  sprite.setTexture(texture);
  int x, y;
  x = 100;
  y = 100;
  sprite.setTextureRect(IntRect(x, y, 300, 100));


  sprite.setPosition(50, 50);

  while (window.isOpen())
  {
    Event event{};
    while (window.pollEvent(event))
    {
      if (Keyboard::isKeyPressed(Keyboard::Right))
      {
        sprite.setTextureRect(IntRect(x, y, 300, 100));
        x += 10;
      }
      if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
    }
    window.clear();
    window.draw(sprite);
    window.display();
  }
  return 0;
}
