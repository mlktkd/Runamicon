#include "ImageAnimation.h"

Frames::Frames() : Height(), Width(), PosTexture() {}

Frames::Frames(Coord PosTexture, float Height, float Width) : Height(Height), Width(Width), PosTexture(PosTexture) {}

ImageAnimation::ImageAnimation() : texture(), AmountFrames(0), ArrImg(nullptr), CurrFrameNumber(0),animationspeed(1) { }

ImageAnimation::ImageAnimation(Sprite& sprite, string FileName, int AmountFrames, Frames* ArrImg) { Init(sprite, FileName, AmountFrames, ArrImg); }

void ImageAnimation::Init(Sprite& sprite, string FileName, int amountFrames, Frames* arrImg) {
	animationspeed = 1;
	texture.loadFromFile(FileName);
	sprite.setTexture(texture);
	if (amountFrames > 0) {
		AmountFrames = amountFrames;
		ArrImg = arrImg;
	}
	CurrFrameNumber = 0;
	sprite.setTextureRect(IntRect(ArrImg[0].PosTexture.x, ArrImg[0].PosTexture.y, ArrImg[0].Width, ArrImg[0].Height));
}

void ImageAnimation::Init(Sprite& sprite, GlobalTextures& texture, int amountFrames, Frames* arrImg) {
	animationspeed = 1;
	sprite.setTexture(texture());
	if (amountFrames > 0) {
		AmountFrames = amountFrames;
		ArrImg = arrImg;
	}
	CurrFrameNumber = 0;
	sprite.setTextureRect(IntRect(ArrImg[0].PosTexture.x, ArrImg[0].PosTexture.y, ArrImg[0].Width, ArrImg[0].Height));
}

int ImageAnimation::GetCurrFrameNum() const { return (int)CurrFrameNumber; }

int ImageAnimation::GetAmountFrames() const { return AmountFrames; }

void ImageAnimation::SetArrImg(int amountFrames, Frames* arrImg) {
	delete[] ArrImg;
	AmountFrames = amountFrames, ArrImg = arrImg;
}

void ImageAnimation::SetNextFrame(Sprite& sprite, float CurrTime) {
	CurrFrameNumber += GlobalAnimationSpeed * CurrTime * animationspeed;
	//cout << "CurrTime: " << CurrTime << "    CurrFrame: " << CurrFrameNumber << "\n";
	if (CurrFrameNumber >= AmountFrames) {
		CurrFrameNumber = 0;
	}
	//cout << CurrFrameNumber << endl;
	sprite.setTextureRect(IntRect(ArrImg[(int)CurrFrameNumber].PosTexture.x, ArrImg[(int)CurrFrameNumber].PosTexture.y, ArrImg[(int)CurrFrameNumber].Width, ArrImg[(int)CurrFrameNumber].Height));
}

void ImageAnimation::SetFirstImg(Sprite& sprite) {
	sprite.setTextureRect(IntRect(ArrImg[0].PosTexture.x, ArrImg[0].PosTexture.y, ArrImg[0].Width, ArrImg[0].Height));
}

ImageAnimation::~ImageAnimation() { if(ArrImg) delete[]ArrImg; }