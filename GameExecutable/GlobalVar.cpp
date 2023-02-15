#pragma once
#include "GlobalItemTexture.h"
#include "GlobalFont.h"
#include "GlobalTextures.h"
#include "SoundManager.h"

GlobalFont::GlobalFont() {
  font.loadFromFile("Assets\\pixel_pirate.ttf");
}

Font&  GlobalFont::operator()() {
  return font;
}

struct LC { LC() { srand(time(NULL)); } }_;

GlobalFont globalFont;

float GlobalAnimationSpeed = 0.08f;

float GlobalSpeed = 0.5f;

GlobalItemTexture globalItemTexture;

GlobalTextures Twolf(0);

GlobalTextures Tskeleton(1);

GlobalTextures Tslime(2);

bool isGameOver = false;

bool isGainedAdditionalQuestPotion = false;

int playerPotionCount;

SoundManager GlobalMusic;