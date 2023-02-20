#include "GAME.h"
#include "SNOW.h"
#include "TITLE.h"
#include "LEVEL_FACTORY.h"

LEVEL_FACTORY::LEVEL_FACTORY(GAME* game):Game(game){}

LEVEL_FACTORY::~LEVEL_FACTORY(){Game = nullptr;}

LEVEL* LEVEL_FACTORY::create(LEVEL_ID id)
{
	if (id == SNOW_ID)return new SNOW(Game);
	if (id == TITLE_ID)return new TITLE(Game);
	return nullptr;
}
