#include "Sandbox3D.h"

#include "raylib.h"
#include "Scene.h"

void Sandbox3D::run(Scene& currentScene){
    update(currentScene);
    draw();
}

void Sandbox3D::update(Scene& currentScene){
    m_player.update();

    if (IsKeyPressed(KEY_Z)){
        EnableCursor();
        currentScene = MENU;
    }
}

void Sandbox3D::draw() const{
    ClearBackground(DARKGRAY);

    BeginMode3D(m_player.getCamera());

    BeginShaderMode(m_gradient);
    DrawCube(
        {0.0f, 0.0f, 0.0f}, 
        0.5f, 0.5f, 0.5f,
        WHITE
    );
    EndShaderMode();

    DrawGrid(100, 0.5f);

    EndMode3D();
}