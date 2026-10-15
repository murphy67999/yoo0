#include <cmath>

#include "Player3D.h"
#include "raylib.h"

void Player3D::update(){
    Vector2 mouseDelta = GetMouseDelta();

    m_yaw -= mouseDelta.x * m_sensitivity;
    m_pitch -= mouseDelta.y * m_sensitivity;

    if (m_pitch > 1.5f) m_pitch = 1.5f;
    if (m_pitch < -1.5f) m_pitch = -1.5f;

    float moveSpeed = m_speed * GetFrameTime();

    Vector3 forward = {
        cosf(m_pitch) * sinf(m_yaw),
        sinf(m_pitch),
        cosf(m_pitch) * cosf(m_yaw)
    };

    Vector3 right = {
        -cosf(m_yaw),
        0.0f,
        sinf(m_yaw)
    };

    if (IsKeyDown(KEY_W)) {
        m_camera.position.x += forward.x * moveSpeed;
        m_camera.position.y += forward.y * moveSpeed;
        m_camera.position.z += forward.z * moveSpeed;
    }

    if (IsKeyDown(KEY_S)) {
        m_camera.position.x -= forward.x * moveSpeed;
        m_camera.position.y -= forward.y * moveSpeed;
        m_camera.position.z -= forward.z * moveSpeed;
    }

    if (IsKeyDown(KEY_D)) {
        m_camera.position.x += right.x * moveSpeed;
        m_camera.position.z += right.z * moveSpeed;
    }

    if (IsKeyDown(KEY_A)) {
        m_camera.position.x -= right.x * moveSpeed;
        m_camera.position.z -= right.z * moveSpeed;
    }

    Vector3 direction = {
        cosf(m_pitch) * sinf(m_yaw),
        sinf(m_pitch),
        cosf(m_pitch) * cosf(m_yaw)
    };

    m_camera.target = {
        m_camera.position.x + direction.x,
        m_camera.position.y + direction.y,
        m_camera.position.z + direction.z
    };

    DisableCursor();
}

Camera Player3D::getCamera() const{
    return m_camera;
}