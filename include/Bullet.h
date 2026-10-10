#pragma once

#include "raylib.h"

struct Bullet{
	float radius = 10.0f;
	float speed = 500.0f;
	Color color = BLACK;
	bool isAlive = true;

	Vector2 pos;
	Vector2 dir;

	void update();
};