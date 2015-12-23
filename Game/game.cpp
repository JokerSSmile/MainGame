#include "game.h"

void Game::InitEnemies()
{
	enemies.push_back(Enemy(mySprites.enemyTexture, FLY1_POSITION_X, FLY1_POSITION_Y, FLY_WIDTH, FLY_HEIGHT, "EnemyFly", 1, 1));
	enemies.push_back(Enemy(mySprites.enemyTexture, FLY2_POSITION_X, FLY2_POSITION_Y, FLY_WIDTH, FLY_HEIGHT, "EnemyFly", 1, 1));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, 1400, 200, 38, 43, "EnemyStandAndShoot", 3, 2));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, 1500, 200, 38, 43, "EnemyStandAndShoot", 3, 2));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, 1300, 300, 38, 43, "EnemyStandAndShoot", 3, 2));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, 2100, 300, 38, 43, "EnemyStandAndShoot", 3, 3));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, 2600, 300, 38, 43, "EnemyStandAndShoot", 3, 3));
	enemies.push_back(Enemy(mySprites.enemyTexture, 1500, 760, FLY_WIDTH, FLY_HEIGHT, "EnemyFly", 1, 5));
	enemies.push_back(Enemy(mySprites.enemyTexture, 1200, 1050, FLY_WIDTH, FLY_HEIGHT, "EnemyFly", 1, 5));
	enemies.push_back(Enemy(mySprites.enemyTexture, 2100, 950, FLY_WIDTH, FLY_HEIGHT, "EnemyFly", 1, 6));
	enemies.push_back(Enemy(mySprites.enemyTexture, 1500, 800, FLY_WIDTH, FLY_HEIGHT, "EnemyFly", 1, 5));
}

void Game::InitGame()
{
	lastShootPlayer = 0;
	hitTimer = 0;
	level = 1;
	float gameTime = 0;

	InitEnemies();

	player = Player(mySprites.heroTexture, PLAYER_POSITION_X, PLAYER_POSITION_Y, PLAYER_WIDTH, PLAYER_HEIGHT, "Hero", 6, mySprites.headTexture);

	myTileMap.LoadMapSprites();

	mySprites.InitImages();
	mySprites.LoadFont();
}

int Game::InitializeLevel()
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
	return 0;
}

void Game::UpdateEnemies(float& time, RenderWindow& window)
{
	for (vector<Enemy>::iterator it = enemies.begin();it != enemies.end(); ++it)
	{
		if (it->life == true)
		{
			it->lastPosition = { it->x, it->y };
			it->Update(boomb, bullets, time, gameTime, window, level);
			it->ExplosionCollision(boomb, gameTime);
			it->deathTime = gameTime;
		}
	}
}

void Game::UpdatePlayer(float& time, View& view)
{
	player.Control(boomb, bullets, time, gameTime, lastShootPlayer);
	player.CheckCollision(myMap, mySprites.wallBackgroundSprite, view, IsLevelCleared());
	player.CheckEnemyCollidesPlayer(enemies, gameTime, hitTimer);
	player.ChangeColorAfterHit(gameTime, hitTimer);
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		player.canMove = true;
		cout << endl;
	}
	player.Moving(time);
}

void Game::UpdateChests(RenderWindow& window)
{
	for (vector<Chest>::iterator chest = chests.begin(); chest != chests.end(); ++chest)
	{
		chest->Update(player);
	}
}

void Game::DeleteBulletFromVector()
{
	for (vector<Bullet>::iterator it = bullets.begin();it != bullets.end(); ++it)
	{
		if (it->deathTime > it->deathTime + BULLET_ANIMATION_STEP_TIME * 2)
		{
			it = bullets.erase(it);
		}
	}
}

void Game::UpdateBullets(float& time, RenderWindow& window)
{
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
						if (Collision::PixelPerfectTest(it->sprite, it1->bulletSprite))
						{
							it1->deathTime = gameTime;
							it1->life = false;
							it->health -= it1->damage;
							it->playerHitTime = gameTime;
						}
					}
				}
			}
			if (it1->isPlayers == false)
			{
				if (Collision::PixelPerfectTest(player.sprite, it1->bulletSprite) || Collision::PixelPerfectTest(player.headSprite, it1->bulletSprite))
				{
					it1->life = false;
					player.health -= it1->damage;
				}
			}
			
			it1->UpdateBullet(time, window, gameTime, mySprites.bulletTexture, mySprites.bulletEffectTexture, mySprites.bulletEffectTextureEnemy, myMap, mySprites.wallBackgroundSprite);
			it1->DeleteBullet(gameTime);

			
		}
		else
		{
			it1->BulletDestroyEffect(gameTime, window);
		}
	}
	DeleteBulletFromVector();
}

void Game::UpdateBombs(float& gameTime)
{
	boomb.Update(gameTime);
}

void Game::UpdateTime()
{
	if (player.health > 0)
	{
		gameTime = gameTimer.getElapsedTime().asSeconds();
	}
}

void Game::UpdateGame(float& time, View& view, RenderWindow& window)
{
	level = InitializeLevel();

	AddChest(view);
	UpdatePlayer(time, view);
	UpdateTime();
	UpdateEnemies(time, window);
	UpdateChests(window);
	UpdateBullets(time, window);
}

void Game::DrawBackground(View& view, RenderWindow& window)
{
	mySprites.wallBackgroundSprite.setOrigin(mySprites.wallBackgroundSprite.getGlobalBounds().width / 2, mySprites.wallBackgroundSprite.getGlobalBounds().height / 2);
	mySprites.wallBackgroundSprite.setPosition(view.getCenter().x, view.getCenter().y);
	mySprites.floorBackgroundSprite.setOrigin(mySprites.floorBackgroundSprite.getGlobalBounds().width / 2, mySprites.floorBackgroundSprite.getGlobalBounds().height / 2);
	mySprites.floorBackgroundSprite.setPosition(view.getCenter().x, view.getCenter().y);
	window.draw(mySprites.wallBackgroundSprite);
	window.draw(mySprites.floorBackgroundSprite);
}

void Game::DrawBombCount(View& view, RenderWindow& window)
{
	Sprite bombCountSprite;
	bombCountSprite.setTexture(mySprites.bombCount);
	bombCountSprite.setPosition(view.getCenter().x - WINDOW_WIDTH / 2 + 28, view.getCenter().y - WINDOW_HEIGHT / 2 + 32);
	bombCountSprite.setScale(1.5, 1.5);
	window.draw(bombCountSprite);

	Text textBombs;
	textBombs.setFont(mySprites.font);
	textBombs.setPosition(view.getCenter().x - WINDOW_WIDTH / 2 + 80, view.getCenter().y - WINDOW_HEIGHT / 2 + 45);
	textBombs.setCharacterSize(20);

	ostringstream toString;
	toString << player.bombCount;
	textBombs.setString(toString.str());

	window.draw(textBombs);
}

void Game::DrawPlayersHealth(View& view, RenderWindow& window)
{
	Texture heartTexture;
	heartTexture.loadFromFile("images/hearts.png");
	Sprite fullHP;
	fullHP.setTexture(heartTexture);
	fullHP.setTextureRect(IntRect(0, 0, 16, 16));
	fullHP.setScale(2, 2);
	Sprite halfHP;
	halfHP.setTexture(heartTexture);
	halfHP.setTextureRect(IntRect(16, 0, 16, 16));
	halfHP.setScale(2, 2);
	Sprite emptySprite;
	emptySprite.setTexture(heartTexture);
	emptySprite.setTextureRect(IntRect(32, 0, 16, 16));
	emptySprite.setScale(2, 2);

	for (int i = 1; i <= MAX_PLAYER_HEALTH; i++)
	{
		emptySprite.setPosition(view.getCenter().x - WINDOW_WIDTH / 2 + i * 35, view.getCenter().y - WINDOW_HEIGHT / 2 + 10);
		window.draw(emptySprite);
	}
	if (player.health > 0)
	{
		for (int i = 1; i <= player.health; i++)
		{
			fullHP.setPosition(view.getCenter().x - WINDOW_WIDTH / 2 + i * 35, view.getCenter().y - WINDOW_HEIGHT / 2 + 10);
			window.draw(fullHP);
		}
		if (player.health - int(player.health) != 0)
		{
			halfHP.setPosition(view.getCenter().x - WINDOW_WIDTH / 2 + int(player.health + 1) * 35, view.getCenter().y - WINDOW_HEIGHT / 2 + 10);
			window.draw(halfHP);
		}
	}
}

void Game::DrawEnemies(RenderWindow& window)
{
	for (vector<Enemy>::iterator it = enemies.begin();it != enemies.end(); ++it)
	{
		if (it->life == true)
		{
			if (it->enemyLevel == level)
			{
				window.draw(it->sprite);
			}
		}
		else
		{
			it->DestroyEffect(gameTime, window, mySprites.poofTexture);
			it->x = 0;
			it->y = 0;
		}
	}
}

void Game::DrawPlayer(RenderWindow& window)
{
	if (player.health > 0)
	{
		window.draw(player.sprite);
		window.draw(player.headSprite);
	}
}

void Game::DrawBombs(RenderWindow& window)
{
	boomb.Draw(window, mySprites.bombState, mySprites.bombExplosion, gameTime);	
}

bool Game::IsLevelCleared()
{
	bool isAllDead = true;

	for (vector<Enemy>::iterator it = enemies.begin();it != enemies.end(); ++it)
	{
		if (it->enemyLevel == level)
		{
			if (it->health > 0)
			{
				isAllDead = false;
			}
		}
	}
	return isAllDead;
}

bool Game::IsRoomEmpty()
{
	bool isEmpty = true;

	for (vector<Enemy>::iterator it = enemies.begin();it != enemies.end(); ++it)
	{
		if (it->enemyLevel == level)
		{
			isEmpty = false;
		}
	}
	return isEmpty;
}

bool Game::IsChestInRoom()
{
	if (chests.size() == 0)
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

void Game::AddChest(View& view)
{
	if (IsLevelCleared() && !IsRoomEmpty())
	{
		if (IsChestInRoom() == false)
		{
			chests.push_back(Chest(view.getCenter().x, view.getCenter().y, level));
		}
	}
}

void Game::DrawMap(RenderWindow& window)
{
	myTileMap.drawMap(myMap, window, IsLevelCleared());
}

void Game::DrawChest(RenderWindow& window)
{
	for (vector<Chest>::iterator it = chests.begin();it != chests.end(); ++it)
	{
			it->DrawChest(window);
	}
}

void Game::SetCorrectDrawOrder(float& time, RenderWindow& window)
{
	if (player.y + player.h < boomb.position.y + 64)
	{
	    DrawPlayer(window);
		DrawBombs(window);
	}
	else
	{
		DrawBombs(window);
		DrawPlayer(window);
	}
}

void Game::DrawWindow(View& view, float& time, RenderWindow& window)
{
	DrawBackground(view, window);
	DrawMap(window);
	DrawPlayersHealth(view, window);
	DrawBombCount(view, window);
	DrawChest(window);
	SetCorrectDrawOrder(time, window);
	UpdateBullets(time, window);
	DrawEnemies(window);
}

