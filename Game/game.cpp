#include "game.h"

void Game::InitEnemies()
{
	enemies.push_back(Enemy(mySprites.enemyTexture, FLY1_POSITION_X, FLY1_POSITION_Y, FLY_WIDTH, FLY_HEIGHT, "EnemyFly", 1, 1));
	enemies.push_back(Enemy(mySprites.enemyTexture, FLY2_POSITION_X, FLY2_POSITION_Y, FLY_WIDTH, FLY_HEIGHT, "EnemyFly", 1, 1));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, 1400, 400, 38, 43, "EnemyStandAndShoot", 3, 2));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, 1500, 400, 38, 43, "EnemyStandAndShoot", 3, 2));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, 1300, 400, 38, 43, "EnemyStandAndShoot", 3, 2));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, 1300, 500, 38, 43, "EnemyStandAndShoot", 3, 2));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, 1300, 300, 38, 43, "EnemyStandAndShoot", 3, 2));
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
		if (it->health > 0)
		{
			it->Update(bullets, time, gameTime, window, level);
			it->deathTime = gameTime;
			it->lastPosition = it->sprite.getPosition();
		}
		else
		{
			cout << "!" << endl;
			it->DestroyEffect(gameTime, window);
		}
	}
}

void Game::UpdatePlayer(float& time, View& view)
{
	player.Update(myMap, bullets, time, gameTime, lastShootPlayer, mySprites.wallBackgroundSprite, view, IsLevelCleared());
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

void Game::UpdateGame(float& time, View& view, RenderWindow& window)
{
	UpdatePlayer(time, view);
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
		if (it->health > 0)
		{
			if (it->enemyLevel == level)
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

void Game::DrawPlayer(RenderWindow& window)
{
	if (player.health > 0)
	{
		window.draw(player.sprite);
		window.draw(player.headSprite);
	}
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

bool Game::IsIntersectsPlayerEnemy(Enemy& enemy)
{
	if (player.sprite.getGlobalBounds().contains(enemy.x + (enemy.sprite.getGlobalBounds().width / 2), enemy.y + (enemy.sprite.getGlobalBounds().height / 2)))
	{
		return true;
	}
	else if (player.headSprite.getGlobalBounds().contains(enemy.x + (enemy.sprite.getGlobalBounds().width / 2), enemy.y + (enemy.sprite.getGlobalBounds().height / 2)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Game::CheckEnemyCollidesPlayer()
{
	for (vector<Enemy>::iterator it = enemies.begin();it != enemies.end(); ++it)
	{
		if (IsIntersectsPlayerEnemy(*it))
		{
			if (gameTime > hitTimer + 1 || hitTimer == 0)
			{
				player.health -= it->damage;
				hitTimer = gameTime;
			}
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
	if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up))
	{
		UpdateBullets(time, window);
		DrawPlayer(window);
	}
	else
	{
		DrawPlayer(window);
		UpdateBullets(time, window);
	}
}

void Game::DrawWindow(View& view, float& time, RenderWindow& window)
{
	DrawBackground(view, window);
	DrawMap(window);
	DrawPlayersHealth(view, window);
	DrawChest(window);
	DrawEnemies(window);
	DrawPlayer(window);
	SetCorrectDrawOrder(time, window);
}

