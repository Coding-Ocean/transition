#pragma once
class ACTOR
{
public:
	ACTOR(class GAME* game) :Game(game) {}
	virtual ~ACTOR(){}
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	class GAME* game() { return Game; }
private:
	class GAME* Game = nullptr;
};

