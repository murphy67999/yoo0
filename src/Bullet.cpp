#include "Bullet.h"
#include "raymath.h"

Bullet::Bullet(Vector2 pos, Vector2 target)
: m_pos(pos), m_target(target) {
	Vector2 dir = Vector2Subtract(target, pos);
	m_dir = Vector2Normalize(dir);
}

void Bullet::update(){
	Vector2 movement = Vector2Scale(m_dir, m_speed * GetFrameTime());
	m_pos = Vector2Add(m_pos, movement);	
}

void Bullet::draw() const{
	DrawCircleV(m_pos, m_radius, m_color);
}

bool Bullet::checkHit(Vector2 targetPos, float targetRadius) const{
	return CheckCollisionCircles(
		m_pos, m_radius, targetPos, targetRadius
	);
}
