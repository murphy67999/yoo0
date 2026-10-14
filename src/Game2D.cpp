#include "raylib.h"
#include "raymath.h"
#include <iostream>

#include "Game2D.h"
#include "Gun.h"
#include "Scene.h"

Game2D::Game2D(){
	m_player.gun = Gun();
}

void Game2D::run(Scene& currentScene){
	update(currentScene);
	draw();
}

void Game2D::update(Scene& currentScene){
	m_player.update();
	m_player.gun.update(m_player.pos, GetMousePosition());

	updateBullets();
	updateEnemies();

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		if (m_player.gun.canShoot()){
			m_bullets.push_back(m_player.gun.shoot(GetMousePosition()));
		}
	}

	if (isPlayerHit()){
		reset();
		currentScene = DEATH;
	}

	if (IsKeyPressed(KEY_Z)){
		reset();
		currentScene = MENU;
	}

	handleEnemySpawning();
	handleEnemyHits();
	removeDeadObjects();
}

void Game2D::draw() const{
	ClearBackground(DARKGRAY);

	DrawCircleV(m_player.pos, m_player.radius, m_player.color);
	DrawCircleV(m_player.gun.getPos(), m_player.gun.getRadius(), m_player.gun.getColor());

	for (Bullet bullet : m_bullets){
		bullet.draw();
	}

	for (Red red : m_redEnemies){
		DrawCircleV(red.pos, red.radius, red.color);
	}

	for (Green green : m_greenEnemies){
		DrawCircleV(green.pos, green.radius, green.color);
		DrawCircleV(green.gun.getPos(), green.gun.getRadius(), green.gun.getColor());
	}

	drawFPS();
}

void Game2D::drawFPS() const{
	int fps = GetFPS();
    DrawText(TextFormat("FPS %d", fps), 10, 10, 50, RAYWHITE);
}

void Game2D::updateBullets(){
	for (Bullet& bullet : m_bullets){
		bullet.update();
	}
}

void Game2D::updateEnemies(){
	for (Red& red : m_redEnemies){
		red.update(m_player.pos);
	}
	for (Green& green : m_greenEnemies){
		green.gun.update(green.pos, m_player.pos);
		if (green.gun.canShoot()){
			m_bullets.push_back(green.gun.shoot(m_player.pos));
		}
	}
}

void Game2D::handleEnemySpawning(){
	m_timer += GetFrameTime();
	if (m_timer >= 2.0f){
		m_timer = 0.0f;
		
		int random = GetRandomValue(1, 2);

		switch (random){
			case 1:{
				Red red;
				red.pos = {
					static_cast<float>(GetRandomValue(0, GetScreenWidth())),
					static_cast<float>(GetRandomValue(0, GetScreenHeight())),					
				};
				m_redEnemies.push_back(red);
				break;
			}

			case 2:{
				Green green;
				green.pos = {
					static_cast<float>(GetRandomValue(0, GetScreenWidth())),
					static_cast<float>(GetRandomValue(0, GetScreenHeight())),					
				};
				green.gun = Gun();
				m_greenEnemies.push_back(green);
				break;				
			}
		}
	}
}

void Game2D::handleEnemyHits(){
	for (Bullet& bullet : m_bullets){
		if (!bullet.isAlive) continue;

		for (Red& red : m_redEnemies){
			if (bullet.checkHit(red.pos, red.radius)){
				bullet.isAlive = false;
				red.isAlive = false;

				break;
			}
		}

		for (Green& green : m_greenEnemies){
			if (bullet.checkHit(green.pos, green.radius)){
				bullet.isAlive = false;
				green.isAlive = false;

				break;
			}
		}
	}
}

bool Game2D::isPlayerHit() const{
	for (const Bullet& bullet : m_bullets){
		if (bullet.checkHit(m_player.pos, m_player.radius)){
			return true;
		}
		
	}

	for (const Red& red : m_redEnemies){
		if (CheckCollisionCircles(
			m_player.pos, m_player.radius,
			red.pos, red.radius
		)){
			return true;
		}
	}

	return false;
}


void Game2D::removeDeadObjects(){
	for (int i = m_bullets.size() - 1; i >= 0; i--){
		if (!m_bullets[i].isAlive){
			m_bullets.erase(m_bullets.begin() + i);
		}
	}
	for (int i = m_redEnemies.size() - 1; i >= 0; i--){
		if (!m_redEnemies[i].isAlive){
			m_redEnemies.erase(m_redEnemies.begin() + i);
		}
	}
	for (int i = m_greenEnemies.size() - 1; i >= 0; i--){
		if (!m_greenEnemies[i].isAlive){
			m_greenEnemies.erase(m_greenEnemies.begin() + i);
		}
	}
}

void Game2D::reset(){
	m_bullets.clear();
	m_redEnemies.clear();
	m_greenEnemies.clear();

	m_player.pos = m_player.spawnPos;
}