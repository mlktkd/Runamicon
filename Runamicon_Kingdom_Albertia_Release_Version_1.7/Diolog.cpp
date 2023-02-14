#include "Diolog.h"

extern GlobalFont globalFont;

LineNode::LineNode() : line(), nextLines(), answer(), Choice(), id() {}

size_t LineNode::size() { return nextLines.size(); }

String& LineNode::operator[](int i) {
  return answer[i]; // получение ответа по индексу
}

LineNode* LineNode::getNext() { return nextLines[Choice]; } // шаг вперед по индексу

void LineNode::ChoiceUp() {
  if (!Choice)Choice = size() - 1;
  else Choice--;
}

void LineNode::ChoiceDown() {
  if (Choice == size() - 1)Choice = 0;
  else Choice++;
}

LineNode::~LineNode() {} // деструктор ничего не делает так как опасно что либо удалять по связям

// -------------------------------------------------------------------------------------- //

Diolog::Diolog() :lineSet(), startOfDialog(), currentStart(), badEnd(), goodEnd(), isDiologActive(), isCanTalk(true), CurrentLineNode(), trigger() {
  text.setFont(globalFont());
  fillColor = Color(160, 20, 60);
  selectedColor = Color(237, 241, 165);
  text.scale(Vector2f(0.3, 0.3));
}

void Diolog::Init() {
  lineSet.push_back(new LineNode()); //0
  lineSet[0]->line = "Hello, dear Knight! I mean no harm, please lower your sword.";
  lineSet[0]->answer.push_back("Hello for you too!");
  lineSet[0]->answer.push_back("Who are you? I don't trust strangers, \nand what are you doing in such a dangerows place?");
  lineSet[0]->answer.push_back("GoodBye");
  lineSet.push_back(new LineNode());//1
  lineSet[1]->line = "You may be curious why i am here and who i am.\n But trust me i'm harmless, i just travel across the world.";
  lineSet[1]->answer.push_back("...");
  lineSet.push_back(new LineNode());//2
  lineSet[2]->line = "...";
  lineSet[2]->answer.push_back("How did you get here ?");
  lineSet[2]->answer.push_back("Do you know anything about Meridius Graybeard");
  lineSet[2]->answer.push_back("Let's trade for a healing potion");
  lineSet[2]->answer.push_back("Ok Goodbye then");
  lineSet.push_back(new LineNode());//3
  lineSet[3]->line = "It's a long story. \nI've been chased by evil creatures and they left when i got here. \nThis oasis must contain some protective magic against evil creatures.";
  lineSet[3]->answer.push_back("...");
  lineSet.push_back(new LineNode());//4
  lineSet[4]->line = "Oh that odd mage... Yeah i've stumbled across with him a couple times. \nHe is experiensed travaler you know. \nBut this is the only thing i know. \nI've got something related to him,\nand if you want to we can trade for a healing potion.";
  lineSet[4]->answer.push_back("...");
  lineSet.push_back(new LineNode());//5
  lineSet[5]->line = "Ok, i found this weird potion, maybe you will make use of it...";
  lineSet[5]->answer.push_back("...");
  lineSet.push_back(new LineNode());//6
  lineSet[6]->line = "See you later...";
  lineSet[6]->answer.push_back("...");
  lineSet.push_back(new LineNode());//7
  lineSet[7]->line = "good end";
  lineSet[7]->answer.push_back("...");
  lineSet.push_back(new LineNode());//8
  lineSet[8]->line = "bad end";
  lineSet[8]->answer.push_back("...");
  startOfDialog.push_back(lineSet[0]);
  startOfDialog.push_back(lineSet[2]);
  currentStart = 0;
  badEnd = lineSet[8];
  goodEnd = lineSet[7];
  lineSet[0]->nextLines.push_back(lineSet[1]);
  lineSet[0]->nextLines.push_back(lineSet[1]);
  lineSet[0]->nextLines.push_back(lineSet[6]);
  lineSet[1]->nextLines.push_back(lineSet[2]);
  lineSet[2]->nextLines.push_back(lineSet[3]);
  lineSet[2]->nextLines.push_back(lineSet[4]);
  lineSet[2]->nextLines.push_back(lineSet[5]);
  lineSet[2]->nextLines.push_back(lineSet[6]);
  lineSet[3]->nextLines.push_back(lineSet[2]);
  lineSet[4]->nextLines.push_back(lineSet[2]);
  lineSet[6]->nextLines.push_back(lineSet[8]);
  lineSet[5]->nextLines.push_back(lineSet[7]);
  //---//
  CurrentLineNode = startOfDialog[currentStart];
}

bool Diolog::GetIsCanTalk()const { return isCanTalk; }

bool Diolog::GetIsDiologActive()const { return isDiologActive; }

void Diolog::SetCurrStart(int currStart) { currentStart = currStart; }

int Diolog::GetCurrStart() const { return currentStart; }

void Diolog::SetIsDiologAcitve(bool isActive) {
  isDiologActive = isActive;
}

void Diolog::SetIsCanTalk(bool val)
{
  isCanTalk = val;
}

void Diolog::newDiolog() {
  CurrentLineNode = startOfDialog[currentStart];
}

void Diolog::checkOnEnding()
{
  if (CurrentLineNode == badEnd) {
    currentStart = 1;
    isDiologActive = false;
  }
  else if (CurrentLineNode == goodEnd) {
    extern int playerPotionCount;
    currentStart = 1;
    isDiologActive = false;
    if (playerPotionCount) {
      isCanTalk = false;
      trigger = true;
    }
  }
}

bool Diolog::GetTrigger() const
{
  return trigger;
}

void Diolog::SetTrigger(bool val)
{
  trigger = val;
}

void Diolog::startDiolog(RenderWindow& window) {

  checkOnEnding();

  Event event;

  while (window.pollEvent(event)) {
    if (event.type == Event::KeyReleased) {
      switch (event.key.code)
      {
      case Keyboard::Up:
        CurrentLineNode->ChoiceUp();
        break;
      case Keyboard::Down:
        CurrentLineNode->ChoiceDown();
        break;
      case Keyboard::Enter:
        CurrentLineNode = CurrentLineNode->getNext();
        break;
      default:
        break;
      }
    }
  }
}

void Diolog::Fill(std::string fileName) {

}//загрузка диалога с файла (доделать)

void Diolog::DrawBackGround(RenderWindow& window, Vector2f& temp)
{
  RectangleShape background;
  background.setPosition(Vector2f(temp.x - 20, temp.y - 30));
  background.setSize(window.getView().getSize());
  background.setFillColor(Color(1, 1, 1, 200));
  window.draw(background);
}

void Diolog::DrawBackGroundSprite(RenderWindow& window, Vector2f& pos)
{
}

void Diolog::Draw(RenderWindow& window) {
  Vector2f temp(window.getView().getCenter());
  temp.x -= (window.getView().getSize().x / 2) - 20;
  temp.y -= 40;

  DrawBackGroundSprite(window, temp);

  DrawBackGround(window, temp);

  text.setString(CurrentLineNode->line);
  text.setPosition(temp);
  text.setFillColor(fillColor);
  window.draw(text);
  for (size_t i = 0; i < CurrentLineNode->size(); i++)
  {
    text.setString(CurrentLineNode->answer[i]);
    text.setPosition(Vector2f(temp.x, temp.y + ((i + 2) * 30)));
    if (CurrentLineNode->Choice == i) {
      text.setFillColor(selectedColor);
    }
    else {
      text.setFillColor(fillColor);
    }
    window.draw(text);
  }
}


Diolog::~Diolog() {
  for (size_t i = 0; i < lineSet.size(); i++)
  {
    delete lineSet[i];
  }
}

/// <summary>
/// -----------------------
/// </summary>

PDDIolog::PDDIolog()
{
  Init();
}

#define NEWLINENODE lineSet.push_back(new LineNode())
#define LINE(i) lineSet[ i ]->line
#define ANS(i) lineSet[ i ]->answer.push_back
#define DEFID(i) lineSet[ i ]->id = i;

void PDDIolog::Init()
{
  princessAndDragon.loadFromFile("Assets\\PrincessAndDragon.png");
  princessFace.loadFromFile("Assets\\PrincessFace.png");
  dragonDark.loadFromFile("Assets\\DragonDark.png");
  dragonBright.loadFromFile("Assets\\DragonBright.png");
  End.loadFromFile("Assets\\End.png");

  backGroundSprite.setTexture(dragonDark);
  backGroundSprite.scale(0.3125f, 0.3703f);

  String Name;
  Name = (rand() % 2 == 0 ? "Sesilia" : "Violett");
  NEWLINENODE; //0
  LINE(0) = " ............... ";
  ANS(0)(" .................. ");

  NEWLINENODE; //1
  LINE(1) = "Dragon: *deep voice* WHO ENTERS!?";
  ANS(1)("  ...  ");
  NEWLINENODE; //2
  LINE(2) = "Dragon: RRAAAAAAAHH!!!";
  ANS(2)("*Prepare Sword*");
  NEWLINENODE; //3
  LINE(3) = "Dragon: Aaah.. is that a Knight who came to save the princess!?";
  ANS(3)(" ... ");
  NEWLINENODE; //4
  LINE(4) = "Princess: Oh... Dear Knight.. Finaly someone Came to save me...";
  ANS(4)("I don't fear you Dragon! You won't stop me.");
  ANS(4)("No one told me about the Dragon... Are you protecting Princess?\n or do you hold her in captivity?");
  NEWLINENODE; //5
  LINE(5) = "Dragon: Always the same scenario... I already got board of this...\n Listen, i've got no reasons to fight with you.";
  ANS(5)("What? Aren't you a dragon?");
  NEWLINENODE; //6
  LINE(6) = "Princess: Wait, dear knight, this dragon is not dangerous to you.\n She would have ate me long time ago if she was.";
  ANS(6)(" ... ");
  NEWLINENODE; //7
  LINE(7) = "Dragon: Are you blind?\nOr you are not smart enough to understand that i am a prisoner too.\n Now lower your sword.";
  ANS(7)(" ... ");
  NEWLINENODE; //8
  LINE(8) = "Princess: You've come to save us right???";
  ANS(8)("Us? Why would i want to free a dangerous creature like a dragon?");
  ANS(8)("Yes! I've come to save you Princess " + Name);
  ANS(8)("May be..");
  NEWLINENODE; //9 перекресток
  LINE(9) = " .................... ";
  ANS(9)("Who Are You Dragon? And Why Are you here?");
  ANS(9)("What did this mage do to you Princess " + Name + "?");
  ANS(9)("How do i Free you?");
  ANS(9)("*Free the Princess*");
  ANS(9)("*Free the Dragon*");
  ANS(9)("*Free Both*");
  NEWLINENODE;//10
  LINE(10) = "Dragon Ursula: My name is Ursula!\n I am a Dragon that peacefully lived among high mountains, untill..\n Meridius The Gray Beard imprisoned me here.\n Since i am here I am Loosing my strength every day\n";
  ANS(10)("...");
  NEWLINENODE;//11
  LINE(11) = "Dragon Ursula: This mage has done something to me, and i don't know what.\n I've been here way longer than a princess.\n I would be greateful if you freed me too";
  ANS(11)("I'll think of that...");
  NEWLINENODE;//12
  LINE(12) = "Princess " + Name + ": This rude man imprisoned me for a ransome.\n My Father Didn't want to give him some stupid relic.\n But other than that he didn't do anything else to me.";
  ANS(12)("Strange...");
  NEWLINENODE;//13
  LINE(13) = "Dragon Ursula:\nI asume you've got to have a special potion that will breake our chains\n Just pour it on the chains and they will melt.";
  ANS(13)("...");
  NEWLINENODE;//14
  LINE(14) = "Princess" + Name + ": Yes, but didn't mage mention that this potion can free-\n-only one prisoner at a time?";
  ANS(14)("...");
  NEWLINENODE;//15
  LINE(15) = "Dragon: what a pity...";
  ANS(15)("...");
  NEWLINENODE;//16
  LINE(16) = "Princess " + Name + ": I knew that someone would save me, thank you my knight!";
  ANS(16)("I am sorry dragon, but duty calls...");
  NEWLINENODE;//17
  LINE(17) = "Dragon Ursula: YES! Freeedom! Finally! Thank you knight!\n I promise you won't regret your desicion!\n By the way, what is your name, human?";
  ANS(17)("My Name is Einar!... sorry, " + Name + ", \nbut i couldn't stand this opportunity to have a dragon at my back...");
  NEWLINENODE;//18
  LINE(18) = Name + ": NO! DON'T LEAVE ME HERE! How Could you!?\n I will tell my father what you did\n He will punish you and that stupid mage!!!";
  ANS(18)("...");
  NEWLINENODE;//19
  LINE(19) = "Dragon Ursula: Freedom! Thank you, human!\nPrincess " + Name + " how nobly! Thank you, my knight! Please tell us your name.\n";
  ANS(19)("My Name is Einar! Ursula, now that you are free, carry us to the kingdom!");
  NEWLINENODE;//20
  LINE(20) = "PRINCESS ROUT END";
  ANS(20)("...");
  NEWLINENODE;//21
  LINE(21) = "DRAGON ROUT END";
  ANS(21)("...");
  NEWLINENODE;//22
  LINE(22) = "TRUE ENDING";
  ANS(22)("...");

  for (size_t i = 0; i < 23; i++)
  {
    DEFID(i);
  }

  startOfDialog.push_back(lineSet[0]);
  currentStart = 0;
  CurrentLineNode = startOfDialog[currentStart];
  badEnd = lineSet[20];
  goodEnd = lineSet[21];
  trueEnd = lineSet[22];

#define LINK(i, j) lineSet[ i ]->nextLines.push_back(lineSet[ j ])
  LINK(0, 1);
  LINK(1, 2);
  LINK(2, 3);
  LINK(3, 4);
  LINK(4, 5);
  LINK(5, 6);
  LINK(6, 7);
  LINK(4, 7);
  LINK(7, 8);
  LINK(8, 9);
  LINK(8, 9);
  LINK(8, 9);
  LINK(9, 10);
  LINK(10, 11);
  LINK(11, 9);
  LINK(9, 12);
  LINK(12, 9);
  LINK(9, 13);
  LINK(13, 14);
  LINK(14, 9);
  LINK(9, 15);
  LINK(15, 16);
  LINK(16, 20);
  LINK(9, 17);
  LINK(17, 18);
  LINK(18, 21);
  LINK(9, 19);
  LINK(19, 22);

  
}

void PDDIolog::DrawBackGround(RenderWindow& window, Vector2f& temp)
{
}

void PDDIolog::checkOnEnding()
{
  if (CurrentLineNode == badEnd) {
    isDiologActive = false;
  }
  else if (CurrentLineNode == goodEnd) {
    isDiologActive = false;
  }
  else if (CurrentLineNode == trueEnd) {
    isDiologActive = false;
  }
}

void PDDIolog::DrawBackGroundSprite(RenderWindow& window, Vector2f& pos)
{
  switch (CurrentLineNode->id) {
  case 0:
  case 1:
  case 15:
  case 20:
  case 21:
  case 22:
    backGroundSprite.setTexture(dragonDark);
    break;
  case 2:
  case 3:
  case 5:
  case 10:
  case 11:
  case 13:
  case 17:
    backGroundSprite.setTexture(dragonBright);
    break;
  case 4:
  case 6:
  case 12:
  case 14:
  case 16:
  case 18:
    backGroundSprite.setTexture(princessFace);
    break;
  case 7:
  case 8:
  case 9:
  case 19:
    backGroundSprite.setTexture(princessAndDragon);
    break;
  default: break;
  }
  //backGroundSprite.setPosition(pos.x, pos.y - (window.getSize().y / 2));
  window.draw(backGroundSprite);
}

void PDDIolog::SetBackGroundPos(Vector2f pos)
{
  backGroundSprite.setPosition(pos);
}

//void WaitForAction(RenderWindow& window ,float waitTime) {
//  Clock clock1;
//  float EndTime = 0;
//  Event event;
//  while (EndTime < waitTime) {
//    float time = clock1.getElapsedTime().asMicroseconds();
//    clock1.restart();
//    time /= 800;
//    EndTime += time;
//
//    while (window.pollEvent(event)) {
//      if (event.key.code == Keyboard::Q) return;
//      if (event.type == Event::KeyReleased) {
//        if (event.key.code == Keyboard::Enter) {
//          return;
//        }
//      }
//    }
//  }
//}

void PDDIolog::PrintEnd(RenderWindow& window)
{
  Clock clock1;
  float EndTime = 0;

  Vector2f temp(window.getView().getCenter());
  temp.x -= 200;
  text.setFillColor(selectedColor);
  text.setPosition(temp);
  backGroundSprite.setTexture(End);
  Event event;
  while (EndTime < 10000) {
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
    window.draw(backGroundSprite);
    if (CurrentLineNode == badEnd) {
      text.setString("                       THE  END\nYOU   HAVE   SAVED   PRINCESS!");
    }
    else if (CurrentLineNode == goodEnd) {
      text.setString("                      THE   END\nYOU   HAVE   SAVED   DRAGON!");
    }
    else if (CurrentLineNode == trueEnd) {
      text.setString("                       TRUE END\nYOU   HAVE   SAVED   BOTH   PRINCESS   AND   DRAGON");
    }
    else {
      text.setString("SOMETHING WENT WRONG!");
    }
    window.draw(text);
    window.display();
    window.clear();
  }
}

void PDDIolog::PrepareDiolog()
{
  extern int playerPotionCount;
  if (playerPotionCount < 2) {
    lineSet[9]->nextLines[5] = lineSet[9];
  }
  else {
    lineSet[9]->nextLines[5] = lineSet[19];
  }
}