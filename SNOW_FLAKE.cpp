#include "graphic.h"
#include "window.h"
#include "rand.h"
#include "GAME.h"
#include "SNOW_FLAKE.h"
SNOW_FLAKE::SNOW_FLAKE(class GAME* game)
	:ACTOR(game)
{
	Img = loadImage("assets\\snowFlake.png");
	Px = random(width);
	Py = random(height);
	Vx = random(-60.0f, 60.0f);
	Vy = random(120.0f, 180.0f);
	Size = random(0.33f, 1.0f);
}
SNOW_FLAKE::~SNOW_FLAKE()
{
}
void SNOW_FLAKE::init()
{
}
void SNOW_FLAKE::update()
{
	Px += Vx * delta;
	Py += Vy * delta;
	if (Px < 0) {
		Px = width;
	}
	if (Px > width) {
		Px = 0;
	}
	if (Py > height) {
		Py = 0;
	}
}
void SNOW_FLAKE::draw()
{
	image(Img, Px, Py, 0, Size);
}
