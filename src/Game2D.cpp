#include "raylib.h"
#include "raymath.h"
#include <iostream>

#include "Game2D.h"
#include "Gun.h"
#include "Scene.h"

Game2D::Game2D(){
	player2D.gun = Gun();
}

void Game2D::update(Scene& currentScene){
	player2D.update();
	player2D.gun.update(player2D.pos, GetMousePosition());

	updateBullets();
	updateEnemies();

	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
		player2D.gun.shoot(GetMousePosition(), bullets);
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

void Game2D::draw(){
	ClearBackground(DARKGRAY);

	DrawCircleV(player2D.pos, player2D.radius, player2D.color);
	DrawCircleV(player2D.gun.pos, player2D.gun.radius, player2D.gun.color);

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

	int fps = GetFPS();
    DrawText(TextFormat("FPS %d", fps), 10, 10, 50, RAYWHITE);
}

void Game2D::updateBullets(){
	for (Bullet& bullet : bullets){
		bullet.update();
	}
}

void Game2D::updateEnemies(){
	for (Red& red : redEnemies){
		red.update(player2D.pos);
	}
	for (Green& green : greenEnemies){
		green.gun.update(green.pos, player2D.pos);
		green.gun.shoot(player2D.pos, bullets);
	}
}

void Game2D::handleEnemySpawning(){
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

bool Game2D::isPlayerHit(){
	for (Bullet& Bullet : bullets){
		if (CheckCollisionCircles(
			player2D.pos, player2D.radius,
			Bullet.pos, Bullet.radius
		)){
			return true;
		}
	}

	for (const Red& red : redEnemies){
		if (CheckCollisionCircles(
			player2D.pos, player2D.radius,
			red.pos, red.radius
		)){
			return true;
		}
	}

	return false;
}

void Game2D::handleEnemyHits(){
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

void Game2D::removeDeadObjects(){
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

void Game2D::reset(){
	bullets.clear();
	redEnemies.clear();
	greenEnemies.clear();

	player2D.pos = player2D.spawnPos;
}