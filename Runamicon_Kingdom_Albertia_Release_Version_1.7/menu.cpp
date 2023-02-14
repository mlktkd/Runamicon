#include "menu.h"

extern GlobalFont globalFont;

void Menu::prepareMenu() {
  for (size_t i = 0; i < menu.size(); i++)
  {
    menu[i].setFont(globalFont());
    menu[i].setPosition(PosMenu.x, PosMenu.y + (40 * i));
    menu[i].setFillColor(fillColor);
  }
  menu[0].setFillColor(SelectedColor);
}

void Menu::Init(int Type) {
  MenuTexture.loadFromFile("Assets\\fon.png");
  MenuSprite.setTexture(MenuTexture);
  fillColor = Color(85, 43, 38);
  SelectedColor = Color(237, 241, 165);
  PosName.x = 250;
  PosName.y = 150;
  gameName.setString("RUNAMICON:   Kingdom  Albertia");
  gameName.setFont(globalFont());
  gameName.setPosition(PosName.x, PosName.y);
  gameName.setFillColor(Color(237, 241, 165));
  gameName.setScale(1.3f, 1.3f);
  //
  shadowGameName.setString("RUNAMICON:   Kingdom  Albertia");
  shadowGameName.setFont(globalFont());
  shadowGameName.setPosition(PosName.x + 5, PosName.y + 3);
  shadowGameName.setFillColor(Color(85, 43, 38));
  shadowGameName.setScale(1.3f, 1.3f);

  PosMenu.x = 350;
  PosMenu.y = 270;
  switch (Type) {
  default:
  case 0: //инициализация главного меню
    menu.resize(5);
    menu[0].setString("S t a r t    G a m e");
    menu[1].setString("S e t t i n g");
    menu[2].setString("H e l p");
    menu[3].setString("C r e d i t s");
    menu[4].setString("E x i t");
    prepareMenu();
    break;
  }
}

Menu::Menu(int Type) :selection() {
  Init(Type); 
}

int Menu::StartMenu(RenderWindow& window) {

  View MenuView;
  MenuView.setSize(window.getSize().x, window.getSize().y);
  MenuView.setCenter(window.getSize().x / 2, window.getSize().y / 2);
  window.setView(MenuView);

  Event menuEvent;
  while (true) {
    while (window.pollEvent(menuEvent))
    {
      if (menuEvent.type == Event::Closed) {
        window.close();
        return 4;
      }
      if (menuEvent.type == Event::KeyReleased) {
        switch (menuEvent.key.code)
        {
        case Keyboard::Up:
          selectionUp();
          break;
        case Keyboard::Down:
          selectionDown();
          break;
        case Keyboard::Left:
          break;
        case Keyboard::Right:
          break;
        case Keyboard::Enter:
          window.clear();
          return selection;
          break;
        default:
          break;
        }
      }
    }
    window.draw(MenuSprite);
    window.draw(shadowGameName);
    window.draw(gameName);
    for (size_t i = 0; i < menu.size(); i++)
    {
      window.draw(menu[i]);
    }

    window.display();
    window.clear();
  }
}

void Menu::selectionDown() {
  menu[selection].setFillColor(fillColor);
  if (selection >= menu.size() - 1) selection = 0;
  else ++selection;
  menu[selection].setFillColor(SelectedColor);
}

void Menu::selectionUp() {
  menu[selection].setFillColor(fillColor);
  if (!selection || selection < 0) selection = menu.size() - 1;
  else --selection;
  menu[selection].setFillColor(SelectedColor);
}