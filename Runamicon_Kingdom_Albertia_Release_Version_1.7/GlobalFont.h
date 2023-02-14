#pragma once
#include "includes.h"

class GlobalFont {
  Font font;
public:
  GlobalFont();
  Font& operator()();
};