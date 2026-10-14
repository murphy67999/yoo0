#include "Sandbox2D.h"

#include "Scene.h"

void Sandbox2D::update(Scene& currentScene){
    if (IsKeyPressed(KEY_Z)){
        currentScene = MENU;
    }
}

void Sandbox2D::draw(){
    ClearBackground(PURPLE);

    BeginShaderMode(gradient);
    DrawRectangle(
        GetScreenWidth() / 2 - 250,
        GetScreenHeight() / 2 - 250,
        500, 500, WHITE
    );
    EndShaderMode();
}