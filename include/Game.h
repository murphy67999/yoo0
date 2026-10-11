#pragma once

#include <vector>

#include "Player.h"
#include "Gun.h"
#include "Bullet.h"
#include "Red.h"
#include "Green.h"
#include "Screen.h"

struct Game{
	Player player;

	std::vector<Bullet> bullets;
	std::vector<Red> redEnemies;
	std::vector<Green> greenEnemies;

	float timer = 0.0f;

	void init();
	void update(Screen& currentScreen);
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
