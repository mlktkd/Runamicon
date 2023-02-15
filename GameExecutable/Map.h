#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <iomanip>
#include <string>
#include <vector>
#include "Box.h"
#include "SoundManager.h"
using namespace sf;

class BaseTile {
protected:
  Texture texture;
  Sprite tileSprite;
  char CurrentChar;
public:
  BaseTile();

  BaseTile(std::string fileName);

  virtual void Init(std::string fileName);

  virtual void setTilePos(Coord pos);

  virtual void setTilePos(float x, float y);

  virtual void SetTileScale(float x, float y);

  virtual char GetCh()const;

  virtual Sprite& getTilSprite();

  virtual bool isNotSame(char ch);

  virtual bool SetTextureRectByChar(char ch) = 0;

  virtual ~BaseTile() = 0;
};

class ForestTileSet :public virtual BaseTile {
public:
  ForestTileSet();
  ForestTileSet(std::string fileName);
  bool SetTextureRectByChar(char ch);
};

class LakeTileSet :virtual public BaseTile {
public:
  LakeTileSet();
  LakeTileSet(std::string FileName);
  bool SetTextureRectByChar(char ch)override;
};

class GrassTileSet : virtual public BaseTile {
public:
  GrassTileSet();
  GrassTileSet(std::string fileName);
  bool SetTextureRectByChar(char ch)override;
};

class TreeTileSet :virtual public BaseTile {
public:
  TreeTileSet();
  TreeTileSet(std::string fileName);
  bool SetTextureRectByChar(char ch) override;
};

class RockTileSet : virtual public BaseTile {
public:
  RockTileSet();
  RockTileSet(std::string FileName);
  bool SetTextureRectByChar(char ch) override;
};

class DesertMap : virtual public BaseTile {
public:
  DesertMap();
  DesertMap(std::string FileName);
  bool SetTextureRectByChar(char ch)override;
};

class CaveMap : virtual public BaseTile {
public:
  CaveMap();
  CaveMap(std::string FileName);
  bool SetTextureRectByChar(char ch)override;
};

class Map
{
  std::vector<BaseTile*> TileSet;
  int CurrentMapNum;
  Coord SpownPoint;
  float height;
  float width;
public:
  String* CurrentMap;

  Map();

  void Init();

  int GetCurrentMapNum()const;

  Coord GetSpownPoint()const;

  void SetNextMap();

  void SetPreviousMap();

  void SetSpownPoint(Coord pos);

  void Draw(RenderWindow& window);

  void DrawTopLayer(RenderWindow& window);

  Box GetSizeOfMap();

  ~Map();
};

