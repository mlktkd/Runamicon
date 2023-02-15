#include "PrincessDragon.h"

extern bool isGameOver;

PrincessDragon::PrincessDragon():HB(-50,-50,500,500)
{
  Init();
}

void PrincessDragon::Init()
{
  Pos = Coord(100, 2600);
  HB.box.setPosition(Pos.x + HB.x, Pos.y + HB.y);
  HB.box.setFillColor(Color(1, 0, 0, 100));
  spriteAnim.Init(sprite, "Assets\\DragonPrincessSprite.png", 1, new Frames[1]{ {Coord(0,0), 144,255} });
  sprite.scale(2, 2);
  sprite.setPosition(Pos.x, Pos.y);
}

Box& PrincessDragon::GetHitBox()
{
  Box temp(Pos.x+HB.x, Pos.y + HB.y, HB.height, HB.width);
  return temp;
}

void PrincessDragon::Draw(RenderWindow& window)
{
  //\window.draw(HB.box);
  window.draw(sprite);
}

extern SoundManager GlobalMusic;

void PrincessDragon::StartEndDiolog(RenderWindow& window)
{
  GlobalMusic.StopAllSounds();
  GlobalMusic.theme4.play();
  Vector2f pos = window.getView().getCenter();
  pos.x -= window.getView().getSize().x / 2;
  pos.y -= window.getView().getSize().y / 2;
  diolog.PrepareDiolog();
  diolog.newDiolog();
  diolog.SetBackGroundPos(pos);
  diolog.SetIsDiologAcitve(true);
  while (diolog.GetIsDiologActive()) {
    diolog.Draw(window);
    diolog.startDiolog(window);
    window.display();
    window.clear();
  }
  diolog.PrintEnd(window);
  isGameOver = true;
}