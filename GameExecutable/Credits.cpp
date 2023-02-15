#include "Credits.h"
extern GlobalFont globalFont;
void WaitForAction(RenderWindow& window, float WaitTime);

Credits::Credits() { Init(); }

void Credits::Init() {
  TextColor = Color(187, 167, 55);
  TextColorBg = Color(28, 29, 68);
  TitlePos = Coord(830, 250);
  TextPos = Coord(700, 400);

  text.resize(8);
  text[0].setString("C R E D I T S: ");
  text[1].setString("C R E D I T S: ");
  text[2].setString("Y e l e m a n o v   T e m i r l a n");
  text[3].setString("Y e l e m a n o v   T e m i r l a n");
  text[4].setString("                                  & &");
  text[5].setString("                                  & &");
  text[6].setString("K a l i a s k a r o v a   M a l i k a");
  text[7].setString("K a l i a s k a r o v a   M a l i k a");

  text[0].setFillColor(TextColorBg);
  text[0].setFont(globalFont());
  text[0].setScale(1.f, 1.f);
  text[0].setPosition(TitlePos.x + 5, TitlePos.y + 3);
  text[1].setFillColor(TextColor);
  text[1].setFont(globalFont());
  text[1].setScale(1.f, 1.f);
  text[1].setPosition(TitlePos.x, TitlePos.y);

  for (int i = 0; i < 6; i += 2) {
    text[i + 2].setFillColor(TextColorBg);
    text[i + 2].setFont(globalFont());
    text[i + 2].setScale(0.9f, 0.9f);
    text[i + 2].setPosition(TextPos.x + 5, TextPos.y + (i * 35) + 3);

    text[i + 3].setFillColor(TextColor);
    text[i + 3].setFont(globalFont());
    text[i + 3].setScale(0.9f, 0.9f);
    text[i + 3].setPosition(TextPos.x, TextPos.y + (i * 35));
  }

  BgImg.loadFromFile("Assets\\credits.png");
  BgFon.setTexture(BgImg);

}

void Credits::PrintCredits(RenderWindow& window) {
  while (true) {
    Event event;
    window.draw(BgFon);
    for (int i = 0; i < text.size(); i++) {
      window.draw(text[i]);
    }
    while (window.pollEvent(event)) {
      if (event.key.code == Keyboard::Q) return;
      if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Enter) {
          return;
        }
      }
    }
    window.display();
    window.clear();
  }
}