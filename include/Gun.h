#pragma once

#include <vector>
#include "raylib.h"

#include "Bullet.h"

struct Gun{
	float radius = 20.0f;
	Color color = BLACK;
	float reloadTime = 1.0f;
	float reloadTimer = 0.0f;
	bool canShoot = true;

	Vector2 pos;

	void update(Vector2 pos1, Vector2 targetPos);
	void shoot(Vector2 target, std::vector<Bullet>& bullets);

private:
	void reload();
};