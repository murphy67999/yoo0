#include "raylib.h"
#include "raymath.h"

#include "Gun.h"
#include "Bullet.h"

void Gun::update(Vector2 pos1, Vector2 targetPos){
	Vector2 dir = Vector2Subtract(targetPos, pos1);

	if (Vector2Length(dir) > 0.0f){
		dir = Vector2Normalize(dir);
		Vector2 movement = Vector2Scale(dir, 75.0f);
		pos = Vector2Add(pos1, movement);
	}

	reload();
}

void Gun::shoot(Vector2 targetPos, std::vector<Bullet>& bullets){
	if (!canShoot) return;

	canShoot = false;

	Bullet bullet;
	bullet.pos = pos;

	Vector2 dir = Vector2Subtract(targetPos, bullet.pos);
	dir = Vector2Normalize(dir);

	bullet.dir = dir;
	bullets.push_back(bullet);	
}

void Gun::reload(){
	if (canShoot) return;

	reloadTimer += GetFrameTime();

	if (reloadTimer >= reloadTime){
		canShoot = true;
		reloadTimer = 0.0f;
	}
}