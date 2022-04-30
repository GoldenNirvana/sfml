#include "Scroll.hpp"

#include <utility>

Scroll::Scroll(std::string str, int xPos, int yPos, int width, int height) : Button(std::move(str), xPos, yPos, width, height)
{}
