#include "PreHistory.h"

extern GlobalFont globalFont;
void WaitForAction(RenderWindow& window, float WaitTime);

PreHistory::PreHistory() { Init(); }

void PreHistory::Init() {
  textFon.setPosition(50, 90);
  textFon.setSize(Vector2f(1800, 300));
  textFon.setFillColor(Color(201, 181, 181, 150));

  TextColor = Color(99, 23, 23);
  NamePos = Coord(220, 130);
  TextPos = Coord(100, 200);

  textline.resize(6);
  textline[0].setString("Knight  Einar,  I  have  heard  about  your  considerable  experience  in  wandering.");
  textline[1].setString("As  we  all  know,  my  daughter,  your  Princess,  was  abducted  by  a  wizard.");
  textline[2].setString("You  have  to  find  and  save  her!");
  textline[3].setString("I'm  giving  you  potions  that  will  help  in  the  release  of  my  daughter.");
  textline[4].setString("The  whole  Kingdom  Albertia  has  relied  on  you.");
  textline[5].setString("Don't  you  dare  let  me  down,  otherwise,  you  won't  escape  execution.  Hit  the  road...");

  for (int i = 0; i < 6; i++) {
    textline[i].setFillColor(TextColor);
    textline[i].setFont(globalFont());
    textline[i].setScale(0.9f, 0.9f);
  }

  KingName.setString("KING  ALBERT:");
  KingName.setFillColor(TextColor);
  KingName.setFont(globalFont());
  KingName.setPosition(NamePos.x, NamePos.y);

  BgImg.loadFromFile("Assets\\history.png");
  BgFon.setTexture(BgImg);

}

void PreHistory::StartHistory(RenderWindow& window) {
  int i = 1;
  int idx = 0;
  Clock clock1;
  float EndTime = 0;
  while (i < 3) {
    window.draw(BgFon);
    window.draw(textFon);
    window.draw(KingName);
    for (int i = 0; i < 3; ++i) {
      textline[idx].setPosition(TextPos.x, TextPos.y + (i * 50));
      window.draw(textline[idx]);
      idx++;
    }
    window.display();
    WaitForAction(window, 20000);
    window.clear();
    i++;
  }
}

void WaitForAction(RenderWindow& window, float WaitTime) {
  Clock clock1;
  float EndTime = 0;
  Event event;
  while (EndTime < WaitTime) {
    float time = clock1.getElapsedTime().asMicroseconds();
    clock1.restart();
    time /= 800;
    EndTime += time;

    while (window.pollEvent(event)) {
      if (event.key.code == Keyboard::Q) return;
      if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Enter) {
          return;
        }
      }
    }
  }
}