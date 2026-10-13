#include "Death.h"
#include "Scene.h"

Death::Death():
restart(
    {GetScreenWidth() / 2.0f - 150, GetScreenHeight() / 2.0f - 50.0f},
    {300, 100},
    {52, 58, 64, 255},
    "RESTART", 50, RAYWHITE
),
menu(
    {GetScreenWidth() / 2.0f - 150, (GetScreenHeight() / 2.0f - 50.0f) + 150.0f},
    {300, 100},
    {52, 58, 64, 255},
    "MENU", 50, RAYWHITE
)
{}

void Death::update(Scene& currentScene){
    if (restart.isButtonClicked()){
        currentScene = GAME_2D;
    }

    if (menu.isButtonClicked()){
        currentScene = MENU;
    }
}

void Death::draw(){
    ClearBackground({232, 224, 240, 255});

    restart.draw();
    menu.draw();
}