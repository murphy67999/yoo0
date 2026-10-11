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
}

void Death::update(Screen& currentScreen){
    if (restart.isButtonClicked()){
        currentScreen = GAME;
    }
}

void Death::draw(){
    ClearBackground({232, 224, 240, 255});

    restart.draw();
}