#pragma once

#include "Button.h"
#include "Screen.h"

struct Death{
    Button restart;
    Button menu;
    
    void init();
    void update(Screen& currentScreen);
    void draw();
};
