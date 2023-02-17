#pragma once
#include "ACTOR.h"
class SNOW_FLAKE :
	public ACTOR
{
public:
	SNOW_FLAKE(class GAME* game);
	~SNOW_FLAKE();
	void init();
	void update();
	void draw();
private:
	int Img;
	float Px, Py, Vx, Vy, Size;
};

