#include "Scroll.hpp"

#include <utility>

Scroll::Scroll(std::string str, int xPos, int yPos, int width, int height) : Button(std::move(str), xPos, yPos, width,
                                                                                    height)
{}

void Scroll::toScroll(int sec)
{
  int r = std::rand();
  if (sec < 400 || sec > 4600)
  {
    setPositionInRect(getPositionInRect() + 1);
  }
  else if (sec < 800 || sec > 4200)
  {
    setPositionInRect(getPositionInRect() + 2);
  }
  else if (sec < 1200 || sec > 3800)
  {
    setPositionInRect(getPositionInRect() + 5);
  }
  else if (sec < 1600 || sec > 3400)
  {
    setPositionInRect(getPositionInRect() + 10);
  }
  else if (sec < 2000 || sec > 3000)
  {
    setPositionInRect(getPositionInRect() + 10 + r % 15);
  }
  else
    setPositionInRect(getPositionInRect() + 20 + r % 25);

  if (getPositionInRect() >= 700)
  {
    setPositionInRect(100 + getPositionInRect() % 700);
  }
  setTextureRect(getPositionInRect());
}

bool Scroll::operator==(const Scroll &scroll) const
{
  return getPositionInRect() == scroll.getPositionInRect();
}

bool Scroll::operator!=(const Scroll &scroll) const
{
  return !operator==(scroll);
}
