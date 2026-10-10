#pragma once

#include "raylib.h"
#include "Gun.h"

struct Player{
	Vector2 pos = {1000.0f, 900.0f};
	float radius = 50.0f;
	float speed = 300.0f;
	Color color = YELLOW;

	Gun gun;

	void update();
};