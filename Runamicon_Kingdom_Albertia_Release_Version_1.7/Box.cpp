#include "Box.h"

Box::Box() :height(), width() {}

Box::Box(float x, float y, float height, float width) : Coord(x, y), height(height), width(width) {}

bool Box::isOverlap(float value, float min, float max) {
  return (value >= min) && (value <= max);
}

bool Box::isIntersect(Box& obj) { // пересечение хитбоксов
  bool xOverlap = isOverlap(x, obj.x, obj.x + obj.width) || isOverlap(obj.x, x, x + width);
  bool yOverlap = isOverlap(y, obj.y, obj.y + obj.height) || isOverlap(obj.y, y, y + height);
  return xOverlap && yOverlap;
}