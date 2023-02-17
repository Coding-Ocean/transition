#include "window.h"
#include "graphic.h"
#include "input.h"
#include "GAME.h"
#include "TITLE_TEXT.h"
#include "TO_SNOW_TEXT.h"
#include "TITLE.h"

TITLE::TITLE(GAME* game)
	:LEVEL(game)
{
	hideCursor();
	
	AddActor(new TITLE_TEXT(game));
	AddActor(new TO_SNOW_TEXT(game));

	InitActors();
	game->initActors();
}

TITLE::~TITLE()
{
	showCursor();
}

void TITLE::proc()
{
	UpdateActors();
	game()->updateActors();
	clear(60);
	DrawActors();
	game()->drawActors();

	if (isTrigger(KEY_SPACE)) {
		game()->setNextLevelId(SNOW_ID);
	}
}
