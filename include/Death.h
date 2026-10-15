#pragma once

#include "Button.h"
#include "Scene.h"

struct Death{
    Death();
    void run(Scene& currentScene) const;

private:
    const Button m_restart;
    const Button m_menu;
    static constexpr Color m_backgroundColor = {232, 224, 240, 255};

    void update(Scene& currentScene) const;
    void draw() const;
};
