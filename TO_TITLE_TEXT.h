#pragma once
#include "ACTOR.h"
class TO_TITLE_TEXT :
    public ACTOR
{
public:
	TO_TITLE_TEXT(class GAME* game);
	~TO_TITLE_TEXT();
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

