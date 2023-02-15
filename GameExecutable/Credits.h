#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Coord.h"
#include "GlobalFont.h"
using namespace std;
using namespace sf;

class Credits {
	Texture BgImg;
	Sprite BgFon;
	vector<Text> text;
	Color TextColor;
	Color TextColorBg;
	Coord TextPos;
	Coord TitlePos;
public:
	Credits();
	void Init();
	void PrintCredits(RenderWindow& window);
};
