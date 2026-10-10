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
}

void Menu::update(Screen& currentScreen){
    if (play.isButtonClicked()){
        currentScreen = GAME;
    }
}

void Menu::draw(){
    DrawRectangleV(play.pos, play.size, play.color);
    DrawText(play.text, play.getTextPosX(), play.getTextPosY(), play.fontSize, play.textColor);
}