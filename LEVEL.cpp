#include "ACTOR.h"
#include "LEVEL.h"

LEVEL::LEVEL(GAME* game)
	:Game(game)
{
}

LEVEL::~LEVEL()
{
	for (ACTOR* actor : Actors) {
		delete actor;
	}
}

void LEVEL::AddActor(ACTOR* actor)
{
	Actors.emplace_back(actor);
}

void LEVEL::InitActors()
{
	for (ACTOR* actor : Actors) {
		actor->init();
	}
}

void LEVEL::UpdateActors()
{
	for (ACTOR* actor : Actors) {
		actor->update();
	}
}

void LEVEL::DrawActors()
{
	for (ACTOR* actor : Actors) {
		actor->draw();
	}
}
