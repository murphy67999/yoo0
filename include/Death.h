#pragma once

#include "Button.h"
#include "Scene.h"

struct Death{
    Button restart;
    Button menu;
    
    Death();
    void update(Scene& currentScene);
    void draw();
};
