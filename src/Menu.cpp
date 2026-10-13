#include "raylib.h"

#include "Menu.h"
#include "Scene.h"

Menu::Menu():
twoDimension(
    {GetScreenWidth() / 2.0f - 100.0f, GetScreenHeight() / 2.0f - 50.0f},
    {200, 100},
    {0, 200, 83, 255},
    "2D", 70, BLACK
),
threeDimenion(
    {GetScreenWidth() / 2.0f - 100.0f, (GetScreenHeight() / 2.0f - 50.0f) + 150.0f},
    {200, 100},
    {0, 200, 83, 255},
    "3D", 70, BLACK
),
exit(
    {GetScreenWidth() / 2.0f - 100.0f, (GetScreenHeight() / 2.0f - 50.0f) + 300.0f},
    {200, 100},
    {0, 200, 83, 255},
    "EXIT", 70, BLACK
)
{}

void Menu::update(Scene& currentScene){
    if (twoDimension.isButtonClicked()){
        currentScene = GAME_2D;
    }
    if (threeDimenion.isButtonClicked()){
        currentScene = GAME_3D;
    }
    if (exit.isButtonClicked()){
        currentScene = EXIT;
    }
}

void Menu::draw(){
    ClearBackground(PURPLE);

    const char* title = "Yoo0";
    int width = MeasureText(title, 100);
    int posX = GetScreenWidth() / 2 - width / 2;
    DrawText(title, posX, 200, 100, WHITE);

    twoDimension.draw();
    threeDimenion.draw();
    exit.draw();
}