#pragma once
#include "Entity.h"
#include "HitBox.h"
#include "Diolog.h"


class Travaler :public virtual Entity
{
  HitBox HB;
  Texture ForDiolog;
  Sprite Face;
public:
  Diolog TDiolog;

  Travaler();

  void Init();

  void Draw(RenderWindow& window);

  Box GetHitBox();

  void StartDiolog();

  bool GetTrigger()const;

  void SetTrigger(bool val);
};