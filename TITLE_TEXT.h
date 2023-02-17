#pragma once
#include "ACTOR.h"
class TITLE_TEXT :
    public ACTOR
{
public:
	TITLE_TEXT(class GAME* game);
	~TITLE_TEXT();
	void init();
	void update();
	void draw();
private:
	const char* Str;
	float Size;
	float R, G, B, A;
	float Px, Py;
	float Theta;
};

