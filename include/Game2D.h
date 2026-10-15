#pragma once

#include <vector>

#include "Player2D.h"
#include "Gun.h"
#include "Bullet.h"
#include "Red.h"
#include "Green.h"
#include "Scene.h"

struct Game2D{
	void run(Scene& currentScene);

private:
	static constexpr Color m_backgroundColor = DARKBROWN;
	Player2D m_player;
	std::vector<Bullet> m_bullets;
	std::vector<Red> m_redEnemies;
	std::vector<Green> m_greenEnemies;
	float m_timer = 0.0f;

	void update(Scene& currentScene);
	void draw() const;
	void updateBullets();
	void updateEnemies();
	void handleEnemySpawning();
	void handleEnemyHits();
	bool isPlayerHit() const;
	void removeDeadObjects();
	void reset();
};
