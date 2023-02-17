#pragma once
#include "LEVEL.h"
class TITLE :
    public LEVEL
{
public:
    TITLE(class GAME* game);
    ~TITLE();
    void proc();
};

