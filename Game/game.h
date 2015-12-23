#pragma once

#include "character.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "map.h"
#include "sprites.h"
#include "chest.h"
#include "bomb.h"

#include <sstream>

struct Game
{
	Game() {};

	Player player;
	tileMap myTileMap;
	Sprites mySprites;
	Clock clock;
	Clock gameTimer;
	Boomb boomb;

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

	int InitializeLevel();

	bool IsLevelCleared();
	bool IsRoomEmpty();

	void AddChest(View& view);
	bool IsChestInRoom();

	void UpdateEnemies(float& time, RenderWindow& window);
	void UpdateChests(RenderWindow& window);
	void UpdatePlayer(float& time, View& view);
	void DeleteBulletFromVector();
	void UpdateBullets(float& time, RenderWindow& window);
	void UpdateBombs(float& gameTime);
	void UpdateTime(); 
	void UpdateGame(float& time, View& view, RenderWindow& window);

	void DrawBackground(View& view, RenderWindow& window);
	void DrawPlayersHealth(View& view, RenderWindow& window);
	void DrawBombCount(View& view, RenderWindow& window);
	void DrawEnemies(RenderWindow& window);
	void DrawPlayer(RenderWindow& window);
	void DrawBombs(RenderWindow& window);
	void SetCorrectDrawOrder(float& time, RenderWindow& window);
	void DrawMap(RenderWindow& window);
	void DrawChest(RenderWindow& window);

	void DrawWindow(View& view, float& time, RenderWindow& window);
};
