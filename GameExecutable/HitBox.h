#pragma once
#include "includes.h"
#include "Box.h"

class HitBox :public virtual Box
{
public:
  RectangleShape box; // ��� ���������� ����� ����� �������, ��� ����� ��� ���� ��� �� ������ ��� ����� ������������.
public:
  HitBox();
  HitBox(Coord offset, int width, int height);
  HitBox(float x, float y, float width, float height);
};

//����� ����� ������� �������� �� ���������� � ������ ���� ���������
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

