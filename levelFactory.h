#pragma once
enum LEVEL_ID{
	SNOW_ID,
	TITLE_ID
};
class LEVEL* levelFactory(LEVEL_ID id, class GAME* game);
