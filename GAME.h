#pragma once
#include <vector>
#include "LEVEL_FACTORY.h"
class GAME
{
public:
	GAME();
	~GAME();
	void run();
	void setNextLevelId(LEVEL_FACTORY::LEVEL_ID nextLevelId) { NextLevelId = nextLevelId; }
	bool currentLevelIsTitle() { return CurrentLevelId == LEVEL_FACTORY::TITLE_ID; }
private:
	//���x���̃V���v���t�@�N�g��
	class LEVEL_FACTORY* LevelFactory = nullptr;
	//���ݎ��s���̃��x��ID
	LEVEL_FACTORY::LEVEL_ID CurrentLevelId;
	//���Ɏ��s�\��̃��x��ID
	LEVEL_FACTORY::LEVEL_ID NextLevelId;
	//���s���̃��x��
	class LEVEL* Level = nullptr;
	//�؂�ւ�����
	class TRANSITION_EFFECT* Transition = nullptr;

public:
	//�����̃��x���Ŏg�p����Actor
	void addActor(class ACTOR* actor);
	void initActors();
	void updateActors();
	void drawActors();
private:
	std::vector<class ACTOR*>Actors;
};

