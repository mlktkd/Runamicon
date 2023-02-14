#pragma once
#include "includes.h"
#include "Coord.h"
#include "GlobalFont.h"

using namespace sf;

class Menu
{
  Texture MenuTexture;
  Sprite MenuSprite;
  std::vector<Text> menu;
  Text gameName;
  Text shadowGameName;
  Coord PosMenu;
  Coord PosName;
  Color fillColor;
  Color SelectedColor;
  int selection;

  void prepareMenu();

  void virtual Init(int Type);
public:

  Menu(int Type);

  int virtual StartMenu(RenderWindow& window);

  void selectionDown();

  void selectionUp();
};
