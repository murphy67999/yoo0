#include "Red.h"

#include "raymath.h"

void Red::update(Vector2 playerPos){
	Vector2 dir = Vector2Subtract(playerPos, pos);
	dir = Vector2Normalize(dir);
	Vector2 movement = Vector2Scale(dir, speed * GetFrameTime());
	pos = Vector2Add(pos, movement);
}
