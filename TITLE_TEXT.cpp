#include "graphic.h"
#include "window.h"
#include "rand.h"
#include "mathUtil.h"
#include "GAME.h"
#include "TITLE_TEXT.h"
TITLE_TEXT::TITLE_TEXT(class GAME* game)
	:ACTOR(game)
{
	Str = "ê·çë";
	Size = 800;
	R = 255;
	G = 255;
	B = 255;
	A = 255;
	Px = 200;
	Py = 900;
}
TITLE_TEXT::~TITLE_TEXT()
{
}
void TITLE_TEXT::init()
{
}
void TITLE_TEXT::update()
{
}
void TITLE_TEXT::draw()
{
	textSize(Size);
	fill(R, G, B, 255);
	text(Str, Px, Py);
}
