#include "Entity.h"

Entity::Entity() :Pos(), health(), isAlive(true), isInvincible(), sprite(), spriteAnim(), Damage(), maxHealth(), oldHealth() {}

Entity::Entity(Coord Pos, float health, float oldHealth ,  float Damage, string FileName, int AmountFrames, Frames * ArrImg, bool isAlive, bool isInvincible)
:Pos(Pos), health(health), oldHealth(oldHealth), Damage(Damage), spriteAnim(sprite, FileName, AmountFrames, ArrImg), isAlive(isAlive), isInvincible(isInvincible), maxHealth() {}

const ImageAnimation& Entity::GetSpriteAnim() const { return spriteAnim; }

void Entity::SetNextFrameEntity(float CurrTime) { spriteAnim.SetNextFrame(sprite, CurrTime); }

bool Entity::GetIsInvincible() const { return isInvincible; }

bool Entity::GetIsAlive() const { return isAlive; }

float Entity::GetDamageVal()const { return Damage; }

float Entity::GetHealth() const { return health; }

float Entity::GetMaxHealth() const { return maxHealth; }

float Entity::GetOldHealth() const { return oldHealth; }

void Entity::SetHealth(float newhealth) { health = newhealth; }

void Entity::SetOldHealth(float oldhealth) { oldHealth = oldhealth; }

void Entity::SetAnimationSpeed(float val){ spriteAnim.animationspeed = val;}

inline Entity::~Entity() {}

//-----------------------------------------------------------------------------------//

LivingEntity::LivingEntity() : Entity(), currentDiraction(), oldDiraction(), currentState(), oldState(), HealthBar() {}

LivingEntity::LivingEntity(Diraction currentDiraction, Diraction oldDiraction, State currentState, State oldState, Coord Pos, float health, float oldHealth, float Damage, string FileName, int AmountFrames, Frames* ArrImg, bool isAlive, bool isInvincible)
:Entity(Pos, health,oldHealth, Damage, FileName, AmountFrames, ArrImg, isAlive, isInvincible), currentDiraction(currentDiraction), oldDiraction(oldDiraction), currentState(currentState), oldState(oldState) { }

Diraction LivingEntity::GetOldDir() const { return oldDiraction; }

Diraction LivingEntity::GetCurrDir() const { return currentDiraction; }

State LivingEntity::GetCurrState() const { return currentState; }

State LivingEntity::GetOldState() const { return oldState; }

void LivingEntity::MinusHealth(float val) {
  health -= val;
  if (health <= 0 && isInvincible != true) { isAlive = false; }
}

void LivingEntity::UpdateHealthBar() {
  HealthBar.setPosition(Pos.x, Pos.y);
  HealthBar.setSize(Vector2f(health, 5));
  if (health > maxHealth - (maxHealth / 4)) HealthBar.setFillColor(Color::Green);
  else  if (health > maxHealth / 2 && health <= maxHealth - (maxHealth / 4)) HealthBar.setFillColor(Color::Yellow);
  else if (health > maxHealth / 4 && health <= maxHealth / 2) HealthBar.setFillColor(Color(190, 130, 0));
  else HealthBar.setFillColor(Color::Red);
}

void LivingEntity::UpdateHealthBar(Coord newPos) {
  HealthBar.setPosition(newPos.x, newPos.y);
  HealthBar.setSize(Vector2f(health, 5));
  if (health > maxHealth - (maxHealth / 4)) HealthBar.setFillColor(Color::Green);
  else  if (health > maxHealth / 2 && health <= maxHealth - (maxHealth / 4)) HealthBar.setFillColor(Color::Yellow);
  else if (health > maxHealth / 4 && health <= maxHealth / 2) HealthBar.setFillColor(Color(190, 130, 0));
  else HealthBar.setFillColor(Color::Red);
}

LivingEntity::~LivingEntity() {}