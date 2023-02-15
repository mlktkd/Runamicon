#include "GlobalTextures.h"

GlobalTextures::GlobalTextures(int num)
{
  Init(num);
}

void GlobalTextures::Init(int num)
{
  switch (num) {
  default:
  case 0://wolf
    texture.loadFromFile("Assets\\wolf_sprites.png");
    break;
  case 1://Skeleton
    texture.loadFromFile("Assets\\Skeleton_Tileset.png");
    break;
  case 2:
    texture.loadFromFile("Assets\\slime-Sheet.png");
    break;
  }
}

Texture& GlobalTextures::operator()() {
  return texture;
}