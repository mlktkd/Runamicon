#pragma once
#include "includes.h"
#include "Coord.h"
#include "GlobalFont.h"

struct LineNode {
  String line; // линия диалога
  std::vector<LineNode*> nextLines; // связи с другими линиями диалогов
  std::vector<String> answer; // возможные ответы 
  int Choice;
  int id;
  //-------------------------------------------------//

  LineNode();

  size_t size();

  String& operator[](int i);

  void ChoiceUp();

  void ChoiceDown();

  LineNode* getNext();

  ~LineNode(); // деструктор ничего не делает так как опасно что либо удалять по связям
};


class Diolog {
protected:
  Text text;
  Color selectedColor;
  Color fillColor;
  bool isCanTalk; // можно ли поговорить с NPC
  std::vector<LineNode*> lineSet; //тут хранятся все возможные узлы которые в дальнейшем будут объеденяться
  std::vector<LineNode*> startOfDialog; //старты диалога
  int currentStart; // показывает с какого диалога начать при следующем заходе
  LineNode* badEnd; // конец диалога без конкретного результата
  LineNode* goodEnd; // конец диалога с конкретным результатом
  LineNode* CurrentLineNode;
  bool isDiologActive;
  bool trigger;
public:
  Diolog();

  virtual void Init();

  bool GetIsCanTalk()const;

  bool GetIsDiologActive()const;

  bool GetTrigger()const;

  int GetCurrStart()const;

  void SetCurrStart(int currStart);

  void SetTrigger(bool val);

  void SetIsDiologAcitve(bool isActive);

  void SetIsCanTalk(bool val);

  void newDiolog();

  virtual void checkOnEnding();

  void startDiolog(RenderWindow& window);

  void Fill(std::string fileName);//загрузка диалога с файла (доделать)

  virtual void DrawBackGround(RenderWindow& window, Vector2f& temp);

  virtual void DrawBackGroundSprite(RenderWindow& window, Vector2f& pos);

  void Draw(RenderWindow& window);

  virtual ~Diolog();
};

class PDDIolog :public virtual Diolog {
protected:
  LineNode* trueEnd;
  Texture princessAndDragon;
  Texture dragonDark;
  Texture dragonBright;
  Texture princessFace;
  Texture End;
  Sprite backGroundSprite;
public:
  PDDIolog();

  void checkOnEnding()override;

  void DrawBackGroundSprite(RenderWindow& window, Vector2f& pos)override;

  void PrintEnd(RenderWindow& window);

  void DrawBackGround(RenderWindow& window, Vector2f& temp);

  void SetBackGroundPos(Vector2f pos);

  void PrepareDiolog();

  void Init() override;
};