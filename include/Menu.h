#pragma once

#include "Button.h"
#include "Screen.h"

struct Menu{
	Button play;

    void init();
    void update(Screen& currentScreen);
    void draw();
};
