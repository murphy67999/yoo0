#pragma once

#include "raylib.h"
#include <vector>

#include "Player3D.h"
#include "Scene.h"

struct Game3D{
    Player3D player;
    Shader shader = LoadShader(0, "shaders/example.fs");

    void update(Scene& currentScene);
    void draw();
};
