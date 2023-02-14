#pragma once
#include "Coord.h"

Coord::Coord() :x(), y() {}

Coord::Coord(float x, float y) : x(x), y(y) {}

bool Coord::operator == (const Coord& obj) {
  return x == obj.x && y == obj.y;
}
void Coord::SetCoord(const Coord obj) { x = obj.x, y = obj.y; }