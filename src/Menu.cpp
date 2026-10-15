#include "raylib.h"

#include "Menu.h"
#include "Scene.h"

Vector2 size = {500.0f, 100.0f};

Menu::Menu():
m_game2D(
    {GetScreenWidth() / 2.0f - size.x / 2.0f, 350.0f},
    size,
    {0, 200, 83, 255},
    "2D GAME", 70, BLACK
),
m_sandbox2D(
    {GetScreenWidth() / 2.0f - size.x / 2.0f, 500.0f},
    size,
    {0, 200, 83, 255},
    "2D SANDBOX", 70, BLACK
),
m_sandbox3D(
    {GetScreenWidth() / 2.0f - size.x / 2.0f, 650.0f},
    size,
    {0, 200, 83, 255},
    "3D SANDBOX", 70, BLACK
),
m_exit(
    {GetScreenWidth() / 2.0f - 100.0f, 800.0f},
    {200, 100},
    {0, 200, 83, 255},
    "EXIT", 70, BLACK
)
{}

void Menu::run(Scene& currentScene) const{
    update(currentScene);
    draw();
}

void Menu::update(Scene& currentScene) const{
    if (m_game2D.isButtonClicked()){
        currentScene = GAME_2D;
    }
    if (m_sandbox2D.isButtonClicked()){
        currentScene = SANDBOX_2D;
    }
    if (m_sandbox3D.isButtonClicked()){
        currentScene = SANDBOX_3D;
    }
    if (m_exit.isButtonClicked()){
        currentScene = EXIT;
    }
}

void Menu::draw() const{
    ClearBackground(m_backgroundColor);

    drawTitle();
    m_game2D.draw();
    m_sandbox2D.draw();
    m_sandbox3D.draw();
    m_exit.draw();
}

void Menu::drawTitle() const{
    const char* title = "Yoo0";
    int width = MeasureText(title, 100);
    int posX = GetScreenWidth() / 2 - width / 2;
    DrawText(title, posX, 200, 100, WHITE);
}