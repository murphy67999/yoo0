#pragma once

#include "raylib.h"

#include "Scene.h"

struct Sandbox2D{
    void run(Scene& currentScene);

private:
    static constexpr Color m_backgroundColor = PURPLE;
    const Shader m_gradient = LoadShader(0, "shaders/gradient.frag");
    float m_rotation = 45.0f;

    void update(Scene& currentScene);
    void draw() const;
};
