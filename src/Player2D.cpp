#include "raylib.h"

#include "Player2D.h"

void Player2D::update(){
	float dt = GetFrameTime();

	if (IsKeyDown(KEY_W)) m_pos.y -= m_speed * dt;
	if (IsKeyDown(KEY_S)) m_pos.y += m_speed * dt;
	if (IsKeyDown(KEY_A)) m_pos.x -= m_speed * dt;
	if (IsKeyDown(KEY_D)) m_pos.x += m_speed * dt;

	gun.update(m_pos, GetMousePosition());
}

void Player2D::draw() const{
	DrawCircleV(m_pos, m_radius, m_color);
	gun.draw();
}

Vector2 Player2D::getPos() const{
	return m_pos;
}

float Player2D::getRadius() const{
	return m_radius;
}

void Player2D::reset(){
	m_pos = m_spawnPos;
}