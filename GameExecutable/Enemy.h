#pragma once
#include <string>
#include "includes.h"
#include "Player.h"
#include "GlobalTextures.h"

using namespace sf;

// Runamicon : Kingdom Albertia

class Enemy :public virtual LivingEntity {
protected:
  HitBox enmFeetBox;
  HitBox enmHitBox;
  float speed;
  int radiusFOV;
  Diraction dir; // для коллизии
public:
  Enemy();

  virtual void Init() = 0;

  virtual void SetNewTileSetRight() = 0;

  virtual void SetNewTileSetLeft() = 0;

  virtual void Revival(Coord pos) = 0;

  virtual void SetPos(Coord pos);

  virtual void SetState(State state, float CurrTime);

  virtual State GetCurrState() const;

  virtual bool isPlInFieldOfView(Player& pl);

  virtual void Move(Player& pl, Map& map, float CurrTime);

  virtual void Atack(Player& pl);

  virtual void Collision(Map& map);

  virtual void UpdateSpritePos();

  virtual Coord GetPos()const;

  virtual Coord GetHitBoxCenterPos() const;

  virtual void Draw(RenderWindow& window);

  virtual Box GetHitBox()const;

  virtual ~Enemy();
};


class Wolf :public virtual Enemy {
protected:
public:
  Wolf();
  
  virtual void Init();

  virtual void SetNewTileSetLeft();

  virtual void SetNewTileSetRight();

  virtual void Revival(Coord pos);
  
};

class Skeleton :public virtual Enemy {
protected:
public:
  Skeleton();

  virtual void Init();
  virtual void SetNewTileSetLeft();
  virtual void SetNewTileSetRight();
  virtual void UpdateSpritePos()override;
  virtual Box GetHitBox()const override;
  virtual void Revival(Coord pos);
};

class Slime :public virtual Enemy {
protected:
public:
  Slime();

  virtual void Init();
  virtual void SetNewTileSetLeft();
  virtual void SetNewTileSetRight();
  virtual void Revival(Coord pos);
};