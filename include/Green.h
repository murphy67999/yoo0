#pragma once

#include "Gun.h"

struct Green{
	Gun gun;
	bool isAlive = true;

	Green(Vector2 pos);
	void draw() const;
	Vector2 getPos() const;
	float getRadius() const;

private:
	Vector2 m_pos;
	static constexpr float m_radius = 50.0f;
	static constexpr float m_speed = 200.0f;
	static constexpr Color m_color = GREEN;
};