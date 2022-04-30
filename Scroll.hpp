#ifndef SFML_SCROLL_HPP
#define SFML_SCROLL_HPP

#include <SFML/Graphics.hpp>
#include "Button.hpp"

class Scroll : public Button
{
public:
  explicit Scroll(std::string str, int xPos = 0, int yPos = 0, int width = 0, int height = 0);
  void toScroll(int sec);

  bool operator==(const Scroll &scroll) const;
  bool operator!=(const Scroll &scroll) const;
};


#endif
