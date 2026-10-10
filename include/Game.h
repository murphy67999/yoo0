#pragma once

#include "Player.h"
#include "Gun.h"
#include "Bullet.h"
#include "Red.h"
#include "Green.h"

#include <vector>

struct Game{
	Player player;

	std::vector<Bullet> bullets;
	std::vector<Red> redEnemies;
	std::vector<Green> greenEnemies;

	float timer = 0.0f;

	void init();
	void update();
	void draw();

private:
	void spawnEnemy();
	void checkCollisions();
	void cleanup();
};
