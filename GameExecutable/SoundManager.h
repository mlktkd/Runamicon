#pragma once
#include <SFML/Audio.hpp>
#include "includes.h"

class SoundManager
{
  SoundBuffer screamSB;
  SoundBuffer oofSB1;
  SoundBuffer oofSB2;
  SoundBuffer oofSB3;
  SoundBuffer metalSB;
  SoundBuffer swordSB;
public:
  Music theme1;
  Music theme2;
  Music theme3;
  Music theme4;
  Sound scream;
  Sound oof1;
  Sound oof2;
  Sound oof3;
  Sound metal;
  Sound sword;
  SoundManager();
  void StopAllSounds();
  bool CheckIfOOFPlayed();
  void PlayRandomOOF();
  
};

