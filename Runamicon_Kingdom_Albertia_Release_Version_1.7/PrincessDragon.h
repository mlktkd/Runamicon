#pragma once
#include "Entity.h"
#include "HitBox.h"
#include "Diolog.h"
#include "SoundManager.h"

class PrincessDragon : public virtual Entity
{
  PDDIolog diolog;
  HitBox HB;
public:
  PrincessDragon();

  void Init();

  void StartEndDiolog(RenderWindow&window);

  Box& GetHitBox();

  void Draw(RenderWindow& window);

};

