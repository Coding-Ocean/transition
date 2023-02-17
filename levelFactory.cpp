#include "GAME.h"
#include "SNOW.h"
#include "TITLE.h"
#include "levelFactory.h"

LEVEL* levelFactory(LEVEL_ID id, GAME* game)
{
	if (id == SNOW_ID)return new SNOW(game);
	if (id == TITLE_ID)return new TITLE(game);
	return nullptr;
}