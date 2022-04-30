#include "Button.hpp"

#include <iostream>

Button::Button(std::string str, int xPos, int yPos, int width, int height)
{
  texture_.loadFromFile(PATH + "textures/" + str);
  sprite_.setTextureRect(sf::IntRect(xPos, yPos, width, height));
  sprite_.setTexture(texture_);
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
