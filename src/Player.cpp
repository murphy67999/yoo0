#include "Player.h"

void Player::update(){
	float dt = GetFrameTime();

	if (IsKeyDown(KEY_D)) pos.x += speed * dt;
	if (IsKeyDown(KEY_A)) pos.x -= speed * dt;
	if (IsKeyDown(KEY_W)) pos.y -= speed * dt;
	if (IsKeyDown(KEY_S)) pos.y += speed * dt;
}