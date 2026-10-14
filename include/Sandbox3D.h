#pragma once

#include "raylib.h"
#include <vector>

#include "Player3D.h"
#include "Scene.h"

struct Sandbox3D{
    Player3D player;
    Shader gradient = LoadShader(0, "shaders/gradient.frag");

    void update(Scene& currentScene);
    void draw();
};
