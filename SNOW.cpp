#include "window.h"
#include "graphic.h"
#include "input.h"
#include "GAME.h"
#include "SNOW_FLAKE.h"
#include "TO_TITLE_TEXT.h"
#include "SNOW.h"

SNOW::SNOW(GAME* game)
	:LEVEL(game)
{
	hideCursor();

	NumSnowFlakes = 2000;
	for (int i = 0; i < NumSnowFlakes; i++) {
		AddActor(new SNOW_FLAKE(game));
	}
	AddActor(new TO_TITLE_TEXT(game));
}

SNOW::~SNOW()
{
	showCursor();
}

void SNOW::proc()
{
	game()->updateActors();
	UpdateActors();

	clear(60, 120, 240);
	game()->drawActors();
	DrawActors();

	if (isTrigger(KEY_SPACE)) {
		game()->setNextLevelId(LEVEL_FACTORY::TITLE_ID);
	}
}
