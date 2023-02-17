#include "graphic.h"
#include "window.h"
#include "rand.h"
#include "mathUtil.h"
#include "GAME.h"
#include "TO_SNOW_TEXT.h"
TO_SNOW_TEXT::TO_SNOW_TEXT(class GAME* game)
	:ACTOR(game)
{
	Str = "スペースキーで雪国へ";
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
TO_SNOW_TEXT::~TO_SNOW_TEXT()
{
}
void TO_SNOW_TEXT::init()
{
}
void TO_SNOW_TEXT::update()
{
	angleMode(DEGREES);
	float from1to0 = Cos(Theta) * 0.5f + 0.5f;
	A = MinAlpha + (255 - MinAlpha) * from1to0;
	Theta += 60 * delta;
}
void TO_SNOW_TEXT::draw()
{
	textSize(Size);
	fill(R, G, B, A);
	text(Str, Px, Py);
}
