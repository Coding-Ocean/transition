#include "framework.h"
#include "window.h"
#include "graphic.h"
#include "input.h"
#include "PLAYER.h"
#include "LEVEL.h"
#include "TRANSITION_EFFECT.h"
#include "GAME.h"
GAME::GAME()
{
	window(1920, 1080, full);

	addActor(new PLAYER(this));

	CurrentLevelId = NextLevelId = TITLE_ID;
	Level = levelFactory(CurrentLevelId, this);

	Transition = new TRANSITION_EFFECT;
	Transition->setTime(6);

	initDeltaTime();
}

GAME::~GAME()
{
	for (ACTOR* actor : Actors) {
		delete actor;
	}
	delete Level;
	delete Transition;
}

void GAME::run()
{
	while (notQuit) {

		setDeltaTime();
		Level->proc();
		Transition->proc();

#ifdef _DEBUG
		fill(255);
		print((let)"deltaTime=" + delta);
#endif
		if (CurrentLevelId == NextLevelId) {
			continue;
		}
		//LevelØ‚è‘Ö‚¦
		Transition->outStart();
		if (Transition->outEndFlag()) {
			delete Level;
			CurrentLevelId = NextLevelId;
			Level = levelFactory(CurrentLevelId, this);
			Transition->inStart();
		}
	}
}

//•¡”‚ÌƒŒƒxƒ‹‚Åg—p‚·‚éActor
void GAME::addActor(ACTOR* actor)
{
	Actors.emplace_back(actor);
}

void GAME::initActors()
{
	for (ACTOR* actor : Actors) {
		actor->init();
	}
}

void GAME::updateActors()
{
	for (ACTOR* actor : Actors) {
		actor->update();
	}
}

void GAME::drawActors()
{
	for (ACTOR* actor : Actors) {
		actor->draw();
	}
}
