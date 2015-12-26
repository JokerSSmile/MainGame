#pragma once

#include "character.h"
#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "map.h"
#include "sprites.h"
#include "chest.h"
#include "bomb.h"
#include "music.h"

#include <sstream>

static enum 
{
	NOT_STATED,
	FIRST,
	SECOND,
	THIRD,
	FORTH,
	FIFTH,
	SIXTH,
	SEVENTH,
	EIGHTH,
	NINTH
} currentRoom;

static enum
{
	MAIN_MENU,
	GAME,
	PAUSE
} gameState;

struct Game
{
	Game() {};

	Player player;
	tileMap myTileMap;
	Sprites mySprites;
	Clock clock;
	Clock gameTimer;
	Boomb boomb;
	Sounds mySounds;

	Sprite mainMenuSprite;

	vector<Map> myMap;
	vector<Enemy> enemies;
	vector<Bullet> bullets;
	vector<Chest> chests;

	float lastShootPlayer;
	float hitTimer;
	float gameTime;
	int room;

	void InitEnemies();

	void InitGame();

	int InitializeRoom();

	bool IsRoomCleared();
	bool IsRoomEmpty();

	void AddChest(View& view);
	bool IsChestInRoom();

	void DeleteEnemyFromVector();
	void UpdateEnemies(float& time, RenderWindow& window);
	void UpdateChests(RenderWindow& window);
	void UpdatePlayer(float& time, View& view);
	void DeleteBulletFromVector();
	void UpdatePlayersBullets(Bullet& bullet);
	void UpdateEnemiesBullets(Bullet& bullet);
	void UpdateBullets(float& time, RenderWindow& window);
	void UpdateBombs();
	void UpdateTime(); 
	void UpdateMusic();
	void UpdateGame(float& time, View& view, RenderWindow& window);

	void DrawBackground(View& view, RenderWindow& window);
	void DrawPlayersHealth(View& view, RenderWindow& window);
	void DrawBombCount(View& view, RenderWindow& window);
	void DrawEnemies(RenderWindow& window);
	void DrawPlayer(RenderWindow& window);
	void DrawBombs(RenderWindow& window, float& time);
	void SetCorrectDrawOrder(float& time, RenderWindow& window);
	void DrawMap(RenderWindow& window);
	void DrawChest(RenderWindow& window);

	void DrawWindow(View& view, float& time, RenderWindow& window);
};
