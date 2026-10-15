#include "Sandbox2D.h"

#include "Scene.h"

void Sandbox2D::run(Scene& currentScene){
    update(currentScene);
    draw();
}

void Sandbox2D::update(Scene& currentScene){
    if (IsKeyPressed(KEY_Z)){
        currentScene = MENU;
    }

    m_rotation += 0.1f;
}

void Sandbox2D::draw() const{
    ClearBackground(m_backgroundColor);

    BeginShaderMode(m_gradient);

    Rectangle rect = {900, 500, 600, 600};
    Vector2 origin = {rect.width / 2.0f, rect.height / 2.0f};
    DrawRectanglePro(rect, origin, m_rotation, RED);

    EndShaderMode();
}