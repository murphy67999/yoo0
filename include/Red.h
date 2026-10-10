#pragma once

#include "raylib.h"

struct Red{
	float radius = 50.0f;
	float speed = 250.0f;
	bool isAlive = true;
	Color color = RED;

	Vector2 pos;

	void update(Vector2 playerPos);
};