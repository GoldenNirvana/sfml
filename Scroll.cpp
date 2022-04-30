#include "Scroll.hpp"

#include <utility>

Scroll::Scroll(std::string str, int xPos, int yPos, int width, int height) : Button(std::move(str), xPos, yPos, width,
                                                                                    height)
{}

void Scroll::toScroll(int sec)
{
  if (getPositionInRect() < 700)
  {
    int r = std::rand();
    if (sec < 500 || sec > 4200)
    {
      setPositionInRect(getPositionInRect() + 1);
    }
    else if (sec < 1000 || sec > 3500)
    {
      setPositionInRect(getPositionInRect() + 2);
    }
    else setPositionInRect(getPositionInRect() + r % 30);
  }
  else
  {
    setPositionInRect(100);
  }
}

bool Scroll::operator==(const Scroll &scroll) const
{
  return getPositionInRect() == scroll.getPositionInRect();
}

bool Scroll::operator!=(const Scroll &scroll) const
{
  return !operator==(scroll);
}
