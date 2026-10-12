#include "Death.h"
#include "Screen.h"

void Death::init(){
    restart.size = {300, 100};
    restart.pos = {
        GetScreenWidth() / 2.0f - restart.size.x / 2.0f,
        GetScreenHeight() / 2.0f - restart.size.y / 2.0f
    };
    restart.color = {52, 58, 64, 255};
    restart.text = "RESTART";
    restart.fontSize = 50;
    restart.textColor = RAYWHITE;

    menu.size = {300, 100};
    menu.pos = {
        GetScreenWidth() / 2.0f - menu.size.x / 2.0f,
        (GetScreenHeight() / 2.0f - menu.size.y / 2.0f) + 150.0f
    };
    menu.color = {52, 58, 64, 255};
    menu.text = "MENU";
    menu.fontSize = 50;
    menu.textColor = RAYWHITE;
}

void Death::update(Screen& currentScreen){
    if (restart.isButtonClicked()){
        currentScreen = GAME;
    }

    if (menu.isButtonClicked()){
        currentScreen = MENU;
    }
}

void Death::draw(){
    ClearBackground({232, 224, 240, 255});

    restart.draw();
    menu.draw();
}