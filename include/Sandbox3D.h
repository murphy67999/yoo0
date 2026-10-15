#pragma once

#include "raylib.h"
#include <vector>

#include "Player3D.h"
#include "Scene.h"

struct Sandbox3D{
    void run(Scene& currentScene);

private:
    static constexpr Color m_backgroundColor = SKYBLUE;
    Player3D m_player;
    const Shader m_gradient = LoadShader(0, "shaders/gradient.frag");

    void update(Scene& currentScene);
    void draw() const;
};
