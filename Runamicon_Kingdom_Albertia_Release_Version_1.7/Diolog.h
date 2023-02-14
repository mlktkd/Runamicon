#pragma once
#include "includes.h"
#include "Coord.h"
#include "GlobalFont.h"

struct LineNode {
  String line; // ����� �������
  std::vector<LineNode*> nextLines; // ����� � ������� ������� ��������
  std::vector<String> answer; // ��������� ������ 
  int Choice;
  int id;
  //-------------------------------------------------//

  LineNode();

  size_t size();

  String& operator[](int i);

  void ChoiceUp();

  void ChoiceDown();

  LineNode* getNext();

  ~LineNode(); // ���������� ������ �� ������ ��� ��� ������ ��� ���� ������� �� ������
};


class Diolog {
protected:
  Text text;
  Color selectedColor;
  Color fillColor;
  bool isCanTalk; // ����� �� ���������� � NPC
  std::vector<LineNode*> lineSet; //��� �������� ��� ��������� ���� ������� � ���������� ����� ������������
  std::vector<LineNode*> startOfDialog; //������ �������
  int currentStart; // ���������� � ������ ������� ������ ��� ��������� ������
  LineNode* badEnd; // ����� ������� ��� ����������� ����������
  LineNode* goodEnd; // ����� ������� � ���������� �����������
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

  void Fill(std::string fileName);//�������� ������� � ����� (��������)

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