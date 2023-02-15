#include "HitBox.h"

HitBox::HitBox() : Box(28, 60, 60, 60) {
  box.setSize(Vector2f(width, height));
}

HitBox::HitBox(Coord offset, int width, int height) : Box(offset.x, offset.y, width, height) {
  box.setSize(Vector2f(width, height));
  SetCoord(offset);
}

HitBox::HitBox(float x, float y, float width, float height) : Box(x, y, width, height) {
  box.setSize(Vector2f(height, width));
  SetCoord(Coord(x, y));
}

// ----------------------------------------------------------------------------------------------//

DamageBox::DamageBox(float x, float y, float width, float height) :HitBox(x, y, width, height), offset(Diraction::right), leftOffset(), rightOffset() {
  Box::height = width;
  Box::width = height;
}

DamageBox::DamageBox(float x, float y, float width, float height, float leftOffset, float rightOffset, Diraction LeftOrRight) :
  HitBox(x, y, width, height), offset(LeftOrRight), leftOffset(leftOffset), rightOffset(rightOffset) {
  Box::height = width;
  Box::width = height;
}

void DamageBox::Draw(RenderWindow& window, const Coord& plPos) {
  box.setPosition(plPos.x + x + GetOffset(), plPos.y + y);
  window.draw(box);
}

float DamageBox::GetOffset() {
  switch (offset)
  {
  default:
  case Diraction::right:
    return rightOffset;
    break;
  case Diraction::left:
    return leftOffset;
    break;
  }
}

void DamageBox::UpdateDiraction(Diraction dir) {
  if (dir == offset)return;
  switch (dir) {
  case Diraction::left: offset = Diraction::left; break;
  case Diraction::right: offset = Diraction::right; break;
  default: break;
  }
}