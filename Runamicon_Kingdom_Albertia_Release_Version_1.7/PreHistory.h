#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Coord.h"
#include "GlobalFont.h"
using namespace std;
using namespace sf;

class PreHistory {
	RectangleShape textFon;
	vector<Text> textline;
	Text KingName;
	Texture BgImg;
	Sprite BgFon;
	Color TextColor;
	Coord TextPos;
	Coord NamePos;
public:
	PreHistory();

	void Init();

	void StartHistory(RenderWindow& window);

};
