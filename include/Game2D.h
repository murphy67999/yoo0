#pragma once

#include <vector>

#include "Player2D.h"
#include "Gun.h"
#include "Bullet.h"
#include "Red.h"
#include "Green.h"
#include "Scene.h"

struct Game2D{
	Player2D player2D;

	std::vector<Bullet> bullets;
	std::vector<Red> redEnemies;
	std::vector<Green> greenEnemies;

	float timer = 0.0f;

	Game2D();
	void update(Scene& currentScene);
	void draw();

private:
	void updateBullets();
	void updateEnemies();
	void handleEnemySpawning();
	bool isPlayerHit();
	void handleEnemyHits();
	void removeDeadObjects();
	void reset();
};
