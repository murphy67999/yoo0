#include "Game3D.h"

#include "raylib.h"
#include "Scene.h"

void Game3D::update(Scene& currentScene){
    player.update();

    if (IsKeyPressed(KEY_Z)){
        EnableCursor();
        currentScene = MENU;
    }
}

void Game3D::draw(){
    ClearBackground(DARKGRAY);

    BeginMode3D(player.camera);

    BeginShaderMode(shader);

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