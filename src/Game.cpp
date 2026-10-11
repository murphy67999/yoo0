#include "raylib.h"
#include "raymath.h"
#include <iostream>

#include "Game.h"
#include "Gun.h"
#include "Screen.h"

void Game::init(){
	player.gun = Gun();
}

void Game::update(Screen& currentScreen){
	player.update();
	player.gun.update(player.pos, GetMousePosition());

	updateBullets();
	updateEnemies();

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		player.gun.shoot(GetMousePosition(), bullets);
	}

	if (isPlayerHit()){
		reset();
		currentScreen = DEATH;
	}

	handleEnemySpawning();
	handleEnemyHits();
	removeDeadObjects();
}

void Game::draw(){
	ClearBackground(RAYWHITE);

	DrawCircleV(player.pos, player.radius, player.color);
	DrawCircleV(player.gun.pos, player.gun.radius, player.gun.color);

	for (Bullet bullet : bullets){
		DrawCircleV(bullet.pos, bullet.radius, bullet.color);
	}

	for (Red red : redEnemies){
		DrawCircleV(red.pos, red.radius, red.color);
	}

	for (Green green : greenEnemies){
		DrawCircleV(green.pos, green.radius, green.color);
		DrawCircleV(green.gun.pos, green.gun.radius, green.gun.color);
	}
}

void Game::updateBullets(){
	for (Bullet& bullet : bullets){
		bullet.update();
	}
}

void Game::updateEnemies(){
	for (Red& red : redEnemies){
		red.update(player.pos);
	}
	for (Green& green : greenEnemies){
		green.gun.update(green.pos, player.pos);
		green.gun.shoot(player.pos, bullets);
	}
}

void Game::handleEnemySpawning(){
	timer += GetFrameTime();
	if (timer >= 2.0f){
		timer = 0.0f;
		
		int random = GetRandomValue(1, 2);

		switch (random){
			case 1:{
				Red red;
				red.pos = {
					static_cast<float>(GetRandomValue(0, GetScreenWidth())),
					static_cast<float>(GetRandomValue(0, GetScreenHeight())),					
				};
				redEnemies.push_back(red);
				break;
			}

			case 2:{
				Green green;
				green.pos = {
					static_cast<float>(GetRandomValue(0, GetScreenWidth())),
					static_cast<float>(GetRandomValue(0, GetScreenHeight())),					
				};
				green.gun = Gun();
				greenEnemies.push_back(green);
				break;				
			}
		}
	}
}

bool Game::isPlayerHit(){
	for (Bullet& Bullet : bullets){
		if (CheckCollisionCircles(
			player.pos, player.radius,
			Bullet.pos, Bullet.radius
		)){
			return true;
		}
	}

	for (const Red& red : redEnemies){
		if (CheckCollisionCircles(
			player.pos, player.radius,
			red.pos, red.radius
		)){
			return true;
		}
	}

	return false;
}

void Game::handleEnemyHits(){
	for (Bullet& bullet : bullets){
		if (!bullet.isAlive) continue;

		for (Red& red : redEnemies){
			if (CheckCollisionCircles(
				bullet.pos, bullet.radius,
				red.pos, red.radius
				)){
				bullet.isAlive = false;
				red.isAlive = false;

				break;
			}
		}

		for (Green& green : greenEnemies){
			if (CheckCollisionCircles(
				bullet.pos, bullet.radius,
				green.pos, green.radius
				)){
				bullet.isAlive = false;
				green.isAlive = false;

				break;
			}
		}
	}
}

void Game::removeDeadObjects(){
	for (int i = bullets.size() - 1; i >= 0; i--){
		if (!bullets[i].isAlive){
			bullets.erase(bullets.begin() + i);
		}
	}
	for (int i = redEnemies.size() - 1; i >= 0; i--){
		if (!redEnemies[i].isAlive){
			redEnemies.erase(redEnemies.begin() + i);
		}
	}
	for (int i = greenEnemies.size() - 1; i >= 0; i--){
		if (!greenEnemies[i].isAlive){
			greenEnemies.erase(greenEnemies.begin() + i);
		}
	}
}

void Game::reset(){
	bullets.clear();
	redEnemies.clear();
	greenEnemies.clear();

	player.pos = player.spawnPos;
}