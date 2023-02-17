#include "graphic.h"
#include "window.h"
#include "rand.h"
#include "mathUtil.h"
#include "GAME.h"
#include "TO_TITLE_TEXT.h"
TO_TITLE_TEXT::TO_TITLE_TEXT(class GAME* game)
	:ACTOR(game)
{
	Str = "スペースキーでタイトルへ";
	Size = 50;
	R = 255;
	G = 255;
	B = 255;
	A = 255;
	Theta = 0;
	MinAlpha = 100;
	//中央に表示する位置
	Px = (width - strlen(Str) * Size / 2) / 2;
	Py = 1000;
}
TO_TITLE_TEXT::~TO_TITLE_TEXT()
{
}
void TO_TITLE_TEXT::init()
{
}
void TO_TITLE_TEXT::update()
{
	angleMode(DEGREES);
	float from1to0 = Cos(Theta) * 0.5f + 0.5f;
	A = MinAlpha + (255 - MinAlpha) * from1to0;
	Theta += 60 * delta;
}
void TO_TITLE_TEXT::draw()
{
	textSize(Size);
	fill(R, G, B, A);
	text(Str, Px, Py);
}
