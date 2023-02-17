#include "graphic.h"
#include "input.h"
#include "GAME.h"
#include "PLAYER.h"

PLAYER::PLAYER(GAME* game)
	:ACTOR(game)
{
	Img = loadImage("assets\\snowman.png");
	Px = InitActorsPx = 1500;
	Py = InitActorsPy = 540;
	Vx = 10;
	Vy = 10;
}

PLAYER::~PLAYER()
{
}

void PLAYER::init()
{
	Px = InitActorsPx;
	Py = InitActorsPy;
}

void PLAYER::update()
{
	if (game()->currentLevelIsTitle())
		return;

	if (isPress(KEY_A)) {
		Px -= Vx;
	}
	else if (isPress(KEY_D)) {
		Px += Vx;
	}
}

void PLAYER::draw()
{
	rectMode(CORNER);
	image(Img, Px, Py);
}
