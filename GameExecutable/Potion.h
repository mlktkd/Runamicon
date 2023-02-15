#pragma once
#include "Entity.h"
#include "GlobalItemTexture.h"

class Potion : public virtual Entity
{
protected:
  Text text;
  float healthRegen;
  int cnt;
public:
  Potion();

  Potion(Coord pos);

  void Draw(RenderWindow&window);

  void AddPotion();

  void ReducePotionCnt();

  bool Use();

  void SetCnt(int val);

  virtual void UpdatePotionBar(RenderWindow&window);

  Box GetHitBox();

  float GetHealingPower()const;

  int GetCnt()const;

  ~Potion();
};

class QuestPotion : public virtual Potion {
public:
  QuestPotion();

  void UpdatePotionBar(RenderWindow& window)override;
};