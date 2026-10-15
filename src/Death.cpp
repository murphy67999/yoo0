#include "Death.h"
#include "Scene.h"

Death::Death():
m_restart(
    {GetScreenWidth() / 2.0f - 150, 500.0f},
    {300, 100},
    {52, 58, 64, 255},
    "RESTART", 50, RAYWHITE
),
m_menu(
    {GetScreenWidth() / 2.0f - 150, 650.0f},
    {300, 100},
    {52, 58, 64, 255},
    "MENU", 50, RAYWHITE
)
{}

void Death::run(Scene& currentScene) const{
    update(currentScene);
    draw();
}

void Death::update(Scene& currentScene) const{
    if (m_restart.isButtonClicked()){
        currentScene = GAME_2D;
    }

    if (m_menu.isButtonClicked()){
        currentScene = MENU;
    }
}

void Death::draw() const{
    ClearBackground(m_backgroundColor);

    m_restart.draw();
    m_menu.draw();
}