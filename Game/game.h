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
#include "menu.h"

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

struct Game
{
	Game() {};

	MainMenu menu;
	Player player;
	tileMap myTileMap;
	Sprites mySprites;
	Clock clock;
	Clock gameTimer;
	Boomb boomb;
	Sounds mySounds;
	GameState gameState;
	View view;
	Event event;

	Sprite mainMenuSprite;

	vector<Map> myMap;
	vector<Enemy> enemies;
	vector<Bullet> bullets;
	vector<Chest> chests;

	float lastShootPlayer;
	float hitTimer;
	float gameTime;
	float time;
	int room;
	int volume;

	void InitEnemies();

	void InitGame();

	int InitializeRoom();

	bool IsRoomCleared();
	bool IsRoomEmpty();

	void AddChest(View& view);
	bool IsChestInRoom();

	void DeleteEnemyFromVector();
	void UpdateEnemies(RenderWindow& window);
	void UpdateChests(RenderWindow& window);
	void UpdatePlayer();
	void DeleteBulletFromVector();
	void UpdatePlayersBullets(Bullet& bullet);
	void UpdateEnemiesBullets(Bullet& bullet);
	void UpdateBullets(RenderWindow& window);
	void UpdateBombs();
	void UpdateTimePerFrame();
	void UpdateTime(); 
	void UpdateSounds();
	void ProcessEvents(RenderWindow& window);
	void UpdateGame(RenderWindow& window);

	void DrawBackground(RenderWindow& window);
	void DrawPlayersHealth(RenderWindow& window);
	void DrawBombCount(RenderWindow& window);
	void DrawEnemies(RenderWindow& window);
	void DrawPlayer(RenderWindow& window);
	void DrawBombs(RenderWindow& window);
	void SetCorrectDrawOrder(RenderWindow& window);
	void DrawMap(RenderWindow& window);
	void DrawChest(RenderWindow& window);

	void DrawWindow(RenderWindow& window);
};
