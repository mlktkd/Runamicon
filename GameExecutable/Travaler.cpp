#include "Travaler.h"

Travaler::Travaler() :HB(0, 0, 120 * 0.8f, 120 * 0.8f) {
  Init();
}

void Travaler::Init()
{
  spriteAnim.Init(sprite, "Assets\\travaler.png", 1, new Frames{ Coord(0,0),120,120 });
  Pos.x = 1632;
  Pos.y = 2560;
  HB.box.setFillColor(Color(0, 70, 0, 100));
  sprite.setPosition(Pos.x, Pos.y);
  sprite.scale(0.8, 0.8);
  HB.box.setPosition(Pos.x + HB.x, Pos.y + HB.y);
  ForDiolog.loadFromFile("Assets\\TravalerFace.png");
  Face.setTexture(ForDiolog);
  Face.scale(0.1, 0.1);
  TDiolog.Init();
}

void Travaler::Draw(RenderWindow& window) {
  //window.draw(HB.box);
  window.draw(sprite);
  if (TDiolog.GetIsDiologActive()) {
    TDiolog.Draw(window);
    Vector2f temp(window.getView().getCenter());
    temp.x += 100;
    temp.y -= 140;
    Face.setPosition(temp);
    window.draw(Face);
  }
}

Box Travaler::GetHitBox()
{
  Box temp(HB.x + Pos.x, HB.y + Pos.y, HB.height, HB.width);
  return temp;
}

void Travaler::StartDiolog() {
  if (TDiolog.GetIsCanTalk()) {
    TDiolog.newDiolog();
    TDiolog.SetIsDiologAcitve(true);
  }
}

bool Travaler::GetTrigger() const
{
  return TDiolog.GetTrigger();
}

void Travaler::SetTrigger(bool val)
{
  TDiolog.SetTrigger(val);
}