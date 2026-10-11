#include "raylib.h"

#include "Menu.h"
#include "Screen.h"

void Menu::init(){
    play.size = {200, 100};
    play.pos = {
        GetScreenWidth() / 2.0f - play.size.x / 2.0f,
        GetScreenHeight() / 2.0f - play.size.y / 2.0f
    };
    play.color = {0, 200, 83, 255};
    play.text = "PLAY";
    play.fontSize = 70;
    play.textColor = BLACK;


    exit.size = {200, 100};
    exit.pos = {
        GetScreenWidth() / 2.0f - play.size.x / 2.0f,
        (GetScreenHeight() / 2.0f - play.size.y / 2.0f) + 150.0f
    };
    exit.color = {0, 200, 83, 255};
    exit.text = "EXIT";
    exit.fontSize = 70;
    exit.textColor = BLACK;
}

void Menu::update(Screen& currentScreen){
    if (play.isButtonClicked()){
        currentScreen = GAME;
    }
    if (exit.isButtonClicked()){
        currentScreen = EXIT;
    }
}

void Menu::draw(){
    ClearBackground(PURPLE);

    const char* title = "Yoo0";
    int width = MeasureText(title, 100);
    int posX = GetScreenWidth() / 2 - width / 2;
    DrawText(title, posX, 200, 100, WHITE);

    play.draw();
    exit.draw();
}