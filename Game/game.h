#pragma once

#include "character.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "map.h"
#include "sprites.h"
#include "chest.h"

struct Game
{
	Game() {};

	Player player;
	tileMap myTileMap;
	Sprites mySprites;
	RenderWindow window;
	Clock clock;
	Clock gameTimer;

	vector<Map> myMap;
	vector<Enemy> enemies;
	vector<Bullet> bullets;
	vector<Chest> chests;

	float lastShootPlayer;
	float hitTimer;
	float gameTime;
	int level;

	void InitEnemies();

	void InitGame();

	void InitRoomNumber();
};
