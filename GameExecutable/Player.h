#pragma once
#include "includes.h"
#include "HitBox.h"
#include "Potion.h"
#include "indicatorBar.h"

static class Wolf;
static class Skeleton;
static class Slime;

class Player :public virtual LivingEntity {
protected:
  HitBox plHitBox;
  int speed;
  DamageBox Db;
  Potion potionBar;
  QuestPotion questPotionBar;
  indicatorBar enduranceBar;
public:
  Player();

  virtual void Init() = 0;

  virtual void SetNewTileSetRight() = 0;

  virtual void SetNewTileSetLeft() = 0;
  
  virtual void SetNewState(State newState);

  virtual HitBox GetHB() const;

  virtual void Revival();

  virtual void Attack(Wolf wolves[AMOUNTWOLVES]);
  
  virtual void Attack(Skeleton skeleton[AMOUNTSKELKETONES]);
  
  virtual void Attack(Slime slime[AMOUNTSLIME]);

  virtual void Move(Diraction newDirection, State newState, RenderWindow& window, Map& map, float CurrTime);

  virtual void Collision(Map& map);

  virtual void UpdateSpritePos();

  virtual Coord GetPos()const;

  virtual void DrawHUD(RenderWindow&window);

  virtual Coord GetHitBoxCenterPos() const;

  virtual void Draw(RenderWindow& window);

  virtual void ReduceEndurance(float val);

  virtual void RestoreEndurance(float val);

  virtual void DrawEnduranceBar(RenderWindow& window);

  virtual void PickUpPotion(Potion& potion);

  virtual void UsePotion();

  virtual int getPotionCnt()const;

  virtual int getQuestPotionCnt()const;

  virtual void BuyQuestPotion();

  //метод взаимодействия по хитобоксам
  bool Interract(Box obj);

  bool Interract(HitBox& obj);

  virtual ~Player();
};

class PlayerKnight:public virtual Player
{
protected:
public:
  PlayerKnight();

  virtual void Init();

  virtual void SetNewTileSetLeft();

  virtual void SetNewTileSetRight();

  virtual void Draw(RenderWindow& window);
};

