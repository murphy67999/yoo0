#include "raylib.h"
#include "raymath.h"

#include "Gun.h"
#include "Bullet.h"

void Gun::update(Vector2 pos, Vector2 targetPos){
	Vector2 dir = Vector2Subtract(targetPos, pos);

	if (Vector2Length(dir) > 0.0f){
		dir = Vector2Normalize(dir);
		Vector2 movement = Vector2Scale(dir, 75.0f);
		m_pos = Vector2Add(pos, movement);
	}

	reload();
}

Bullet Gun::shoot(Vector2 target){
	m_canShoot = false;

	return Bullet(m_pos, target);
}

bool Gun::canShoot() const{
	return m_canShoot;
}

Vector2 Gun::getPos() const{
	return m_pos;
}

float Gun::getRadius() const{
	return m_radius;
}

Color Gun::getColor() const{
	return m_color;
}

void Gun::reload(){
	if (m_canShoot) return;

	m_reloadTimer += GetFrameTime();

	if (m_reloadTimer >= m_reloadTime){
		m_canShoot = true;
		m_reloadTimer = 0.0f;
	}
}