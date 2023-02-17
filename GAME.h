#pragma once
#include <vector>
#include "levelFactory.h"
class GAME
{
public:
	GAME();
	~GAME();
	void run();
	void setNextLevelId(LEVEL_ID nextLevelId) { NextLevelId = nextLevelId; }
	bool currentLevelIsTitle() { return CurrentLevelId == TITLE_ID; }
private:
	LEVEL_ID CurrentLevelId;
	LEVEL_ID NextLevelId;
	class LEVEL* Level = nullptr;
	class TRANSITION_EFFECT* Transition = nullptr;

//ï°êîÇÃÉåÉxÉãÇ≈égópÇ∑ÇÈActor
public:
	void addActor(class ACTOR* actor);
	void initActors();
	void updateActors();
	void drawActors();
private:
	std::vector<class ACTOR*>Actors;
};

