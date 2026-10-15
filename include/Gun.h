#pragma once

#include <vector>
#include "raylib.h"

#include "Bullet.h"

struct Gun{
	void update(Vector2 pos, Vector2 targetPos);
	Bullet shoot(Vector2 target);
	bool canShoot() const;
	Vector2 getPos() const;
	float getRadius() const;
	Color getColor() const;
	void draw() const;

private:
	Vector2 m_pos;
	bool m_canShoot = true;
	float m_reloadTimer = 0.0f;
	static constexpr float m_radius = 20.0f;
	static constexpr Color m_color = BLACK;
	static constexpr float m_reloadTime = 1.0f;

	void reload();
};