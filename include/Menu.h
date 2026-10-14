#pragma once

#include "Button.h"
#include "Scene.h"

struct Menu{
    Menu();
    void run(Scene& currentScene) const;

private:
	Button m_game2D;
    Button m_sandbox2D;
    Button m_sandbox3D;
    Button m_exit;

    void update(Scene& currentScene) const;
    void draw() const;
    void drawTitle() const;
};
