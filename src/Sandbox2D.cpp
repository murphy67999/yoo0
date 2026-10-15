#include "Sandbox2D.h"

#include "Scene.h"

void Sandbox2D::run(Scene& currentScene) const{
    update(currentScene);
    draw();
}

void Sandbox2D::update(Scene& currentScene) const{
    if (IsKeyPressed(KEY_Z)){
        currentScene = MENU;
    }
}

void Sandbox2D::draw() const{
    ClearBackground(m_backgroundColor);

    BeginShaderMode(m_gradient);

    DrawRectangle(
        GetScreenWidth() / 2 - 250,
        GetScreenHeight() / 2 - 250,
        500, 500, WHITE
    );
    
    EndShaderMode();
}