#pragma once
#include "includes.h"
#include "Box.h"

class HitBox :public virtual Box
{
public:
  RectangleShape box; // эту переменную можно будет удалить, она чисто для того что бы видеть где будет столкнавение.
public:
  HitBox();
  HitBox(Coord offset, int width, int height);
  HitBox(float x, float y, float width, float height);
};

//новый класс который отвечает за интеракцию с какими либо объектами
class DamageBox :public virtual HitBox { 
  Diraction offset;
  float leftOffset;
  float rightOffset;
public:
  DamageBox(float x, float y, float width, float height);
  DamageBox(float x, float y, float width, float height, float leftOffset, float rightOffset, Diraction LeftOrRight);
  void Draw(RenderWindow& window, const Coord& plPos);
  float GetOffset();
  HitBox GetHitBox();
  void UpdateDiraction(Diraction dir);
};

