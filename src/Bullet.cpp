#include "Bullet.h"
#include "raymath.h"

void Bullet::update(){
	Vector2 movement = Vector2Scale(dir, speed * GetFrameTime());
	pos = Vector2Add(pos, movement);	
}
