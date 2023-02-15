#pragma once
#include <SFML/Graphics.hpp>
#include "Coord.h"
#include "ImageAnimation.h"
using namespace sf;

enum Diraction;
enum State;

// тут пробные энтети

class Entity {
protected:
  Coord Pos;
  float health;
  float maxHealth;
  float oldHealth;
  bool isAlive;
  bool isInvincible;
  Sprite sprite;
  ImageAnimation spriteAnim;
  float Damage;
public:
  Entity();

  Entity(Coord Pos, float health, float oldHealth, float Damage, string FileName, int AmountFrames, Frames* ArrImg, bool isAlive = true, bool isInvincible = false);

  const ImageAnimation& GetSpriteAnim() const;

  virtual void SetNextFrameEntity(float CurrTime);

  bool GetIsInvincible() const;

  bool GetIsAlive() const;

  float GetOldHealth() const;

  float GetMaxHealth() const;

  float GetHealth() const;

  float GetDamageVal()const;

  virtual void SetHealth(float newhealth);

  virtual void SetOldHealth(float oldHealth);

  virtual void SetAnimationSpeed(float val);

  virtual ~Entity() = 0;
};

class LivingEntity :public virtual Entity {
protected:
  Diraction currentDiraction;
  Diraction oldDiraction;
  State currentState;
  State oldState;
  RectangleShape HealthBar;
public:
  LivingEntity();
  LivingEntity(Diraction currentDiraction, Diraction oldDiraction, State currentState, State oldState, Coord Pos,
    float health, float oldHealth, float Damage, string FileName, int AmountFrames, Frames* ArrImg, bool isAlive = true, bool isInvincible = false);

  Diraction GetOldDir() const;

  Diraction GetCurrDir() const;

  State GetCurrState() const;

  State GetOldState() const;

  void UpdateHealthBar();

  void UpdateHealthBar(Coord newPos);

  virtual void MinusHealth(float val);

  virtual ~LivingEntity();
};