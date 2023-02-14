#include <sstream>
#include "Potion.h"
#include "GlobalFont.h"

extern GlobalItemTexture globalItemTexture;
extern GlobalFont globalFont;

Potion::Potion():cnt(1), healthRegen(50) {
  text.setFont(globalFont());
  stringstream temp;
  temp << cnt;
  text.setString(temp.str());
  text.scale(0.3, 0.3);
  text.setPosition(Pos.x + 10, Pos.y + 10);
  sprite.setTexture(globalItemTexture());
  sprite.setTextureRect(IntRect(128,288,32,32));
  isInvincible = true;
  isAlive = true;
}

Potion::Potion(Coord pos) :Potion() {
  Pos = pos;
  sprite.setPosition(pos.x, pos.y);
  sprite.scale(0.7, 0.7);
  text.setPosition(pos.x + 15, pos.y + 15);
}

void Potion::Draw(RenderWindow& window)
{ 
  window.draw(sprite);
  window.draw(text);
}

void Potion::UpdatePotionBar(RenderWindow& window) {
  Vector2f temp = window.getView().getCenter();
  temp.x -= window.getView().getSize().x / 2;
  temp.y += (window.getView().getSize().y / 2)-60;
  sprite.setPosition(temp);
  text.setPosition(temp.x + 30, temp.y);
}

Box Potion::GetHitBox()
{
  return Box(Pos.x, Pos.y, 32, 32);
}

float Potion::GetHealingPower() const
{
  return healthRegen;
}

int Potion::GetCnt() const{return cnt;}

Potion::~Potion(){}

void Potion::AddPotion() {
  cnt++;
  stringstream temp;
  temp << cnt;
  text.setString(temp.str());
}

void Potion::ReducePotionCnt()
{
  if (cnt) {
    cnt--;
  }
  stringstream temp;
  temp << cnt;
  text.setString(temp.str());
}

bool Potion::Use()
{
  if (!cnt)return false;
  cnt--;
  stringstream temp;
  temp << cnt;
  text.setString(temp.str());
  return true;
}

void Potion::SetCnt(int val)
{
  cnt = val;
  stringstream temp;
  temp << cnt;
  text.setString(temp.str());
}

QuestPotion::QuestPotion()
{
  sprite.setTexture(globalItemTexture());
  sprite.setTextureRect(IntRect(352, 288, 32, 32));
  isInvincible = true;
  isAlive = true;
}

void QuestPotion::UpdatePotionBar(RenderWindow& window)
{
  Vector2f temp = window.getView().getCenter();
  temp.x -= (window.getView().getSize().x / 2) - 40;
  temp.y += (window.getView().getSize().y / 2) - 60;
  sprite.setPosition(temp);
  text.setPosition(temp.x + 30, temp.y);
}