#include "Red.h"

#include "raymath.h"

Red::Red(Vector2 pos)
: m_pos(pos) {}

void Red::update(Vector2 target){
	Vector2 dir = Vector2Subtract(target, m_pos);
	dir = Vector2Normalize(dir);
	Vector2 movement = Vector2Scale(dir, m_speed * GetFrameTime());
	m_pos = Vector2Add(m_pos, movement);
}

void Red::draw() const{
	DrawCircleV(m_pos, m_radius, m_color);
}

Vector2 Red::getPos() const{
	return m_pos;
}

float Red::getRadius() const{
	return m_radius;
}