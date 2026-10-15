#pragma once

#include "raylib.h"

#include "Scene.h"

struct Sandbox2D{
    void run(Scene& currentScene) const;

private:
    static constexpr Color m_backgroundColor = PURPLE;
    const Shader m_gradient = LoadShader(0, "shaders/gradient.frag");

    void update(Scene& currentScene) const;
    void draw() const;
};
