#include "indicatorBar.h"
extern GlobalItemTexture globalItemTexture;

indicatorBar::indicatorBar():maxUnit(100), currentUnit(100), bar(){
  bar.setFillColor(Color::Magenta);
  sprite.setTexture(globalItemTexture());
  sprite.setTextureRect(IntRect(384, 672, 32, 32));
  sprite.scale(0.5f, 0.5f);
}

bool indicatorBar::ReduceByVal(float val)
{
  if (!currentUnit)return false;
  currentUnit = currentUnit < val ? 0 : (currentUnit - val);
  return true;
}

void indicatorBar::HealBar(float val)
{
  currentUnit = currentUnit + val > maxUnit ? maxUnit : currentUnit + val;
}

void indicatorBar::Draw(RenderWindow& window)
{
  window.draw(bar);
  window.draw(sprite);
}

void indicatorBar::UpdateBar(Coord pos)
{
  sprite.setPosition(pos.x - 10, pos.y-10);
  bar.setPosition(pos.x, pos.y);
  bar.setSize(Vector2f(currentUnit, 5));
}
