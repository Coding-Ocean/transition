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
	//レベルのシンプルファクトリ
	class LEVEL_FACTORY* LevelFactory = nullptr;
	//現在実行中のレベルID
	LEVEL_FACTORY::LEVEL_ID CurrentLevelId;
	//次に実行予定のレベルID
	LEVEL_FACTORY::LEVEL_ID NextLevelId;
	//実行中のレベル
	class LEVEL* Level = nullptr;
	//切り替え効果
	class TRANSITION_EFFECT* Transition = nullptr;

public:
	//複数のレベルで使用するActor
	void addActor(class ACTOR* actor);
	void initActors();
	void updateActors();
	void drawActors();
private:
	std::vector<class ACTOR*>Actors;
};

