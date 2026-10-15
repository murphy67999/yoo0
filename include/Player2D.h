#pragma once

#include "raylib.h"

#include "Gun.h"

struct Player2D{
	Gun gun;
	void update();
	void draw() const;
	Vector2 getPos() const;
	float getRadius() const;
	void reset();

private:
	Vector2 m_pos = m_spawnPos;
	static constexpr Vector2 m_spawnPos = {1000.0f, 900.0f};
	static constexpr float m_radius = 50.0f;
	static constexpr float m_speed = 300.0f;
	static constexpr Color m_color = YELLOW;
};