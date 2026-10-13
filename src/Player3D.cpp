#include <cmath>

#include "Player3D.h"
#include "raylib.h"

void Player3D::update(){
    Vector2 mouseDelta = GetMouseDelta();

    yaw -= mouseDelta.x * sensitivity;
    pitch -= mouseDelta.y * sensitivity;

    if (pitch > 1.5f) pitch = 1.5f;
    if (pitch < -1.5f) pitch = -1.5f;

    float moveSpeed = speed * GetFrameTime();

    Vector3 forward = {
        sinf(yaw),
        0.0f,
        cosf(yaw)
    };
    Vector3 right = {
        -cosf(yaw),
        0.0f,
        sinf(yaw)
    };

    if (IsKeyDown(KEY_W)) {
        camera.position.x += forward.x * moveSpeed;
        camera.position.z += forward.z * moveSpeed;
    }

    if (IsKeyDown(KEY_S)) {
        camera.position.x -= forward.x * moveSpeed;
        camera.position.z -= forward.z * moveSpeed;
    }

    if (IsKeyDown(KEY_D)) {
        camera.position.x += right.x * moveSpeed;
        camera.position.z += right.z * moveSpeed;
    }

    if (IsKeyDown(KEY_A)) {
        camera.position.x -= right.x * moveSpeed;
        camera.position.z -= right.z * moveSpeed;
    }

    Vector3 direction = {
        cosf(pitch) * sinf(yaw),
        sinf(pitch),
        cosf(pitch) * cosf(yaw)
    };

    camera.target = {
        camera.position.x + direction.x,
        camera.position.y + direction.y,
        camera.position.z + direction.z
    };

    DisableCursor();
}