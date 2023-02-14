#pragma once
#include "includes.h"
#include "menu.h"
#include "Enemy.h"
#include "Travaler.h"
#include "Potion.h"
#include "PrincessDragon.h"
#include "SoundManager.h"
#include "PreHistory.h"
#include "Credits.h"

class Game
{
  RenderWindow window; 
  Menu mainMenu;
  PreHistory history;
  Credits credits;
  Map map;
  PlayerKnight player;
  //PlayerFairy plFairy;
  Travaler travaler;
  Wolf wolves[AMOUNTWOLVES];
  Skeleton skeleton[AMOUNTSKELKETONES];
  Slime slime[AMOUNTSLIME];
  HitBox SafeZone[AMOUNTSAFEZONES];
  float CurrTime;
  PrincessDragon PD;
  list<Potion> potions;
  list<Potion> desertPotions;
public:
  Game();

  void Start();

  void StartGame();

  void SetCenter(View& view, float x, float y);

  void MoveEntities(); 

  void PickUpPotions(list<Potion>& LPotion);

  void DrawEntities();

  void UpdateGame();

  bool SafeZoneInteraction();

  void DrawGameOver();
};

