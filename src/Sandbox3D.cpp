#include "Sandbox3D.h"

#include "raylib.h"
#include "Scene.h"

void Sandbox3D::update(Scene& currentScene){
    player.update();

    if (IsKeyPressed(KEY_Z)){
        EnableCursor();
        currentScene = MENU;
    }
}

void Sandbox3D::draw(){
    ClearBackground(DARKGRAY);

    BeginMode3D(player.camera);

    BeginShaderMode(gradient);
    DrawCube(
        {0.0f, 0.0f, 0.0f}, 
        0.5f, 0.5f, 0.5f,
        WHITE
    );
    EndShaderMode();

    DrawGrid(100, 0.5f);

    EndMode3D();
    
    int fps = GetFPS();
    DrawText(TextFormat("FPS %d", fps), 10, 10, 50, RAYWHITE);
}