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
#include "boss.h"

#include <sstream>



struct Game
{
	Game() {};

	Window window;
	MainMenu menu;
	Player player;
	Boss boss;
	tileMap myTileMap;
	Sprites mySprites;
	Clock clock;
	Clock gameTimer;
	Boomb boomb;
	Sounds mySounds;
	GameState gameState;
	View view;
	Event event;
	Level level;
	PlayerState playerState;
	RoomNum room;

	Sprite mainMenuSprite;
	Sprite pauseSprite;
	RectangleShape pauseRect;

	Text continueText;
	Text exitText;
	Text menuText;

	vector<Map> myMap;
	vector<Enemy> enemies;
	vector<Bullet> bullets;
	vector<Chest> chests;

	float currentFrame;
	float lastShootPlayer;
	float gameTime;
	float time;
	int volume;
	bool isKeyPressed;

	void InitLevelOneEnemies();

	void InitLevelTwoEnemies();

	void InitLevelThreeEnemies();

	void InitEnemies();
	void InitGame(RenderWindow& window);
	void ResetData();
	void Restart();
	void InitializeRoom();

	void SetPauseText();
	void CheckMouseIntersectionWithTextPause(RenderWindow& window);
	void InitSheetAndBackground(RenderWindow& window);
	void SetPause(RenderWindow& window);

	void SetEndGameText(RenderWindow& window);
	void CheckMouseIntersectionWithTextEnd(RenderWindow & window);
	void EndGame(RenderWindow & window);

	bool IsRoomCleared();
	bool IsRoomEmpty();
	void AddChest(View& view);
	bool IsChestInRoom();

	bool RemoveEnemyFromVector();
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
	void UpdateMusic();
	void ProcessEvents(RenderWindow& window);
	void UpdatePause();
	void SetMainMenuMusic();
	void CheckEndGame();
	void UpdateBoss();
	void UpdateGame(RenderWindow& window);

	void DrawHelp(RenderWindow & window);

	void DrawBackground(RenderWindow& window);
	void DrawPlayersHealth(RenderWindow& window);
	void DrawBombCount(RenderWindow& window);
	void DrawEnemies(RenderWindow& window);
	void DrawPlayer(RenderWindow& window);
	void DrawBombs(RenderWindow& window);
	void SetCorrectDrawOrder(RenderWindow& window);
	void JumpNextLevel(RenderWindow & window);
	void DrawMap(RenderWindow& window);
	void DrawChest(RenderWindow& window);
	void DrawPause(RenderWindow& window);

	void DrawEndGame(RenderWindow& window);
	void DrawBoss(RenderWindow& window);
	void DrawWindow(RenderWindow& window);
};
