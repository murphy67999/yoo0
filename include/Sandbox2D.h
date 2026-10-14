#pragma once

#include "raylib.h"

#include "Scene.h"

struct Sandbox2D{
    Shader gradient = LoadShader(0, "shaders/gradient.frag");

    void update(Scene& currentScene);
    void draw();
};
