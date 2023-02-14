#pragma once
#include "Enemy.h"

extern float GlobalAnimationSpeed;

extern float GlobalSpeed;
 
Player::Player() : plHitBox(), speed(), LivingEntity(), Db(50, -10, 115, 50, -60, 0, Diraction::right) {}

void Player::SetNewState(State newState) {
  if (currentState != newState) {
    oldState = currentState;
    currentState = newState;
  }
  if (GetCurrDir() == Diraction::left || ((GetCurrDir() == Diraction::up || GetCurrDir() == Diraction::down) && GetOldDir() == Diraction::left)) { SetNewTileSetLeft(); }
  else if (GetCurrDir() == Diraction::right || ((GetCurrDir() == Diraction::up || GetCurrDir() == Diraction::down) && GetOldDir() == Diraction::right)) { SetNewTileSetRight(); }
}

HitBox Player::GetHB() const { return plHitBox; }

void Player::Revival() {
  isAlive = true;
  health = 100;
  oldDiraction = Diraction::left;
  currentDiraction = Diraction::right;
  SetNewState(State::standing);
  spriteAnim.SetFirstImg(sprite);
  Pos = Coord(100, 600);
  UpdateSpritePos();
  potionBar.SetCnt(2);
  questPotionBar.SetCnt(1);
}

void Player::Attack(Wolf wolves[AMOUNTWOLVES]) {
  for (size_t i = 0; i < AMOUNTWOLVES; i++)
  {
    if (Interract(wolves[i].GetHitBox())) {
      wolves[i].MinusHealth(GetDamageVal());
    }
  }
}

void Player::Attack(Skeleton skeleton[AMOUNTSKELKETONES]) {
  for (size_t i = 0; i < AMOUNTSKELKETONES; i++) {
    if (Interract(skeleton[i].GetHitBox())) {
      skeleton[i].MinusHealth(GetDamageVal());
    }
  }
}

void Player::Attack(Slime slime[AMOUNTSLIME]) {
  for (size_t i = 0; i < AMOUNTSLIME; i++) {
    if (Interract(slime[i].GetHitBox())) {
      slime[i].MinusHealth(GetDamageVal());
    }
  }
}

void Player::Move(Diraction newDirection, State newState, RenderWindow& window, Map& map, float CurrTime) { //сдвиг
  if ((newDirection != currentDiraction && (!(newDirection == Diraction::up && currentDiraction == Diraction::down) && !(newDirection == Diraction::down && currentDiraction == Diraction::up)))
    || ((newDirection == Diraction::up || newDirection == Diraction::down) && (currentDiraction == Diraction::left || currentDiraction == Diraction::right))) {
    oldDiraction = currentDiraction;
  }

  SetNewState(newState);
  Diraction lastDir = currentDiraction;
  currentDiraction = newDirection;
  Db.UpdateDiraction(currentDiraction);
  extern float GlobalSpeed;
  switch (currentDiraction) {
  case Diraction::right:
    if (currentState == walking) { Pos.x += speed * GlobalSpeed; }
    if (oldDiraction != currentDiraction) { SetNewTileSetRight(); }
    break;
  case Diraction::left:
    if (currentState == walking) { Pos.x -= speed * GlobalSpeed; }
    if (oldDiraction != currentDiraction) { SetNewTileSetLeft(); }
    break;
  case Diraction::up:
    if (currentState == walking) { Pos.y -= speed * GlobalSpeed; }
    if (oldDiraction == Diraction::right && (lastDir != currentDiraction || oldState != currentState)) { SetNewTileSetRight(); }
    if (oldDiraction == Diraction::left && (lastDir != currentDiraction || oldState != currentState)) { SetNewTileSetLeft(); }
    break;
  case Diraction::down:
    if (currentState == walking) { Pos.y += speed * GlobalSpeed; }
    if (oldDiraction == Diraction::right && (lastDir != currentDiraction || oldState != currentState)) { SetNewTileSetRight(); }
    if (oldDiraction == Diraction::left && (lastDir != currentDiraction || oldState != currentState)) { SetNewTileSetLeft(); }
    break;
  }
  spriteAnim.SetNextFrame(sprite, CurrTime);
  Collision(map); // проверка на пересечение со стеной
}

void Player::Collision(Map& map) {
  for (size_t i = (Pos.y + plHitBox.y) / TILESIZE; i < (Pos.y + plHitBox.y + plHitBox.height) / TILESIZE; i++) {
    for (size_t j = (Pos.x + plHitBox.x) / TILESIZE; j < (Pos.x + plHitBox.x + plHitBox.width) / TILESIZE; j++) {

      if (map.CurrentMap[i][j] == 'O') {
        switch (currentDiraction) {
        case Diraction::right:
          Pos.x = j * TILESIZE - plHitBox.x - plHitBox.width;
          break;
        case Diraction::left:
          Pos.x = j * TILESIZE - plHitBox.x + TILESIZE;
          return;
          break;
        case Diraction::up:
          Pos.y = i * TILESIZE - plHitBox.y + TILESIZE;
          break;
        case Diraction::down:
          Pos.y = i * TILESIZE - plHitBox.height - plHitBox.y;
          break;
        }
      }
      else if (map.CurrentMap[i][j] == 'N') {
        enduranceBar.HealBar(100);
        map.SetNextMap();
        Pos = map.GetSpownPoint();
        return;
      }
      else if (map.CurrentMap[i][j] == 'P') {
        enduranceBar.HealBar(100);
        map.SetPreviousMap();
        Pos = map.GetSpownPoint();
        return;
      }
    }
  }
}

void Player::UpdateSpritePos() {
  sprite.setPosition(Pos.x, Pos.y);
  //plHitBox.box.setPosition(Pos.x + plHitBox.x, Pos.y + plHitBox.y);
  UpdateHealthBar();
}

Coord Player::GetPos()const { return Pos; }

Coord Player::GetHitBoxCenterPos() const { return Coord(Pos.x + plHitBox.x + (plHitBox.width / 2), Pos.y + plHitBox.y + (plHitBox.height / 2)); }

void Player::Draw(RenderWindow& window) { // прорисовка персонажа
  if (currentState == walking) { UpdateSpritePos(); }
  window.draw(HealthBar);
  window.draw(sprite);
  //window.draw(plHitBox.box); // прорисовка хитобокса ног // закомментируй если хочешшь убрать белвый квадратик
  //Db.Draw(window, Pos);
}

void Player::DrawHUD(RenderWindow& window) {
  potionBar.UpdatePotionBar(window);
  potionBar.Draw(window);
  questPotionBar.UpdatePotionBar(window);
  questPotionBar.Draw(window);
}

bool Player::Interract(Box obj) {
  Box temp(Pos.x + Db.x + Db.GetOffset(), Pos.y + Db.y, Db.height, Db.width);
  if (temp.isIntersect(obj)) {
    return true;
  }
  return false;
}

bool Player::Interract(HitBox& obj)
{
  Box temp(Pos.x + plHitBox.x, Pos.y + plHitBox.y, plHitBox.height, plHitBox.width);
  if (temp.isIntersect(obj)) return true;
  return false;
}

void Player::PickUpPotion(Potion& potion) {
  for (size_t i = 0; i < potion.GetCnt(); i++)
  {
    potionBar.AddPotion();
  }
  potion.SetCnt(0);
}

void Player::UsePotion() {
  if (potionBar.Use()) {
    health += potionBar.GetHealingPower();
    health = health > maxHealth ? maxHealth : health;
  }
}

int Player::getPotionCnt() const
{
  return potionBar.GetCnt();
}

void Player::ReduceEndurance(float val)
{
  if (!enduranceBar.ReduceByVal(val)) {
    MinusHealth(val/2);
    oldHealth = health;
  }
}

void Player::RestoreEndurance(float val)
{
  enduranceBar.HealBar(val);
}

void Player::DrawEnduranceBar(RenderWindow& window)
{
  enduranceBar.UpdateBar(Coord(Pos.x, Pos.y - 5));
  enduranceBar.Draw(window);
}

void Player::BuyQuestPotion()
{
  potionBar.ReducePotionCnt();
  questPotionBar.AddPotion();
}

int Player::getQuestPotionCnt() const
{
  return questPotionBar.GetCnt();
}

Player::~Player() {}

// ---------------------------------------------------------------------------------------------- // 

PlayerKnight::PlayerKnight() { Init(); }

void PlayerKnight::Init() {
  spriteAnim.Init(sprite, "Assets\\FullKnight.png", 1, PlStandingRight);
  currentDiraction = Diraction::right;
  oldDiraction = Diraction::left;
  currentState = standing;
  oldState = walking;
  health = 100;
  maxHealth = 100;
  oldHealth = health;
  Damage = 2;
  isAlive = true;
  isInvincible = false;
  speed = 3.5f;
  Pos = Coord(100, 600);
  plHitBox = HitBox(34, 60, 20, 20);
  sprite.setPosition(Pos.x, Pos.y);
  sprite.scale(0.7f, 0.7f);
  plHitBox.box.setFillColor(Color(1, 0, 0, 100));
  Db.box.setFillColor(Color(100, 0, 0, 100));
  potionBar.SetCnt(2);
}

void PlayerKnight::SetNewTileSetLeft() {
  switch (currentState) {
  case standing: spriteAnim.SetArrImg(1, PlStandingLeft); break;
  case walking: spriteAnim.SetArrImg(6, PlWalkingLeft); break;
  case blocking: spriteAnim.SetArrImg(1, PlBlockingLeft); break;
  case atacking: spriteAnim.SetArrImg(3, PlAtackingLeft); break;
  case dying: spriteAnim.SetArrImg(8, PlDyingLeft); break;
  case damaging: spriteAnim.SetArrImg(3, PlDamagingLeft); break;
  }
}

void PlayerKnight::SetNewTileSetRight() {
  switch (currentState) {
  case standing: spriteAnim.SetArrImg(1, PlStandingRight); break;
  case walking: spriteAnim.SetArrImg(6, PlWalkingRight); break;
  case blocking: spriteAnim.SetArrImg(1, PlBlockingRight); break;
  case atacking: spriteAnim.SetArrImg(3, PlAtackingRight); break;
  case dying: spriteAnim.SetArrImg(8, PlDyingRight); break;
  case damaging: spriteAnim.SetArrImg(3, PlDamagingRight); break;
  }
}

void PlayerKnight::Draw(RenderWindow & window) { // прорисовка персонажа
  UpdateSpritePos();
  window.draw(HealthBar);
  window.draw(sprite);
  //window.draw(plHitBox.box); // прорисовка хитобокса ног // закомментируй если хочешшь убрать белвый квадратик
  //Db.Draw(window, Pos);
}