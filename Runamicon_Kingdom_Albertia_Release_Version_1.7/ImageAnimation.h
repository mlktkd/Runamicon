#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <windows.h>
#include "Coord.h"
#include "Map.h"
#include "GlobalTextures.h"

using namespace sf;
using namespace std;

struct Frames {
	float Height, Width;
	Coord PosTexture;
	Frames();
	Frames(Coord PosTexture, float Height, float Width);
};

extern float GlobalAnimationSpeed;

class ImageAnimation {
protected:
	Texture texture;
	int AmountFrames;       // количество спрайтов в ряду
	Frames* ArrImg;
	float CurrFrameNumber;  // номер текущей картинк
public:
	float animationspeed;
	ImageAnimation();

	ImageAnimation(Sprite& sprite, string FileName, int AmountFrames, Frames* ArrImg);

	void Init(Sprite& sprite, string FileName, int amountFrames, Frames* arrImg);

	void Init(Sprite& sprite, GlobalTextures& texture, int amountFrames, Frames* arrImg);

	int GetCurrFrameNum()const;

	int GetAmountFrames()const;

	void SetArrImg(int amountFrames, Frames* arrImg);

	void SetNextFrame(Sprite& sprite, float CurrTime);

	void SetFirstImg(Sprite& sprite);

	~ImageAnimation();
};
