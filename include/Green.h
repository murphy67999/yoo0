#pragma once

#include "Gun.h"

struct Green{
	float radius = 50.0f;
	float speed = 200.0f;
	bool isAlive = true;
	Color color = GREEN;

	Vector2 pos;
	Gun gun;
};