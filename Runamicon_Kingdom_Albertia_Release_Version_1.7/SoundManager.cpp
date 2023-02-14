#include "SoundManager.h"

SoundManager::SoundManager()
{
  theme1.openFromFile("Assets\\theme_foret.wav");
  theme2.openFromFile("Assets\\theme_ruine.wav");
  theme3.openFromFile("Assets\\mystery.wav");
  theme4.openFromFile("Assets\\EndingMusic.wav");
  theme1.setLoop(true);
  theme2.setLoop(true);
  theme3.setLoop(true);
  screamSB.loadFromFile("Assets\\scream 21.wav");
  scream.setBuffer(screamSB); 
  oofSB1.loadFromFile("Assets\\oof 22.wav");
  oof1.setBuffer(oofSB1);
  oofSB2.loadFromFile("Assets\\oof 20.wav");
  oof2.setBuffer(oofSB2);
  oofSB3.loadFromFile("Assets\\oof 11.wav");
  oof3.setBuffer(oofSB3);
  metalSB.loadFromFile("Assets\\metal hits metal 11.wav");
  metal.setBuffer(metalSB);
  swordSB.loadFromFile("Assets\\sfx_sword.wav");
  sword.setBuffer(swordSB);
}

void SoundManager::StopAllSounds()
{
  if (theme1.getStatus() == SoundSource::Playing) theme1.stop();
  if (theme2.getStatus() == SoundSource::Playing) theme2.stop();
  if (theme3.getStatus() == SoundSource::Playing) theme3.stop();
  if (theme4.getStatus() == SoundSource::Playing) theme4.stop();
}

bool SoundManager::CheckIfOOFPlayed()
{
  if (oof1.getStatus() == SoundSource::Playing) return true;
  else if (oof2.getStatus() == SoundSource::Playing)return true;
  else if (oof3.getStatus() == SoundSource::Playing)return true;
  return false;
}

void SoundManager::PlayRandomOOF()
{
  switch (rand()%3)
  {
  case 0: oof1.play(); break;
  case 1: oof2.play(); break;
  case 2: oof3.play(); break;
  default:
    break;
  }
}

