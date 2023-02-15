#include "Enemy.h"

extern GlobalTextures Twolf;
extern GlobalTextures Tskeleton;
extern GlobalTextures Tslime;

Enemy::Enemy() : enmFeetBox(), speed(), radiusFOV(), LivingEntity(), dir(Diraction::right), enmHitBox() {}

void Enemy::SetPos(Coord pos) {
  Pos = pos;
  sprite.setPosition(Pos.x, Pos.y);
}

void Enemy::SetState(State state, float CurrTime) {
  oldState = currentState;
  currentState = state;
  if (GetCurrDir() == Diraction::left) { SetNewTileSetLeft(); }
  else if (GetCurrDir() == Diraction::right) { SetNewTileSetRight(); }
  if (currentState == State::standing) { spriteAnim.SetNextFrame(sprite, CurrTime); }
}

State Enemy::GetCurrState() const { return currentState; }

bool Enemy::isPlInFieldOfView(Player& pl) {  //находит центр хитбокса
  return int(sqrt(((pl.GetPos().x - this->Pos.x) * (pl.GetPos().x - this->Pos.x)) + ((pl.GetPos().y - this->Pos.y) * (pl.GetPos().y - this->Pos.y)))) <= radiusFOV;
}

void Enemy::Move(Player& pl, Map& map, float CurrTime) { //сдвиг
  int diff_x, diff_y;
  Coord oldPos = Pos;
  if (pl.GetHitBoxCenterPos().x > this->GetHitBoxCenterPos().x) { diff_x = pl.GetHitBoxCenterPos().x - this->GetHitBoxCenterPos().x; oldDiraction = currentDiraction; currentDiraction = Diraction::right; }
  else if (pl.GetHitBoxCenterPos().x < this->GetHitBoxCenterPos().x) { diff_x = this->GetHitBoxCenterPos().x - pl.GetHitBoxCenterPos().x; oldDiraction = currentDiraction; currentDiraction = Diraction::left; }
  else { diff_x = 0; }
  if (pl.GetHitBoxCenterPos().y > this->GetHitBoxCenterPos().y) { diff_y = pl.GetHitBoxCenterPos().y - this->GetHitBoxCenterPos().y; }
  else if (pl.GetHitBoxCenterPos().y < this->GetHitBoxCenterPos().y) { diff_y = this->GetHitBoxCenterPos().y - pl.GetHitBoxCenterPos().y; }
  else { diff_y = 0; }
  extern float GlobalSpeed;

  if (currentState == State::damaging && spriteAnim.GetCurrFrameNum() <= spriteAnim.GetAmountFrames() - 1) {
    if (spriteAnim.GetCurrFrameNum() == spriteAnim.GetAmountFrames() - 1) {
      SetState(State::standing, CurrTime);
    }
  }
  else {
    if (oldHealth > health) {
      SetState(State::damaging, CurrTime);
      oldHealth = health;
    }
    else
      if ((diff_x <= TILESIZE * 2 && diff_y <= TILESIZE * 2)) {
        if (pl.GetHitBoxCenterPos().y > this->GetHitBoxCenterPos().y) {
          Pos.y += speed * GlobalSpeed;
          dir = down;
        }
        if (pl.GetHitBoxCenterPos().y < this->GetHitBoxCenterPos().y) {
          Pos.y -= speed * GlobalSpeed;
          dir = up;
        }
        if (diff_x <= TILESIZE * 2 && diff_y <= 5) {
          SetState(State::atacking, CurrTime);
          if (spriteAnim.GetCurrFrameNum() == spriteAnim.GetAmountFrames() - 1) {
            Atack(pl);
          }
        }
      }
      else if (diff_x > diff_y) {
        if (pl.GetHitBoxCenterPos().x > this->GetHitBoxCenterPos().x) {
          Pos.x += speed * GlobalSpeed;
          dir = Diraction::right;
          if (oldDiraction != currentDiraction) { SetNewTileSetRight(); }
        }
        if (pl.GetHitBoxCenterPos().x < this->GetHitBoxCenterPos().x) {
          Pos.x -= speed * GlobalSpeed;
          dir = Diraction::left;
          if (oldDiraction != currentDiraction) { SetNewTileSetLeft(); }
        }
      }
      else {
        if (pl.GetHitBoxCenterPos().y > this->GetHitBoxCenterPos().y) {
          Pos.y += speed * GlobalSpeed;
          dir = Diraction::down;
        }
        if (pl.GetHitBoxCenterPos().y < this->GetHitBoxCenterPos().y) {
          Pos.y -= speed * GlobalSpeed;
          dir = Diraction::up;
        }
      }
  }
  spriteAnim.SetNextFrame(sprite, CurrTime);
  Collision(map); // проверка на пересечение со стеной
}

void Enemy::Atack(Player& pl) {
  if (this->currentState == State::atacking &&
    !(pl.GetCurrState() == State::blocking &&   //проверка на направление блока игрока
      ((pl.GetCurrDir() == Diraction::left && this->GetCurrDir() == Diraction::right) || (pl.GetCurrDir() == Diraction::right && this->GetCurrDir() == Diraction::left)
        || ((pl.GetCurrDir() == Diraction::up || pl.GetCurrDir() == Diraction::down) && pl.GetOldDir() == Diraction::left && this->GetCurrDir() == Diraction::right)
        || ((pl.GetCurrDir() == Diraction::up || pl.GetCurrDir() == Diraction::down) && pl.GetOldDir() == Diraction::right && this->GetCurrDir() == Diraction::left)))) {
    pl.MinusHealth(this->Damage);
    pl.SetNewState(State::damaging);
  }
}

void Enemy::Collision(Map& map) {
  for (size_t i = (Pos.y + enmFeetBox.y) / TILESIZE; i < (Pos.y + enmFeetBox.y + enmFeetBox.height) / TILESIZE; i++) {
    for (size_t j = (Pos.x + enmFeetBox.x) / TILESIZE; j < (Pos.x + enmFeetBox.x + enmFeetBox.width) / TILESIZE; j++) {

      if (map.CurrentMap[i][j] == 'O') {
        switch (dir) {
        case Diraction::right:
          Pos.x = j * TILESIZE - enmFeetBox.x - enmFeetBox.width;
          break;
        case Diraction::left:
          Pos.x = j * TILESIZE - enmFeetBox.x + TILESIZE;
          return;
          break;
        case Diraction::up:
          Pos.y = i * TILESIZE - enmFeetBox.y + TILESIZE;
          break;
        case Diraction::down:
          Pos.y = i * TILESIZE - enmFeetBox.height - enmFeetBox.y;
          break;
        }
      }
    }
  }
}

void Enemy::UpdateSpritePos() {
  sprite.setPosition(Pos.x, Pos.y);
  UpdateHealthBar();
  //enmFeetBox.box.setPosition(Pos.x + enmFeetBox.x, Pos.y + enmFeetBox.y);
  //enmHitBox.box.setPosition(Pos.x + enmHitBox.x, Pos.y + enmHitBox.y);
}

Coord Enemy::GetPos()const { return Pos; }

Coord Enemy::GetHitBoxCenterPos() const { return Coord(Pos.x + enmFeetBox.x + (enmFeetBox.width / 2), Pos.y + enmFeetBox.y + (enmFeetBox.height / 2)); }

void Enemy::Draw(RenderWindow& window) { // прорисовка персонажа
  //if (currentState == walking) { 
  UpdateSpritePos();
  // }
  if (isAlive) window.draw(HealthBar);
  window.draw(sprite);
  //window.draw(enmFeetBox.box); // прорисовка хитобокса ног // закомментируй если хочешшь убрать белвый квадратик
  //window.draw(enmHitBox.box);
}

Box Enemy::GetHitBox()const {
  Box temp(enmHitBox.x + Pos.x, enmHitBox.y + Pos.y, enmHitBox.height, enmHitBox.width);
  return temp;
}

Enemy::~Enemy() {}

// ------------------------------------------------------------------------------------------------------------------------------//

Wolf::Wolf() { Init(); }

void Wolf::Init() {
  spriteAnim.Init(sprite, Twolf, 1, WolfStandingLeft);
  currentDiraction = Diraction::left;
  oldDiraction = Diraction::right;
  currentState = standing;
  oldState = walking;
  health = 50;
  maxHealth = 50;
  oldHealth = health;
  Damage = 1;
  speed = 7;
  isAlive = true;
  isInvincible = false;
  radiusFOV = 400;
  Pos = Coord(300, 600);
  enmFeetBox = HitBox(20, 27, 10, 45);
  sprite.setPosition(Pos.x, Pos.y);
  sprite.scale(0.7f, 0.7f);
  enmFeetBox.box.setFillColor(Color(1, 0, 0, 100));
  enmHitBox = HitBox(0, 0, 40, 70);
  enmHitBox.box.setFillColor(Color(0, 100, 0, 100));
  SetAnimationSpeed(0.6f);
}

void Wolf::SetNewTileSetLeft() {
  switch (currentState) {
  case standing: spriteAnim.SetArrImg(1, WolfStandingLeft); break;
  case walking: spriteAnim.SetArrImg(6, WolfWalkingLeft); break;
  case atacking: spriteAnim.SetArrImg(3, WolfAtackingLeft); break;
  case dying: spriteAnim.SetArrImg(7, WolfDyingLeft); break;
  case damaging: spriteAnim.SetArrImg(3, WolfDamagingLeft); break;
  }
}

void Wolf::SetNewTileSetRight() {
  switch (currentState) {
  case standing: spriteAnim.SetArrImg(1, WolfStandingRight); break;
  case walking: spriteAnim.SetArrImg(6, WolfWalkingRight); break;
  case atacking: spriteAnim.SetArrImg(3, WolfAtackingRight); break;
  case dying: spriteAnim.SetArrImg(7, WolfDyingRight); break;
  case damaging: spriteAnim.SetArrImg(3, WolfDamagingRight); break;
  }
}

void Wolf::Revival(Coord pos) {
  isAlive = true;
  health = 50;
  oldHealth = health;
  oldDiraction = Diraction::left;
  currentDiraction = Diraction::right;
  currentState = State::standing;
  spriteAnim.SetFirstImg(sprite);
  SetNewTileSetRight();
  Pos = pos;
  UpdateSpritePos();
}


Skeleton::Skeleton() { Init(); }

void Skeleton::Init() {
  spriteAnim.Init(sprite, Tskeleton, 2, SkeletonStandingLeft);
  currentDiraction = Diraction::left;
  oldDiraction = Diraction::right;
  currentState = standing;
  oldState = walking;
  health = 80;
  maxHealth = 80;
  oldHealth = health;
  Damage = 1.3f;
  speed = RAND(2, 3);
  isAlive = true;
  isInvincible = false;
  radiusFOV = 300;
  Pos = Coord(300, 600); ///////////////////////////////
  enmFeetBox = HitBox(35, 61, 20, 50);
  enmHitBox = HitBox(0, 0, 80, 40); ///////////////////////////////
  sprite.setPosition(Pos.x, Pos.y);
  sprite.scale(1.3f, 1.3f);
  enmHitBox.box.setFillColor(Color(0, 100, 0, 100));
  enmFeetBox.box.setFillColor(Color(1, 0, 0, 100));
}

void Skeleton::SetNewTileSetLeft() {
  switch (currentState) {
  case standing: spriteAnim.SetArrImg(2, SkeletonStandingLeft); break;
  case walking: spriteAnim.SetArrImg(4, SkeletonWalkingLeft); break;
  case atacking: spriteAnim.SetArrImg(7, SkeletonAtackingLeft); break;
  case dying: spriteAnim.SetArrImg(4, SkeletonDyingLeft); break;
  case damaging: spriteAnim.SetArrImg(3, SkeletonDamagingLeft); break;
  }
}

void Skeleton::SetNewTileSetRight() {
  switch (currentState) {
  case standing: spriteAnim.SetArrImg(2, SkeletonStandingRight); break;
  case walking: spriteAnim.SetArrImg(4, SkeletonWalkingRight); break;
  case atacking: spriteAnim.SetArrImg(7, SkeletonAtackingRight); break;
  case dying: spriteAnim.SetArrImg(4, SkeletonDyingRight); break;
  case damaging: spriteAnim.SetArrImg(3, SkeletonDamagingRight); break;
  }
}

void Skeleton::UpdateSpritePos() {
  sprite.setPosition(Pos.x, Pos.y);
  UpdateHealthBar(Coord(Pos.x + 25, Pos.y - 20));
  //enmFeetBox.box.setPosition(Pos.x + enmFeetBox.x, Pos.y + enmFeetBox.y);
  //enmHitBox.box.setPosition(Pos.x + enmHitBox.x + (currentDiraction == Diraction::left ? 50: 0), Pos.y + enmHitBox.y);
}

Box Skeleton::GetHitBox()const {
  Box temp(enmHitBox.x + Pos.x + (currentDiraction == Diraction::left ? 50 : 0), enmHitBox.y + Pos.y, enmHitBox.height, enmHitBox.width);
  return temp;
}

void Skeleton::Revival(Coord pos) {
  isAlive = true;
  health = 80;
  oldHealth = health;
  oldDiraction = Diraction::left;
  currentDiraction = Diraction::right;
  currentState = State::standing;
  spriteAnim.SetFirstImg(sprite);
  SetNewTileSetRight();
  Pos = pos;
  UpdateSpritePos();
}

Slime::Slime() { Init(); }

void Slime::Init() {
  spriteAnim.Init(sprite, Tslime, 4, SlimeStandingRight);
  currentDiraction = Diraction::right;
  oldDiraction = Diraction::left;
  currentState = standing;
  oldState = walking;
  health = 70;
  maxHealth = 70;
  oldHealth = health;
  Damage = 1.8f;
  isAlive = true;
  isInvincible = false;
  speed = RAND(1, 4);
  radiusFOV = 150;
  Pos = Coord(100, 600);
  enmHitBox = HitBox(5, 5, 40, 40);
  enmFeetBox = HitBox(17, 21, 21, 31);
  sprite.setPosition(Pos.x, Pos.y);
  sprite.scale(1.8f, 1.8f);
  enmHitBox.box.setFillColor(Color(0, 100, 0, 100));
  enmFeetBox.box.setFillColor(Color(1, 0, 0, 100));
}

void Slime::SetNewTileSetLeft() {
  switch (currentState) {
  case standing: spriteAnim.SetArrImg(4, SlimeStandingLeft); break;
  case walking: spriteAnim.SetArrImg(4, SlimeWalkingLeft); break;
  case atacking: spriteAnim.SetArrImg(5, SlimeAtackingLeft); break;
  case dying: spriteAnim.SetArrImg(5, SlimeDyingLeft); break;
  case damaging: spriteAnim.SetArrImg(3, SlimeDamagingLeft); break;
  }
}

void Slime::SetNewTileSetRight() {
  switch (currentState) {
  case standing: spriteAnim.SetArrImg(4, SlimeStandingRight); break;
  case walking: spriteAnim.SetArrImg(4, SlimeWalkingRight); break;
  case atacking: spriteAnim.SetArrImg(5, SlimeAtackingRight); break;
  case dying: spriteAnim.SetArrImg(5, SlimeDyingRight); break;
  case damaging: spriteAnim.SetArrImg(3, SlimeDamagingRight); break;
  }
}

void Slime::Revival(Coord pos) {
  isAlive = true;
  health = 70;
  oldHealth = health;
  oldDiraction = Diraction::left;
  currentDiraction = Diraction::right;
  currentState = State::standing;
  spriteAnim.SetFirstImg(sprite);
  SetNewTileSetRight();
  Pos = pos;
  UpdateSpritePos();
}