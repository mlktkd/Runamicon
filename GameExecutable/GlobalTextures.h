#pragma once
#include "includes.h"

class GlobalTextures
{
  Texture texture;
public:
  GlobalTextures(int num);

  void Init(int num);

  Texture& operator()();
};

