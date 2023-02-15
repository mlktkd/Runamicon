#include "Game.h"

Clock TimerForAnimation;

extern GlobalFont globalFont;

extern bool isGameOver;

extern int playerPotionCount;

extern SoundManager GlobalMusic;

Coord WolvesStartCoords[AMOUNTWOLVES]{
  //Top Path
  Coord(96, 96),Coord(544, 96),Coord(960, 96),Coord(1760, 96),Coord(2080, 448),Coord(3200, 480),Coord(4128, 96),
  //Mid Path
  Coord(1280, 512),Coord(1626, 512),Coord(3200, 640),Coord(3104,640),
  //Buttom Path
  Coord(640,1056),Coord(1120,1184),Coord(1568,1184),Coord(1888,1184),Coord(2496,1184),Coord(1888,992),
  Coord(2496,992),Coord(1888,832),Coord(2496,832),Coord(4192,1120),Coord(4640,1120),Coord(3712,992),
};

Coord SkeletonesStartCoords[AMOUNTSKELKETONES]{
  Coord(96,96),Coord(320, 512),Coord(640,128),Coord(704, 448),Coord(1024, 224),
  Coord(1408, 256),Coord(1568, 384),Coord(1984, 128),Coord(2304, 256),Coord(2656, 128),
  Coord(2784,416),Coord(3072,96),Coord(320,832),Coord(736,832), Coord(1280,672),
  Coord(1152,1056),Coord(1696,864),Coord(2048,1088),Coord(1824,1152), Coord(2016,1248),
  Coord(2272,608),Coord(2752,992),Coord(2784,1216),Coord(2848,1312), Coord(2720,1440),
  Coord(2848,1568),Coord(2336,1248),Coord(1408,1376),Coord(1888,1536), Coord(2336,1664),
  Coord(2656,1920),Coord(640,1472),Coord(544,1696),Coord(192,1312), Coord(352,2048),
  Coord(864,2080),Coord(608,2592),Coord(34,77),Coord(704,2972), Coord(192,2912),
  Coord(1312,3040),Coord(2144,2944),Coord(2464,2624),Coord(2816,2912), Coord(2912,2496),
  Coord(1376,1728),Coord(2304,2176),Coord(1760,3040),Coord(1856,1824), Coord(3008,1824),

};

Coord SlimeStartCoords[AMOUNTSLIME]{
  Coord(496, 288),Coord(784, 256),Coord(1008, 272),Coord(1088, 336),Coord(1248,272),
  Coord(1264,416),Coord(1296,608),Coord(1600, 672),Coord(1648, 624),Coord(109 * 16, 41 * 16),
  Coord(105 * 16,44 * 16),Coord(111 * 16,14 * 16),Coord(113 * 16,18 * 16),Coord(118 * 16,17 * 16),Coord(155 * 16,11 * 16),
  Coord(181 * 16,11 * 16),Coord(179 * 16,14 * 16),Coord(184 * 16,13 * 16),Coord(178 * 16,36 * 16),Coord(174 * 16,39 * 16),
  Coord(181 * 16,40 * 16),Coord(177 * 16,43 * 16),Coord(152 * 16,60 * 16),Coord(157 * 16,62 * 16),Coord(153 * 16,64 * 16),
  Coord(167 * 16,70 * 16),Coord(168 * 16,73 * 16),Coord(163 * 16,74 * 16),Coord(160 * 16,67 * 16),Coord(103 * 16,64 * 16),
  Coord(98 * 16,74 * 16),Coord(105 * 16,85 * 16),Coord(95 * 16,93 * 16),Coord(41 * 16,48 * 16),Coord(47 * 16,53 * 16),
  Coord(23 * 16,80 * 16),Coord(28 * 16,84 * 16),Coord(36 * 16,80 * 16),Coord(31 * 16,103 * 16),Coord(48 * 16,116 * 16),
  Coord(55 * 16,113 * 16),Coord(57 * 16,118 * 16),Coord(60 * 16,115 * 16),Coord(62 * 16,119 * 16),Coord(66 * 16,112 * 16),
  Coord(31 * 16,146 * 16),Coord(52 * 16,140 * 16),Coord(91 * 16,158 * 16),Coord(96 * 16,152 * 16),Coord(93 * 16,161 * 16),
  Coord(90 * 16,164 * 16),Coord(134 * 16,124 * 16),Coord(129 * 16,129 * 16),Coord(136 * 16,136 * 16),Coord(143 * 16,125 * 16),
  Coord(146 * 16,132 * 16),Coord(153 * 16,138 * 16),Coord(163 * 16,125 * 16),Coord(165 * 16,134 * 16),Coord(176 * 16,133 * 16),
};

Coord PotionCoords[AMOUNTPOTIONS]{
  Coord(100,100),Coord(3712,224),Coord(1632,352),Coord(160,1024),Coord(1216,1120),
};

Coord DesertPotionCoords[AMOUNTDESERTPOTIONS]{
  Coord(1472,288),Coord(2912,128),Coord(1952,1184),Coord(1952,1152),Coord(640,1600),Coord(800,2976),Coord(2688,2688),
};

Coord DesertSafeZoneCoords[AMOUNTSAFEZONES]{
  Coord(14 * 32,13 * 32),Coord(48 * 32,5 * 32),Coord(40 * 32,31 * 32),Coord(60 * 32,21 * 32),Coord(90 * 32,14 * 32),Coord(11 * 32,42 * 32),
  Coord(33 * 32,59 * 32),Coord(64 * 32,58 * 32),Coord(71 * 32,41 * 32),Coord(89 * 32,63 * 32),Coord(74 * 32,87 * 32),Coord(11 * 32,76 * 32),
  Coord(48 * 32,79 * 32),
};

Game::Game() :mainMenu(0), window(VideoMode(1920, 1081), "Runamicon: Kingdom Albertia"), CurrTime() {
  for (int i = 0; i < AMOUNTWOLVES; ++i) {
    wolves[i].SetPos(WolvesStartCoords[i]); //расстановка волков
  }
  for (int i = 0; i < AMOUNTSKELKETONES; ++i) {
    skeleton[i].SetPos(SkeletonesStartCoords[i]); //расстановка скелетов
  }
  for (int i = 0; i < AMOUNTSLIME; ++i) {
    slime[i].SetPos(SlimeStartCoords[i]); //расстановка скелетов
  }
  for (size_t i = 0; i < AMOUNTPOTIONS; i++)
  {
    potions.push_back(Potion(PotionCoords[i]));
  }
  for (size_t i = 0; i < AMOUNTDESERTPOTIONS; i++)
  {
    desertPotions.push_back(Potion(DesertPotionCoords[i]));
  }
  for (size_t i = 0; i < AMOUNTSAFEZONES; i++)
  {
    SafeZone[i].SetCoord(DesertSafeZoneCoords[i]);
    SafeZone[i].height = 224;
    SafeZone[i].width = 224;
    SafeZone[i].box.setPosition(DesertSafeZoneCoords[i].x, DesertSafeZoneCoords[i].y);
    SafeZone[i].box.setFillColor(Color(1, 0, 0, 100));
    SafeZone[i].box.setSize(Vector2f(224, 224));
  }
}

void Game::Start() {
  Event event;
  CurrTime = TimerForAnimation.getElapsedTime().asSeconds();
  TimerForAnimation.restart();
  GlobalMusic.theme1.play();

  while (window.isOpen()) {
    while (window.pollEvent(event))
    {
      if (event.type == Event::Closed) window.close();
      switch (mainMenu.StartMenu(window))
      {
      case 0: history.StartHistory(window); StartGame();break;
      case 3: credits.PrintCredits(window); break;
      case 4:
        GlobalMusic.StopAllSounds();
        window.close();
        break;
      default:
        break;
      }
    }
  }
}

void Game::StartGame() {
  View RenderView;
  Coord center;
  center = Coord(50, 50);
  RenderView.setSize(600, 400);
  RenderView.setCenter(center.x + 100, center.y);
  window.setView(RenderView);

  Clock clock;
  float pressingTime = 0;
  while (true) {
    float time = clock.getElapsedTime().asMicroseconds();
    clock.restart();
    time /= 800;
    Event event;
    State newState1 = standing;
    State newState2 = standing;
    pressingTime += time;
    if (!player.GetIsAlive()) {
      if (GlobalMusic.scream.getStatus() == SoundSource::Stopped) {
        GlobalMusic.scream.play();
      }
      player.SetNewState(State::dying);
      if (pressingTime > 13) {
        if (player.GetSpriteAnim().GetCurrFrameNum() < player.GetSpriteAnim().GetAmountFrames() - 1) {
          player.SetNextFrameEntity(CurrTime);
        }
        pressingTime = 0;
      }
    }
    else {
      if (!travaler.TDiolog.GetIsDiologActive()) {
        if (pressingTime > 10) { // привязка ко времени движения всех врагов и главного персонажа

          if (player.GetCurrState() == State::damaging && player.GetSpriteAnim().GetCurrFrameNum() <= player.GetSpriteAnim().GetAmountFrames() - 1) {
            if (!GlobalMusic.CheckIfOOFPlayed()) {
              GlobalMusic.PlayRandomOOF();
            }
            if (player.GetSpriteAnim().GetCurrFrameNum() == player.GetSpriteAnim().GetAmountFrames() - 1) {
              player.SetNewState(State::standing);
              player.SetOldHealth(player.GetHealth());
              if (player.GetCurrDir() == Diraction::left || ((player.GetCurrDir() == Diraction::up || player.GetCurrDir() == Diraction::down) && player.GetOldDir() == Diraction::left)) { player.SetNewTileSetLeft(); }
              else if (player.GetCurrDir() == Diraction::right || ((player.GetCurrDir() == Diraction::up || player.GetCurrDir() == Diraction::down) && player.GetOldDir() == Diraction::right)) { player.SetNewTileSetRight(); }
            }
            player.SetNextFrameEntity(CurrTime);
          }
          else if (player.GetCurrState() == State::atacking && player.GetSpriteAnim().GetCurrFrameNum() < player.GetSpriteAnim().GetAmountFrames()) {
            player.Move(player.GetCurrDir(), player.GetCurrState(), window, map, CurrTime);
            if (player.GetSpriteAnim().GetCurrFrameNum() == player.GetSpriteAnim().GetAmountFrames() - 1) {

              GlobalMusic.sword.play();

              if (map.GetCurrentMapNum() == 0) {

                player.Attack(wolves); // атака, пробежка по массиву, если может задеть хитбоксом то бьет
              }
              else if (map.GetCurrentMapNum() == 1) {
                player.Attack(skeleton);
              }
              else {
                player.Attack(slime);
              }
              player.SetNewState(State::standing);
            }
          }
          else {
            if (Keyboard::isKeyPressed(Keyboard::RShift) || Keyboard::isKeyPressed(Keyboard::RControl) || Keyboard::isKeyPressed(Keyboard::Up) ||
              Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right)) {
              if (Keyboard::isKeyPressed(Keyboard::RShift)) { newState1 = atacking; }
              if (Keyboard::isKeyPressed(Keyboard::RControl)) { newState1 = blocking; }
              if ((Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right))
                && !(Keyboard::isKeyPressed(Keyboard::RShift)) && !(Keyboard::isKeyPressed(Keyboard::RControl))) {
                newState1 = walking;
              }
              if (!(Keyboard::isKeyPressed(Keyboard::Up)) && !(Keyboard::isKeyPressed(Keyboard::Down)) && !(Keyboard::isKeyPressed(Keyboard::Left)) && !(Keyboard::isKeyPressed(Keyboard::Right))
                && ((Keyboard::isKeyPressed(Keyboard::RShift)) || (Keyboard::isKeyPressed(Keyboard::RControl)))) {
                player.Move(player.GetCurrDir(), newState1, window, map, CurrTime);
              }
              else {
                if (Keyboard::isKeyPressed(Keyboard::Up)) { player.Move(Diraction::up, newState1, window, map, CurrTime); }
                if (Keyboard::isKeyPressed(Keyboard::Down)) { player.Move(Diraction::down, newState1, window, map, CurrTime); }
                if (Keyboard::isKeyPressed(Keyboard::Left)) { player.Move(Diraction::left, newState1, window, map, CurrTime); }
                if (Keyboard::isKeyPressed(Keyboard::Right)) { player.Move(Diraction::right, newState1, window, map, CurrTime); }
              }
            }
            else {
              newState1 = standing;
              player.Move(player.GetCurrDir(), newState1, window, map, CurrTime);
            }
          }
          MoveEntities(); // движение всех врагов 
          pressingTime = 0;
        }
      }
      else {
        travaler.TDiolog.startDiolog(window);
        if (travaler.GetTrigger()) {
          travaler.SetTrigger(false);
          player.BuyQuestPotion();
        }
      }
    }

    while (window.pollEvent(event)) {
      if (event.key.code == Keyboard::Q) return;
      if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::F) {
          if (map.GetCurrentMapNum() == 0) {
            PickUpPotions(potions);//подбирание зелий в лесу
          }
          else if (map.GetCurrentMapNum() == 1) { // разговаривание с путешественником
            if (player.Interract(travaler.GetHitBox())) {
              playerPotionCount = player.getPotionCnt();
              travaler.StartDiolog();
            }
            PickUpPotions(desertPotions); // подбирание зелий в пустыне
          }
          else if (map.GetCurrentMapNum() == 2) {
            if (player.Interract(PD.GetHitBox())) {
              playerPotionCount = player.getQuestPotionCnt();
              PD.StartEndDiolog(window);
            }
          }
        }
        if (event.key.code == Keyboard::H) { // отхил
          player.UsePotion();
        }
      }
    }
    if (isGameOver) {
      UpdateGame();
      return;
    }
    SetCenter(RenderView, player.GetPos().x + 50, player.GetPos().y + 60); // предатврощение выхода view за границу карты
    window.setView(RenderView);
    map.Draw(window);

    DrawEntities(); // прорисовка всех врагов

    player.Draw(window);
    map.DrawTopLayer(window);

    if (map.GetCurrentMapNum() == 1) {
      travaler.Draw(window);
      if (!SafeZoneInteraction()) player.ReduceEndurance(DESERTPASSIVEDAMAGE);
    }
    player.DrawHUD(window);

    if (!player.GetIsAlive() && player.GetCurrState() == State::dying && player.GetSpriteAnim().GetCurrFrameNum() == player.GetSpriteAnim().GetAmountFrames() - 1) {
      UpdateGame();
      DrawGameOver();
      window.display();
      window.clear();
      return;
    }
    window.display();
    window.clear();
  }
}

void Game::PickUpPotions(list<Potion>& Lpotions) {
  for (list<Potion>::iterator it(begin(Lpotions)); it != end(Lpotions); ++it)
  {
    if (player.Interract(it->GetHitBox())) {
      player.PickUpPotion(*it);
      it = Lpotions.erase(it);
      if (it == Lpotions.end()) {
        break;
      }
    }
  }
}

void Game::SetCenter(View& view, float x, float y) {
  Box MapSize = map.GetSizeOfMap(); //ширина и высота карты
  float center_x = view.getSize().x / 2; // центр вюшки по х
  float center_y = view.getSize().y / 2; // центр вюшки по y
  float vx = x, vy = y; // координаты центра вюшки которые будут изменяться если надо
  if (x < center_x)vx = center_x; // когда игрок по х меньше центра вьюшки по x
  if (y < center_y) vy = center_y; // когда игрок по y меньше центра вьюшки по y
  if (x > MapSize.width - center_x)vx = MapSize.width - center_x; // когда координаты игрока по x привышают границу центра вьюшки по правой стороне
  if (y > MapSize.height - center_y)vy = MapSize.height - center_y; //когда координаты игрока по y привышают границу центра вьюшки по нижней стороне
  view.setCenter(vx, vy);
}

void Game::MoveEntities() {
  //идет движение относительно нынешней карты
  if (map.GetCurrentMapNum() == 0) {
    for (int i = 0; i < AMOUNTWOLVES; i++) {
      if (wolves[i].GetIsAlive()) {
        if (wolves[i].isPlInFieldOfView(player)) {
          if (wolves[i].GetCurrState() != State::damaging) {
            wolves[i].SetState(State::walking, CurrTime);
          }
          wolves[i].Move(player, map, CurrTime);
        }
        else { wolves[i].SetState(State::standing, CurrTime); }
      }
      else { //анимация смерти
        wolves[i].SetState(State::dying, CurrTime);
        if (wolves[i].GetSpriteAnim().GetCurrFrameNum() < wolves[i].GetSpriteAnim().GetAmountFrames() - 1) {
          wolves[i].SetNextFrameEntity(CurrTime);
        }
      }
    }
  }
  else if (map.GetCurrentMapNum() == 1) {
    for (int i = 0; i < AMOUNTSKELKETONES; i++) {
      if (skeleton[i].GetIsAlive()) {
        if (skeleton[i].isPlInFieldOfView(player)) {
          if (skeleton[i].GetCurrState() != State::damaging) {
            skeleton[i].SetState(State::walking, CurrTime);
          }
          skeleton[i].Move(player, map, CurrTime);
        }
        else { skeleton[i].SetState(State::standing, CurrTime); }
      }
      else {
        skeleton[i].SetState(State::dying, CurrTime);
        if (skeleton[i].GetSpriteAnim().GetCurrFrameNum() < skeleton[i].GetSpriteAnim().GetAmountFrames() - 1) {
          skeleton[i].SetNextFrameEntity(CurrTime);
        }
      }
    }
  }
  else if (map.GetCurrentMapNum() == 2) {
    for (int i = 0; i < AMOUNTSLIME; i++) {
      if (slime[i].GetIsAlive()) {
        if (slime[i].isPlInFieldOfView(player)) {
          if (slime[i].GetCurrState() != State::damaging) {
            slime[i].SetState(State::walking, CurrTime);
          }
          slime[i].Move(player, map, CurrTime);
        }
        else { slime[i].SetState(State::standing, CurrTime); }
      }
      else {
        slime[i].SetState(State::dying, CurrTime);
        if (slime[i].GetSpriteAnim().GetCurrFrameNum() < slime[i].GetSpriteAnim().GetAmountFrames() - 1) {
          slime[i].SetNextFrameEntity(CurrTime);
        }
      }
    }
  }
}

void Game::DrawEntities() {
  //прорисовка если карта совпадает с картой где должны быть волки
  if (map.GetCurrentMapNum() == 0) {
    for (int i = 0; i < AMOUNTWOLVES; i++) {
      wolves[i].Draw(window);
    }
    for (auto& p : potions) {
      p.Draw(window);
    }
  }
  else if (map.GetCurrentMapNum() == 1) {
    for (int i = 0; i < AMOUNTSKELKETONES; i++) {
      skeleton[i].Draw(window);
    }
    for (auto& p : desertPotions) {
      p.Draw(window);
    }
    player.DrawEnduranceBar(window);
    /*for (size_t i = 0; i < AMOUNTSAFEZONES; i++)
    {
      window.draw(SafeZone[i].box);
    }*/
  }
  else if (map.GetCurrentMapNum() == 2) {
    for (int i = 0; i < AMOUNTSLIME; i++) {
      slime[i].Draw(window);
    }
    PD.Draw(window);
  }
}

bool Game::SafeZoneInteraction()
{
  for (size_t i = 0; i < AMOUNTSAFEZONES; i++)
  {
    if (player.Interract(SafeZone[i])) {
      player.RestoreEndurance(DESERTENDURANCERESTORATION);
      return true;
    }
  }
  return false;
}

void Game::UpdateGame() {
  // обновление игрока
  GlobalMusic.StopAllSounds();
  GlobalMusic.theme1.play();
  isGameOver = false;
  player.Revival();
  // обновление противников
  for (size_t i = 0; i < AMOUNTWOLVES; ++i) {
    wolves[i].Revival(WolvesStartCoords[i]);
  }

  for (size_t i = 0; i < AMOUNTSKELKETONES; ++i) {
      skeleton[i].Revival(SkeletonesStartCoords[i]);
  }

  for (size_t i = 0; i < AMOUNTSLIME; ++i) {
      slime[i].Revival(SlimeStartCoords[i]);
  }
  // обновление зелий
  for (list<Potion>::iterator it(begin(potions)); it != end(potions); ++it) {
    it = potions.erase(it);
    if (it == potions.end()) {
      break;
    }
  }
  for (size_t i = 0; i < AMOUNTPOTIONS; i++) {
    potions.push_back(Potion(PotionCoords[i]));
  }

  for (list<Potion>::iterator it(begin(desertPotions)); it != end(desertPotions); ++it) {
    it = desertPotions.erase(it);
    if (it == desertPotions.end()) {
      break;
    }
  }
  for (size_t i = 0; i < AMOUNTDESERTPOTIONS; i++) {
    desertPotions.push_back(Potion(DesertPotionCoords[i]));
  }
  // обновление диалога
  if (travaler.TDiolog.GetCurrStart() != 0) { travaler.TDiolog.SetCurrStart(0); }
  travaler.TDiolog.SetIsCanTalk(true);

  // обновление карты
  if (map.GetCurrentMapNum() != 0) {
    if (map.GetCurrentMapNum() == 2) {
      map.SetPreviousMap();
    }
    if (map.GetCurrentMapNum() == 1) {
      map.SetPreviousMap();
      map.SetSpownPoint(Coord(100, 600));
    }
  }
}

void Game::DrawGameOver() {
  Text text;
  RectangleShape YouLose;
  YouLose.setPosition(Vector2f(window.getView().getCenter().x - window.getView().getSize().x, window.getView().getCenter().y - window.getView().getSize().y));
  YouLose.setSize(Vector2f(window.getView().getSize().x * 2, window.getView().getSize().y * 2));
  YouLose.setFillColor(Color(1, 1, 1, 220));
  text.setFont(globalFont());
  text.setString("YOU LOSE");
  text.setPosition(Vector2f(window.getView().getCenter().x - 60, window.getView().getCenter().y - 20));
  text.setFillColor(Color(138, 14, 14));
  text.scale(Vector2f(0.5, 0.5));
  window.draw(YouLose);
  window.draw(text);
}