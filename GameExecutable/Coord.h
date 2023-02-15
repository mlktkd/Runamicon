#pragma once

struct Coord
{
  float x, y;
  Coord();
  Coord(float x, float y);
  bool operator == (const Coord& obj);
  void SetCoord(const Coord obj);
};