#pragma once
#include "Coord.h"

// структурка которая пригодится для всех видов хитбоксов

struct Box :public virtual Coord
{
  // в случае если это хит бокс то координаты x,y будут сдвигом относительно координат объекта,
  //к примеру в классе игрок hitBox.x hitBox.y это сдвиг отнасительно координат спрайта
  float height, width;
  Box();
  Box(float x, float y, float height, float width);
  bool isOverlap(float value, float min, float max);
  bool isIntersect(Box& obj);
};