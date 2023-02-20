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

	//�X�^�[�g���̃��x��������
	LevelFactory = new LEVEL_FACTORY(this);
	CurrentLevelId = NextLevelId = LEVEL_FACTORY::TITLE_ID;
	Level = LevelFactory->create(CurrentLevelId);

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
		//Level->proc()���Ń��x����؂�ւ��Ă��Ȃ�
		if (CurrentLevelId == NextLevelId) {
			continue;
		}
		//Level->proc()���Ń��x����؂�ւ����������ɗ���
		Transition->outStart();
		//��ʐ؂�ւ����ʏI����ALevel�؂�ւ�
		if (Transition->outEndFlag()) {
			delete Level;
			CurrentLevelId = NextLevelId;
			Level = LevelFactory->create(CurrentLevelId);
			Transition->inStart();
		}
	}
}

//�����̃��x���Ŏg�p����Actor
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
