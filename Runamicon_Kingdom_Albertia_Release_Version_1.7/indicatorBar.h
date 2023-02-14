#pragma once
#include "includes.h"
#include "Coord.h"
#include "GlobalItemTexture.h"

class indicatorBar
{
  Sprite sprite;
  float maxUnit;
  float currentUnit;
  RectangleShape bar;
public :
  indicatorBar();

  bool ReduceByVal(float val);
  
  void HealBar(float val);

  void Draw(RenderWindow& window);

  void UpdateBar(Coord pos);
};

