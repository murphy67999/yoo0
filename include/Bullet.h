#pragma once

#include "raylib.h"

struct Bullet{
	bool isAlive = true;

	Bullet(Vector2 pos, Vector2 target);
	void update();
	void draw() const;
	bool checkHit(Vector2 targetPos, float targetRadius) const;

private:
	Vector2 m_pos;
	Vector2 m_target;
	Vector2 m_dir;
	static constexpr float m_radius = 10.0f;
	static constexpr float m_speed = 500.0f;
	static constexpr Color m_color = BLACK;
};