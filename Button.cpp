#include "Button.hpp"

#include <iostream>

Button::Button(std::string str, int xPos, int yPos, int width, int height)
{
  texture_.loadFromFile("../textures/" + str);
  sprite_.setTextureRect(sf::IntRect(xPos, yPos, width, height));
  sprite_.setTexture(texture_);
  positionInRect_ = xPos;
}

void Button::setPosition(float x, float y)
{
  sprite_.setPosition(x, y);
}

void Button::rotate(float angle)
{
  sprite_.rotate(angle);
}

sf::Vector2f Button::getPosition()
{
  return sprite_.getPosition();
}

const sf::Sprite &Button::getSprite() const
{
  return sprite_;
}

void Button::setSprite(const sf::Sprite &sprite)
{
  sprite_ = sprite;
}

const sf::Texture &Button::getTexture() const
{
  return texture_;
}

void Button::setTexture(const sf::Texture &texture)
{
  texture_ = texture;
}

void Button::setColor(const sf::Color &color)
{
  sprite_.setColor(color);
}

void Button::setTextureRect(const sf::IntRect &intRect)
{
  sprite_.setTextureRect(intRect);
}

int Button::getPositionInRect() const
{
  return positionInRect_;
}

void Button::setPositionInRect(int positionInRect)
{
  positionInRect_ = positionInRect;
}

void Button::setTextureRect(int xPos)
{
  sf::IntRect tempRect = sprite_.getTextureRect();
  sprite_.setTextureRect({xPos, tempRect.top, tempRect.width, tempRect.height});
}

bool Button::isClicked(const sf::Window &window)
{
  sf::IntRect tempRect = sprite_.getTextureRect();
  sf::Vector2f pos = sprite_.getPosition();
  return sf::IntRect(pos.x, pos.y, tempRect.width, tempRect.height).contains(sf::Mouse::getPosition(window))
         && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
