#pragma once

#include "raylib.h"

struct Player3D{
    Camera3D camera = {
        {0.0f, 0.5f, 0.0f},
        {0.0f, 0.5f, -1.0f},
        {0.0f, 1.0f, 0.0f},
        60.0f, CAMERA_PERSPECTIVE
    };
    float speed = 5.0f;
    float yaw = 0.0f;
    float pitch = 0.0f;
    float sensitivity = 0.01f;

    void update();
};
