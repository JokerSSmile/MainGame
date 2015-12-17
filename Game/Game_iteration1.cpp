#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>
#include "collision.h"
#include "constants.h"
#include "map.h"
#include "view.h"
#include "player.h"
#include "enemy.h"
#include "chest.h"
#include "sprites.h"


using namespace sf;
using namespace std;


int InitializeLevel(Player & player)
{
	if (player.x > 0 && player.x < WINDOW_WIDTH)
	{
		if (player.y > 0 && player.y < WINDOW_HEIGHT)
		{
			return 1;
		}
		else if (player.y > WINDOW_HEIGHT && player.y < WINDOW_HEIGHT * 2)
		{
			return 4;
		}
		else if (player.y > WINDOW_HEIGHT * 2 && player.y < WINDOW_HEIGHT * 3)
		{
			return 7;
		}
	}
	else if (player.x > WINDOW_WIDTH && player.x < WINDOW_WIDTH * 2)
	{
		if (player.y > 0 && player.y < WINDOW_HEIGHT)
		{
			return 2;
		}
		else if (player.y > WINDOW_HEIGHT && player.y < WINDOW_HEIGHT * 2)
		{
			return 5;
		}
		else if (player.y > WINDOW_HEIGHT * 2 && player.y < WINDOW_HEIGHT * 3)
		{
			return 8;
		}
	}
	else if (player.x > WINDOW_WIDTH * 2 && player.x < WINDOW_WIDTH * 3)
	{
		if (player.y > 0 && player.y < WINDOW_HEIGHT)
		{
			return 3;
		}
		else if (player.y > WINDOW_HEIGHT && player.y < WINDOW_HEIGHT * 2)
		{
			return 6;
		}
		else if (player.y > WINDOW_HEIGHT * 2 && player.y < WINDOW_HEIGHT * 3)
		{
			return 9;
		}
	}
}

void ProcessEvents(RenderWindow& window)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}
}

void DrawPlayersHealth(float health, RenderWindow & window, View & view)
{
	Texture heartTexture;
	heartTexture.loadFromFile("images/hearts.png");
	Sprite fullHP;
	fullHP.setTexture(heartTexture);
	fullHP.setTextureRect(IntRect(0,0,16,16));
	fullHP.setScale(2, 2);
	Sprite halfHP;
	halfHP.setTexture(heartTexture);
	halfHP.setTextureRect(IntRect(16, 0, 16, 16));
	halfHP.setScale(2, 2);

	if (health > 0)
	{
		for (int i = 1; i <= health; i += 1)
		{
			fullHP.setPosition(view.getCenter().x - WINDOW_WIDTH / 2 + i * 35, view.getCenter().y - WINDOW_HEIGHT / 2 + 10);
			window.draw(fullHP);
		}
		if (health - int(health) != 0)
		{
			halfHP.setPosition(view.getCenter().x - WINDOW_WIDTH / 2 + int(health + 1) * 35, view.getCenter().y - WINDOW_HEIGHT / 2 + 10);
			window.draw(halfHP);
		}
	}
}

void DrawBackground(RenderWindow & window, Sprite & wallBackgroundSprite, Sprite & floorBackgroundSprite)
{
	//background
	wallBackgroundSprite.setOrigin(wallBackgroundSprite.getGlobalBounds().width / 2, wallBackgroundSprite.getGlobalBounds().height / 2);
	wallBackgroundSprite.setPosition(view.getCenter().x, view.getCenter().y);
	floorBackgroundSprite.setOrigin(floorBackgroundSprite.getGlobalBounds().width / 2, floorBackgroundSprite.getGlobalBounds().height / 2);
	floorBackgroundSprite.setPosition(view.getCenter().x, view.getCenter().y);
	window.draw(wallBackgroundSprite);
	window.draw(floorBackgroundSprite);
}

void CheckEnemyCollidesPlayer(float& gameTime, float& hitTimer, Player& p, vector<Enemy>& enemies)
{
	//check colisions enemies with player
	for (vector<Enemy>::iterator it = enemies.begin();it != enemies.end(); ++it)
	{
		if (p.sprite.getGlobalBounds().contains(it->x + (it->sprite.getGlobalBounds().width / 2), it->y + (it->sprite.getGlobalBounds().height / 2)))
		{
			if (gameTime > hitTimer + 1 || hitTimer == 0)
			{
				p.health -= enemies[0].damage;
				hitTimer = gameTime;
			}
		}
	}
}

void UpdateBullets(Player& p, vector<Enemy>& enemies, float gameTime, vector<Bullet>& bullets, float& time, RenderWindow& window, Sprites& mySprite)//Texture& bulletTexture)
{
	//going through bullets mass and delete/update it. Check collisions with player, enemies
	for (vector<Bullet>::iterator it1 = bullets.begin();it1 != bullets.end(); ++it1)
	{
		if (it1->life == true)
		{
			for (vector<Enemy>::iterator it = enemies.begin();it != enemies.end(); ++it)
			{
				if (it->health > 0)
				{
					if (it1->isPlayers == true)
					{
						if (it->sprite.getGlobalBounds().contains(it1->x + BULLET_SIDE / 2, it1->y + BULLET_SIDE / 2))
						{
							it1->life = false;
							it->health -= p.damage;
						}
					}
				}
			}
			if (it1->isPlayers == false)
			{
				if (p.sprite.getGlobalBounds().contains(it1->x + BULLET_SIDE / 2, it1->y + BULLET_SIDE / 2))
				{
					it1->life = false;
					it1->isPlayers = false;
					p.health -= enemies[0].damage;
				}
			}
			it1->Update(time, window, gameTime, mySprite.bulletTexture);
			it1->DeleteBullet(gameTime);
		}
	}
}

void DrawEnemies(RenderWindow& window, int& level, vector<Enemy>& enemies)
{
	for (vector<Enemy>::iterator it = enemies.begin();it != enemies.end(); ++it)
	{
		if (it->health > 0)
		{
			if (it->level == level)
			{
				window.draw(it->sprite);
			}
		}
		else
		{
			it->x = 0;
			it->y = 0;
		}
	}
}

void DrawPlayer(Player& p, RenderWindow& window)
{
	//while HP > 0 draw player 
	if (p.health > 0)
	{
		window.draw(p.sprite);
	}
}

void UpdateEnemies(vector<Enemy>& enemies, float& time, float& gameTime, RenderWindow& window, int& level)
{
	//enemy update
	for (vector<Enemy>::iterator it = enemies.begin();it != enemies.end(); ++it)
	{
		if (it->health > 0)
		{
			it->Update(time, gameTime, window, level);
		}
	}
}

bool IsLevelCleared(int& level, vector<Enemy>& enemies)
{
	bool isAllDead = true;

	for (vector<Enemy>::iterator it = enemies.begin();it != enemies.end(); ++it)
	{
		if (it->level == level)
		{
			if (it->health > 0)
			{
				isAllDead = false;
			}
		}
	}
	return isAllDead;
}

bool IsRoomEmpty(int& level, vector<Enemy>& enemies)
{
	bool isEmpty = true;

	for (vector<Enemy>::iterator it = enemies.begin();it != enemies.end(); ++it)
	{
		if (it->level == level)
		{
			isEmpty = false;
		}
	}
	return isEmpty;
}

bool IsChestInRoom(vector<Chest> chests, int& level)
{
	if (size(chests) == 0)
	{
		return false;
	}
	bool isChestInRoom = false;
	for (vector<Chest>::iterator chest = chests.begin(); chest != chests.end(); ++chest)
	{
		if (level == chest->level)
		{
			isChestInRoom = true;
		}
	}
	return isChestInRoom;
}

void AddChest(int& level, vector<Chest>& chests, vector<Enemy>& enemies)
{
	if (IsLevelCleared(level, enemies) && !IsRoomEmpty(level, enemies))
	{
		if (IsChestInRoom(chests, level) == false)
		{
			chests.push_back(Chest(view.getCenter().x, view.getCenter().y, level));
		}
	}
}

void UpdateChests(vector<Chest>& chests, RenderWindow& window, Player& p)
{
	for (vector<Chest>::iterator chest = chests.begin(); chest != chests.end(); ++chest)
	{
		chest->Update(window, p);
	}
}

void InitEnemies(vector<Enemy>& enemies, Sprites& mySprites)
{
	enemies.push_back(Enemy(mySprites.enemyTexture, FLY1_POSITION_X, FLY1_POSITION_Y, FLY_WIDTH, FLY_HEIGHT, "EnemyFly", 1, 1));
	enemies.push_back(Enemy(mySprites.enemyTexture, FLY2_POSITION_X, FLY2_POSITION_Y, FLY_WIDTH, FLY_HEIGHT, "EnemyFly", 1, 1));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, 1400, 400, 38, 43, "EnemyStandAndShoot", 3, 2));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, 1500, 400, 38, 43, "EnemyStandAndShoot", 3, 2));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, 1300, 400, 38, 43, "EnemyStandAndShoot", 3, 2));
}

void StartGame()
{
	//players last shoot time
	float lastShootPlayer = 0;

	//map struct
	tileMap myMap;

	Sprites mySprites;
	mySprites.InitImages();

	vector<Chest> chests;

	vector<Enemy> enemies;
	InitEnemies(enemies, mySprites);

	//create player
	Player player(mySprites.heroTexture, PLAYER_POSITION_X, PLAYER_POSITION_Y, PLAYER_WIDTH, PLAYER_HEIGHT, "Hero", 6);

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game");

	view.reset(FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));

	//clock
	Clock clock;
	Clock gameTimer;

	//last player hit time
	float hitTimer = 0;

	//game time
	float gameTime;

	//current level
	int level = 1;

	while (window.isOpen())
	{
		level = InitializeLevel(player);

		//time
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 500;

		//game time
		if (player.health > 0)
		{
			gameTime = gameTimer.getElapsedTime().asSeconds();
		}

		//event
		ProcessEvents(window);

		player.Update(time, gameTime, lastShootPlayer, mySprites.wallBackgroundSprite, view);

		UpdateEnemies(enemies, time, gameTime, window, level);

		AddChest(level, chests, enemies);
		CheckEnemyCollidesPlayer(gameTime, hitTimer, player, enemies);

		//view
		window.setView(view);

		/////////////////////////////
		window.clear();

		DrawBackground(window, mySprites.wallBackgroundSprite, mySprites.floorBackgroundSprite);

		DrawPlayersHealth(player.health, window, view);

		DrawEnemies(window, level, enemies);

		myMap.drawMap(window, IsLevelCleared(level, enemies));

		UpdateChests(chests, window, player);

		UpdateBullets(player, enemies, gameTime, bullets, time, window, mySprites);

		DrawPlayer(player, window);

		window.display();
		/////////////////////////////
	}
}

int main()
{
	StartGame();
	return 0;
}
