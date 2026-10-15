#pragma once

#include "raylib.h"

struct Player3D{
    void update();
    Camera getCamera() const;

private:
    Camera3D m_camera = {
        {0.0f, 0.5f, 0.0f},
        {0.0f, 0.5f, -1.0f},
        {0.0f, 1.0f, 0.0f},
        60.0f, CAMERA_PERSPECTIVE
    };
    float m_yaw = 0.0f;
    float m_pitch = 0.0f;
    static constexpr float m_speed = 5.0f;
    static constexpr float m_sensitivity = 0.01f;
};
