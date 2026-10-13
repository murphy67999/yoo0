#pragma once

#include "Button.h"
#include "Scene.h"

struct Menu{
	Button twoDimension;
    Button threeDimenion;
    Button exit;

    Menu();
    void update(Scene& currentScene);
    void draw();
};
