#pragma once
#include "includes.h"

class GlobalItemTexture
{
  Texture texture;
public:
  GlobalItemTexture();

  Texture& operator()();
};

