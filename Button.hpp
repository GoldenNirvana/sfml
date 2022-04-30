#ifndef SFML_BUTTON_HPP
#define SFML_BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <ostream>

const std::string PATH = "D:/Projects/ClionProjects/sfml/";

class Button
{
public:
  explicit Button(std::string str, int xPos = 0, int yPos = 0, int width = 0, int height = 0);
  void setPosition(float x, float y);
  void rotate(float angle);
  sf::Vector2f getPosition();
  const sf::Sprite &getSprite() const;
  void setSprite(const sf::Sprite &sprite);
  const sf::Texture &getTexture() const;
  void setTexture(const sf::Texture &texture);
  void setColor(const sf::Color &color);
  int getPositionInRect() const;
  void setPositionInRect(int positionInRect);
  void setTextureRect(const sf::IntRect &intRect);
  void setTextureRect(int xPos);
  bool isClicked(const sf::Window &window);

private:
  int positionInRect_;
  sf::Sprite sprite_;
  sf::Texture texture_;
};


#endif
