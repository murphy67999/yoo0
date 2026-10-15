#include "raylib.h"
#include "raymath.h"
#include <iostream>

#include "Game2D.h"
#include "Gun.h"
#include "Scene.h"

void Game2D::run(Scene& currentScene){
	update(currentScene);
	draw();
}

void Game2D::update(Scene& currentScene){
	m_player.update();

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
	ClearBackground(m_backgroundColor);

	m_player.draw();

	for (Bullet bullet : m_bullets){
		bullet.draw();
	}

	for (Red red : m_redEnemies){
		red.draw();
	}

	for (Green green : m_greenEnemies){
		green.draw();
	}
}

void Game2D::updateBullets(){
	for (Bullet& bullet : m_bullets){
		bullet.update();
	}
}

void Game2D::updateEnemies(){
	for (Red& red : m_redEnemies){
		red.update(m_player.getPos());
	}
	for (Green& green : m_greenEnemies){
		green.gun.update(green.getPos(), m_player.getPos());
		if (green.gun.canShoot()){
			m_bullets.push_back(green.gun.shoot(m_player.getPos()));
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
				m_redEnemies.emplace_back(
					Vector2{
						static_cast<float>(GetRandomValue(0, GetScreenWidth())),
						static_cast<float>(GetRandomValue(0, GetScreenHeight()))
					}
				);
				break;
			}

			case 2:{
				m_greenEnemies.emplace_back(
					Vector2{
						static_cast<float>(GetRandomValue(0, GetScreenWidth())),
						static_cast<float>(GetRandomValue(0, GetScreenHeight()))
					}
				);
				break;				
			}
		}
	}
}

void Game2D::handleEnemyHits(){
	for (Bullet& bullet : m_bullets){
		if (!bullet.isAlive) continue;

		for (Red& red : m_redEnemies){
			if (bullet.checkHit(red.getPos(), red.getRadius())){
				bullet.isAlive = false;
				red.isAlive = false;

				break;
			}
		}

		for (Green& green : m_greenEnemies){
			if (bullet.checkHit(green.getPos(), green.getRadius())){
				bullet.isAlive = false;
				green.isAlive = false;

				break;
			}
		}
	}
}

bool Game2D::isPlayerHit() const{
	for (const Bullet& bullet : m_bullets){
		if (bullet.checkHit(m_player.getPos(), m_player.getRadius())){
			return true;
		}
		
	}

	for (const Red& red : m_redEnemies){
		if (CheckCollisionCircles(
			m_player.getPos(), m_player.getRadius(),
			red.getPos(), red.getRadius()
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

	m_player.reset();
}