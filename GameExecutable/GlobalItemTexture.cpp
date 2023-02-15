#include "GlobalItemTexture.h"

GlobalItemTexture::GlobalItemTexture()
{
  texture.loadFromFile("Assets\\Items.png");
}

Texture& GlobalItemTexture::operator()() {
  return texture;
}