#pragma once
#include "ACTOR.h"
class TO_SNOW_TEXT :
    public ACTOR
{
public:
	TO_SNOW_TEXT(class GAME* game);
	~TO_SNOW_TEXT();
	void init();
	void update();
	void draw();
private:
	const char* Str;
	float Size;
	float R, G, B, A;
	float Theta;
	float MinAlpha;
	float Px, Py;
};

