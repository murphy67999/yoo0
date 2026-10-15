#pragma once

#include "raylib.h"

struct Red{
	bool isAlive = true;

	Red(Vector2 pos);
	void update(Vector2 target);
	void draw() const;
	Vector2 getPos() const;
	float getRadius() const;

private:
	static constexpr float m_radius = 50.0f;
	static constexpr float m_speed = 250.0f;
	static constexpr Color m_color = RED;
	Vector2 m_pos;
};