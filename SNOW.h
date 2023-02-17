#pragma once
#include "LEVEL.h"
class SNOW :
    public LEVEL
{
public:
    SNOW(class GAME* game);
    ~SNOW();
    void proc();
private:
    int NumSnowFlakes;
};

