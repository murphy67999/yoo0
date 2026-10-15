#pragma once

#include "Button.h"
#include "Scene.h"

struct Menu{
    Menu();
    void run(Scene& currentScene) const;

private:
    static constexpr Color m_backgroundColor = PURPLE;
	const Button m_game2D;
    const Button m_sandbox2D;
    const Button m_sandbox3D;
    const Button m_exit;

    void update(Scene& currentScene) const;
    void draw() const;
    void drawTitle() const;
};
