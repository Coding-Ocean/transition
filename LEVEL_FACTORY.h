#pragma once
class LEVEL_FACTORY
{
public:
	enum LEVEL_ID {
		SNOW_ID,
		TITLE_ID
	};
	LEVEL_FACTORY(class GAME* game);
	~LEVEL_FACTORY();
	class LEVEL* create(LEVEL_ID id);
private:
	class GAME* Game;
};