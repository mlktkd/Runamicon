#pragma once
#include "Coord.h"

// ���������� ������� ���������� ��� ���� ����� ���������

struct Box :public virtual Coord
{
  // � ������ ���� ��� ��� ���� �� ���������� x,y ����� ������� ������������ ��������� �������,
  //� ������� � ������ ����� hitBox.x hitBox.y ��� ����� ������������ ��������� �������
  float height, width;
  Box();
  Box(float x, float y, float height, float width);
  bool isOverlap(float value, float min, float max);
  bool isIntersect(Box& obj);
};