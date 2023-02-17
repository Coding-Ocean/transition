#pragma once
#include <vector>
#include "levelFactory.h"
class LEVEL
{
public:
	LEVEL(class GAME* game);
	virtual ~LEVEL();
	virtual void proc() = 0;
	class GAME* game() { return Game; }
protected:
	std::vector<class ACTOR*> Actors;
	void AddActor(class ACTOR*);
	void InitActors();
	void UpdateActors();
	void DrawActors();
private:
	class GAME* Game = nullptr;
};

