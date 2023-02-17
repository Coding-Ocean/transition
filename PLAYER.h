#pragma once
#include "ACTOR.h"
class PLAYER :
    public ACTOR
{
public:
    PLAYER(class GAME* game);
    ~PLAYER();
    void init();
    void update();
    void draw();
private:
    int Img;
    float Px, Py;
    float Vx, Vy;
    float InitActorsPx, InitActorsPy;
};

