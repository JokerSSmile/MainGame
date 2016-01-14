#include "game.h"

void Game::InitLevelOneEnemies()
{
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(400, 300), Vector2i(WORM_SIZE), "Worm", WORM_HP_1, 1));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(1200, 800), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_1, 5));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(1300, 1100), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_1, 5));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, Vector2f(1400, 220), Vector2i(STAND_AND_SHOOT_SIZE), "EnemyStandAndShoot", STAND_AND_SHOOT_HP_1, 2));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, Vector2f(1400, 900), Vector2i(STAND_AND_SHOOT_SIZE), "EnemyStandAndShoot", STAND_AND_SHOOT_HP_1, 5));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, Vector2f(2100, 1000), Vector2i(STAND_AND_SHOOT_SIZE), "EnemyStandAndShoot", STAND_AND_SHOOT_HP_1, 6));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, Vector2f(2600, 1000), Vector2i(STAND_AND_SHOOT_SIZE), "EnemyStandAndShoot", STAND_AND_SHOOT_HP_1, 6));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(2300, 800), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_1, 6));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(2600, 900), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_1, 6));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(2100, 200), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_1, 3));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(2300, 400), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_1, 3));
}

void Game::InitLevelTwoEnemies()
{
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(300, 200), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_2, 1));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(350, 325), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_2, 1));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(1400, 1000), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_2, 5));
	enemies.push_back(Enemy(mySprites.heroTexture, Vector2f(1600, 1000), Vector2i(ZOMBIE_SIZE), "EnemyFollow", FOLLOW_HP_2, 5));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(1100, 800), Vector2i(WORM_SIZE), "Worm", WORM_HP_2, 5));
	enemies.push_back(Enemy(mySprites.heroTexture, Vector2f(1200, 1700), Vector2i(ZOMBIE_SIZE), "EnemyFollow", FOLLOW_HP_2, 8));
	enemies.push_back(Enemy(mySprites.heroTexture, Vector2f(1300, 1700), Vector2i(ZOMBIE_SIZE), "EnemyFollow", FOLLOW_HP_2, 8));
	enemies.push_back(Enemy(mySprites.heroTexture, Vector2f(1600, 1700), Vector2i(ZOMBIE_SIZE), "EnemyFollow", FOLLOW_HP_2, 8));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(500, 1500), Vector2i(WORM_SIZE), "Worm", WORM_HP_2, 7));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(700, 1600), Vector2i(WORM_SIZE), "Worm", WORM_HP_2, 7));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(300, 1650), Vector2i(WORM_SIZE), "Worm", WORM_HP_2, 7));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(2500, 1450), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_2, 9));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(2600, 1500), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_2, 9));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(2550, 1600), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_2, 9));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(2450, 1700), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_2, 9));
	enemies.push_back(Enemy(mySprites.heroTexture, Vector2f(2100, 1700), Vector2i(ZOMBIE_SIZE), "EnemyFollow", FOLLOW_HP_2, 9));
	enemies.push_back(Enemy(mySprites.heroTexture, Vector2f(2100, 800), Vector2i(ZOMBIE_SIZE), "EnemyFollow", FOLLOW_HP_2, 6));
	enemies.push_back(Enemy(mySprites.heroTexture, Vector2f(2450, 1100), Vector2i(ZOMBIE_SIZE), "EnemyFollow", FOLLOW_HP_2, 6));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(2200, 900), Vector2i(WORM_SIZE), "Worm", WORM_HP_2, 6));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(2200, 200), Vector2i(WORM_SIZE), "Worm", WORM_HP_2, 3));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(2400, 300), Vector2i(WORM_SIZE), "Worm", WORM_HP_2, 3));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(2300, 400), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_2, 3));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(2600, 450), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_2, 3));

}

void Game::InitLevelThreeEnemies()
{
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(250, 440), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_3, 1));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(1200, 200), Vector2i(WORM_SIZE), "Worm", WORM_HP_3, 2));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(1550, 400), Vector2i(WORM_SIZE), "Worm", WORM_HP_3, 2));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, Vector2f(2100, 250), Vector2i(STAND_AND_SHOOT_SIZE), "EnemyStandAndShoot", STAND_AND_SHOOT_HP_3, 3));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, Vector2f(2500, 350), Vector2i(STAND_AND_SHOOT_SIZE), "EnemyStandAndShoot", STAND_AND_SHOOT_HP_3, 3));
	enemies.push_back(Enemy(mySprites.standAndShootTexture, Vector2f(2300, 350), Vector2i(STAND_AND_SHOOT_SIZE), "EnemyStandAndShoot", STAND_AND_SHOOT_HP_3, 3));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(1300, 800), Vector2i(WORM_SIZE), "Worm", WORM_HP_3, 5));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(1500, 800), Vector2i(WORM_SIZE), "Worm", WORM_HP_3, 5));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(1450, 1050), Vector2i(WORM_SIZE), "Worm", WORM_HP_3, 5));
	enemies.push_back(Enemy(mySprites.heroTexture, Vector2f(2450, 1100), Vector2i(ZOMBIE_SIZE), "EnemyFollow", FOLLOW_HP_3, 6));
	enemies.push_back(Enemy(mySprites.heroTexture, Vector2f(300, 1500), Vector2i(ZOMBIE_SIZE), "EnemyFollow", FOLLOW_HP_3, 7));
	enemies.push_back(Enemy(mySprites.heroTexture, Vector2f(450, 1750), Vector2i(ZOMBIE_SIZE), "EnemyFollow", FOLLOW_HP_3, 7));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(1600, 1580), Vector2i(WORM_SIZE), "Worm", WORM_HP_3, 8));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(1300, 1750), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_3, 8));
	enemies.push_back(Enemy(mySprites.enemyTexture, Vector2f(1500, 1450), Vector2i(FLY_SIZE), "EnemyFly", FLY_HP_3, 8));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(2100, 1600), Vector2i(WORM_SIZE), "Worm", WORM_HP_3, 9));
	enemies.push_back(Enemy(mySprites.wormTexture, Vector2f(2400, 1650), Vector2i(WORM_SIZE), "Worm", WORM_HP_3, 9));
	enemies.push_back(Enemy(mySprites.heroTexture, Vector2f(2600, 1450), Vector2i(ZOMBIE_SIZE), "EnemyFollow", FOLLOW_HP_3, 9));
}

void Game::InitEnemies()
{
	switch (level)
	{
	case ONE: InitLevelOneEnemies();
		break;
	case TWO: InitLevelTwoEnemies();
		break;
	case THREE: InitLevelThreeEnemies();
		break;
	case BOSS: boss = Boss(mySprites.bossTexture, Vector2f(200, 320), Vector2i(80, 112), "Boss", BOSS_HEALTH, 1);
		break;
	default:
		break;
	}
}

void Game::InitGame(RenderWindow& window)
{
	Image icon;
	icon.loadFromFile("resources/images/icon.png");
	window.setIcon(36, 30, icon.getPixelsPtr());
	level = ONE;
	lastShootPlayer = 0;
	volume = 30;
	gameState = MAIN_MENU;
	InitEnemies();
	player = Player(mySprites.heroTexture, Vector2f(PLAYER_POSITION_X - 100, PLAYER_POSITION_Y + 700), Vector2i(PLAYER_SIZE), "Hero", 6, mySprites.headTexture);
	view.reset(FloatRect(0, float(WINDOW_HEIGHT), float(WINDOW_WIDTH), float(WINDOW_HEIGHT)));
	myTileMap.InitMap(myMap, level);
	mySprites.InitImages();
	mySprites.LoadFont();
	menu.InitMenu(mySprites.mainMenuTexture, mySprites.font);
	isKeyPressed = false;
	mySounds.LoadMusic();
	mySounds.menuMusic.play();
}

void Game::ResetData()
{
	myMap.clear();
	enemies.clear();
	bullets.clear();
	chests.clear();
	gameTimer.restart();
	clock.restart();
	boomb.currentFrame = 0;
	player.lastBombPlant = 0;
	boomb.position = { -TILE_SIDE, -TILE_SIDE };
	boss.sprite.setPosition(-TILE_SIDE, -TILE_SIDE);
	boomb.explosionTime = 0;
	boomb.createTime = 0;
	boomb.isAlive = false;
	player.lastHitTime = 0;
	player.hitTimer = 0;
}

void Game::Restart()
{
	ResetData();
	lastShootPlayer = 0;
	room = FIRST;
	volume = 30;
	InitEnemies();
	player.position = { PLAYER_POSITION_X, PLAYER_POSITION_Y + 700 };
	view.reset(FloatRect(0, float(WINDOW_HEIGHT), float(WINDOW_WIDTH), float(WINDOW_HEIGHT)));
	myTileMap.InitMap(myMap, level);
	mySprites.InitImages();
	mySounds.LoadMusic();
	menu.InitMenu(mySprites.mainMenuTexture, mySprites.font);
	isKeyPressed = false;
	mySounds.menuMusic.play();
}

void Game::InitializeRoom()
{
	if (player.position.x > 0 && player.position.x < WINDOW_WIDTH)
	{
		if (player.position.y > 0 && player.position.y < WINDOW_HEIGHT)
		{
			room = FIRST;
		}
		else if (player.position.y > WINDOW_HEIGHT && player.position.y < WINDOW_HEIGHT * 2)
		{
			room = FORTH;
		}
		else if (player.position.y > WINDOW_HEIGHT * 2 && player.position.y < WINDOW_HEIGHT * 3)
		{
			room = SEVENTH;
		}
	}
	else if (player.position.x > WINDOW_WIDTH && player.position.x < WINDOW_WIDTH * 2)
	{
		if (player.position.y > 0 && player.position.y < WINDOW_HEIGHT)
		{
			room = SECOND;
		}
		else if (player.position.y > WINDOW_HEIGHT && player.position.y < WINDOW_HEIGHT * 2)
		{
			room = FIFTH;
		}
		else if (player.position.y > WINDOW_HEIGHT * 2 && player.position.y < WINDOW_HEIGHT * 3)
		{
			room = EIGHTH;
		}
	}
	else if (player.position.x > WINDOW_WIDTH * 2 && player.position.x < WINDOW_WIDTH * 3)
	{
		if (player.position.y > 0 && player.position.y < WINDOW_HEIGHT)
		{
			room = THIRD;
		}
		else if (player.position.y > WINDOW_HEIGHT && player.position.y < WINDOW_HEIGHT * 2)
		{
			room = SIXTH;
		}
		else if (player.position.y > WINDOW_HEIGHT * 2 && player.position.y < WINDOW_HEIGHT * 3)
		{
			room = NINTH;
		}
	}
}

void Game::SetPauseText()
{
	continueText.setString("CONTINUE?");
	continueText.setFont(mySprites.font);
	continueText.setCharacterSize(28);
	continueText.setRotation(5);
	continueText.setOrigin(continueText.getGlobalBounds().width / 2, continueText.getGlobalBounds().height / 2);
	continueText.setPosition(view.getCenter().x + 5, view.getCenter().y - 120);

	exitText.setString("EXIT");
	exitText.setFont(mySprites.font);
	exitText.setCharacterSize(28);
	exitText.setRotation(5);
	exitText.setOrigin(exitText.getGlobalBounds().width / 2, exitText.getGlobalBounds().height / 2);
	exitText.setPosition(view.getCenter().x - 10, view.getCenter().y + 100);

	menuText.setString("GO TO MENU");
	menuText.setFont(mySprites.font);
	menuText.setCharacterSize(28);
	menuText.setRotation(5);
	menuText.setOrigin(menuText.getGlobalBounds().width / 2, menuText.getGlobalBounds().height / 2);
	menuText.setPosition(view.getCenter().x, view.getCenter().y + 40);
}

void Game::CheckMouseIntersectionWithTextPause(RenderWindow& window)
{
	Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (continueText.getGlobalBounds().contains(mousePos))
	{
		continueText.setColor(COLOR_WHILE_MOUSE_ON_TEXT);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			gameState = GAME;
		}
	}
	else if (menuText.getGlobalBounds().contains(mousePos))
	{
		menuText.setColor(COLOR_WHILE_MOUSE_ON_TEXT);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			gameState = MAIN_MENU;
		}
	}
	else if (exitText.getGlobalBounds().contains(mousePos))
	{
		exitText.setColor(COLOR_WHILE_MOUSE_ON_TEXT);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			window.close();
		}
	}
	else
	{
		continueText.setColor(Color::White);
		menuText.setColor(Color::White);
		exitText.setColor(Color::White);
	}
}

void Game::InitSheetAndBackground(RenderWindow& window)
{
	pauseRect.setFillColor(Color(0, 0, 0, 150));
	pauseRect.setSize(Vector2f(view.getSize().x, view.getSize().y));
	pauseRect.setOrigin(pauseRect.getSize().x / 2, pauseRect.getSize().y / 2);
	pauseRect.setPosition(view.getCenter());

	pauseSprite.setTexture(mySprites.pauseTexture);
	pauseSprite.setOrigin(pauseSprite.getGlobalBounds().width / 2, pauseSprite.getGlobalBounds().height / 2);
	pauseSprite.setPosition(view.getCenter());
}

void Game::SetPause(RenderWindow& window)
{
	InitSheetAndBackground(window);
	SetPauseText();
	CheckMouseIntersectionWithTextPause(window);
}

void Game::SetEndGameText(RenderWindow& window)
{
	if (gameState == END_GAME)
	{
		continueText.setString("YOU LOSE\n\nTRY AGAIN?");
	}
	else
	{
		continueText.setString("WIN\n\nTRY AGAIN?");
	}
	continueText.setFont(mySprites.font);
	continueText.setCharacterSize(35);
	continueText.setRotation(5);
	continueText.setOrigin(continueText.getGlobalBounds().width / 2, continueText.getGlobalBounds().height / 2);
	continueText.setPosition(view.getCenter().x + 5, view.getCenter().y - 100);

	exitText.setString("YES");
	exitText.setFont(mySprites.font);
	exitText.setCharacterSize(28);
	exitText.setRotation(5);
	exitText.setOrigin(exitText.getGlobalBounds().width / 2, exitText.getGlobalBounds().height / 2);
	exitText.setPosition(view.getCenter().x - 50, view.getCenter().y + 40);

	menuText.setString("NO");
	menuText.setFont(mySprites.font);
	menuText.setCharacterSize(28);
	menuText.setRotation(5);
	menuText.setOrigin(menuText.getGlobalBounds().width / 2, menuText.getGlobalBounds().height / 2);
	menuText.setPosition(view.getCenter().x + 50, view.getCenter().y + 40);
}

void Game::CheckMouseIntersectionWithTextEnd(RenderWindow& window)
{
	Vector2f mousePos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
	if (menuText.getGlobalBounds().contains(mousePos))
	{
		menuText.setColor(COLOR_WHILE_MOUSE_ON_TEXT);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			level = ONE;
			Restart();
			player = Player(mySprites.heroTexture, Vector2f(PLAYER_POSITION_X - 100, PLAYER_POSITION_Y + 700), Vector2i(PLAYER_SIZE), "Hero", 6, mySprites.headTexture);
			gameState = MAIN_MENU;
		}
	}
	else if (exitText.getGlobalBounds().contains(mousePos))
	{
		exitText.setColor(COLOR_WHILE_MOUSE_ON_TEXT);
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			level = ONE;
			Restart();
			player = Player(mySprites.heroTexture, Vector2f(PLAYER_POSITION_X - 100, PLAYER_POSITION_Y + 700), Vector2i(PLAYER_SIZE), "Hero", 6, mySprites.headTexture);
			gameState = GAME;
		}
	}
	else
	{
		menuText.setColor(Color::White);
		exitText.setColor(Color::White);
	}
}

void Game::EndGame(RenderWindow& window)
{
	InitSheetAndBackground(window);
	SetEndGameText(window);
	CheckMouseIntersectionWithTextEnd(window);
}

bool Game::RemoveEnemyFromVector()
{
	for (auto& enemy : enemies)
	{
		if (enemy.alive == true)
		{
			return false;
		}
	}
	return true;
}

void Game::UpdateEnemies(RenderWindow& window)
{
	if (RemoveEnemyFromVector() == true)
	{
		enemies.clear();
	}
	for (auto& enemy: enemies)
	{
		if (enemy.alive == true)
		{
			if (room == enemy.enemyRoom)
			{
				enemy.MoveFollowEnemy(gameTime, player.position, myMap, time, enemies);
				enemy.UpdateHeadFrame(mySprites.enemyFollowHead, gameTime);
				enemy.UpdateFly(time, myMap);
				enemy.UpdateStandAndShoot(bullets, gameTime);
				enemy.UpdateWorm(myMap, enemies, gameTime, time);
				enemy.Update(boomb, gameTime, player.position);
				
			}
			else
			{
				enemy.clock.restart();
			}
			enemy.ExplosionCollision(boomb, gameTime);
			enemy.deathTime = gameTime;
		}
		enemy.isNeedRemove(gameTime);
	}
}

void Game::UpdatePlayer()
{
	player.Moving(time, myMap, view, IsRoomCleared(), mySprites.wallBackgroundSprite);
	player.CheckEnemyCollidesPlayer(enemies, boss, gameTime, mySounds.playerHurts);
	player.ChangeColorAfterHit(gameTime);
	player.CheckExplosionCollision(boomb, gameTime, mySounds.playerHurts);
	player.SpikeCollision(myMap, gameTime, mySounds.playerHurts);
}

void Game::UpdateChests(RenderWindow& window)
{
	for (auto& chest: chests)
	{
		chest.UpdateDrawText(mySprites.font, window, view);
		if (chest.room == room)
		{
			chest.Update(player, mySounds.chestOpening, mySprites);
		}
	}
}

void Game::DeleteBulletFromVector()
{
	auto isDead = [](Bullet bullet) 
	{
		return (bullet.isDel);
	};
	bullets.erase(remove_if(bullets.begin(), bullets.end(), isDead), bullets.end());
}

void Game::UpdatePlayersBullets(Bullet& bullet)
{
	if (bullet.isPlayers == true)
	{
		for (auto& enemy : enemies)
		{
			if (enemy.health > 0)
			{
				if (Collision::PixelPerfectTest(enemy.sprite, bullet.bulletSprite) && enemy.sprite.getPosition().x != 0)
				{
					bullet.deathTime = gameTime;
					bullet.alive = false;
					enemy.health -= bullet.damage;
					enemy.playerHitTime = gameTime;
					mySounds.tearDestroy.play();
				}
				else if (Collision::PixelPerfectTest(enemy.headSprite, bullet.bulletSprite) && enemy.name == "EnemyFollow")
				{
					bullet.deathTime = gameTime;
					bullet.alive = false;
					enemy.health -= bullet.damage;
					enemy.playerHitTime = gameTime;
					mySounds.tearDestroy.play();
				}
			}
		}
		if (Collision::PixelPerfectTest(boss.sprite, bullet.bulletSprite) && boss.alive == true)
		{
			if (boss.state == STAY || boss.state == SHOOT)
			{
				bullet.deathTime = gameTime;
				bullet.alive = false;
				boss.health -= bullet.damage;
				boss.playerHitTime = gameTime;
				mySounds.tearDestroy.play();
			}
		}
	}
}

void Game::UpdateEnemiesBullets(Bullet& bullet)
{
	if (bullet.isPlayers == false)
	{
		if (Collision::PixelPerfectTest(player.sprite, bullet.bulletSprite) || Collision::PixelPerfectTest(player.headSprite, bullet.bulletSprite))
		{
			bullet.alive = false;
			player.health -= bullet.damage;
			player.lastHitTime = gameTime;
			mySounds.playerHurts.play();
			mySounds.tearDestroy.play();		
		}
	}
}

void Game::UpdateBullets(RenderWindow& window)
{
	for (auto& bullet: bullets)
	{
		if (bullet.alive == true)
		{
			if (gameState == GAME)
			{
				UpdatePlayersBullets(bullet);
				UpdateEnemiesBullets(bullet);
				bullet.UpdateBullet(time, window, gameTime, mySprites.bulletTexture, mySprites.bulletEffectTexture, mySprites.bulletEffectTextureEnemy);
				bullet.CheckCollisionBullet(gameTime, myMap, mySprites.wallBulletSprite, mySounds.tearDestroy);
				bullet.DeleteBullet(gameTime, mySounds.tearDestroy, player.range);
			}
			bullet.DrawBullet(window);
		}
		else
		{
			bullet.BulletDestroyEffect(gameTime, window);
		}
	}
	DeleteBulletFromVector();
}

void Game::UpdateBombs()
{
	boomb.Update(gameTime);
	boomb.PlaySound(mySounds.bombExplosion, gameTime);
	for (auto& map : myMap)
	{
		if (map.sprite.getGlobalBounds().intersects(boomb.damageZone.getGlobalBounds()) && map.pos == ROCK)
		{
			map.alive = false;
		}
	}
	auto isDestroyed = [](Map map)
	{
		return (map.alive == false);
	};
	myMap.erase(remove_if(myMap.begin(), myMap.end(), isDestroyed), myMap.end());
}

void Game::UpdateTime()
{
	if (player.health > 0)
	{
		gameTime = gameTimer.getElapsedTime().asSeconds();
	}
}

void Game::UpdateTimePerFrame()
{
	time = float(clock.getElapsedTime().asMicroseconds());
	clock.restart();
	time = time / GAME_TIME_DIFFERENCE;
}

void Game::UpdateMusic()
{
	mySounds.UpdateMusic(volume, level);
}

void Game::ProcessEvents(RenderWindow& window)
{
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			window.close();
	}
	if (gameState == GAME && window.hasFocus())
	{
		player.Control(boomb, bullets, time, gameTime, lastShootPlayer, mySounds.tearFire);
	}
}

void Game::UpdatePause()
{
	if (Keyboard::isKeyPressed(Keyboard::Escape) && isKeyPressed == false)
	{
		isKeyPressed = true;
		if (gameState == GAME)
		{
			gameState = PAUSE;
		}
		else
		{
			gameState = GAME;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Escape) == false)
	{
		isKeyPressed = false;
	}
}

void Game::SetMainMenuMusic()
{
	mySounds.backgroundMusic1.stop();
	mySounds.backgroundMusic2.stop();
	mySounds.backgroundMusic3.stop();
	if (mySounds.menuMusic.getStatus() == false)
	{
		mySounds.menuMusic.play();
	}
}

void Game::CheckEndGame()
{
	if (player.health <= 0)
	{
		gameState = END_GAME;
		level = ONE;
	}
	if (boss.alive == false)
	{
		if (level == BOSS)
		{
			gameState = FINISHED;
		}
	}
}

void Game::UpdateBoss()
{
	boss.UpdateAlive();
	if (boss.bossRoom == room && level == BOSS)
	{
		boss.Update(bullets, gameTime, player.position, time);
		boss.PlaySound(mySounds.bossLands, mySounds.bossShoots, mySounds.bossDies);
		boss.ExplosionCollision(boomb, gameTime);
	}
	else
	{
		boss.clock.restart();
	}
}

void Game::UpdateGame(RenderWindow& window)
{
	UpdatePause();
	UpdateTimePerFrame();
	if (gameState == MAIN_MENU)
	{
		SetMainMenuMusic();
		menu.Update(volume, view);
	}
	else if (gameState == GAME)
	{
		mySounds.menuMusic.stop();
		AddChest(view);
		UpdatePlayer();
		UpdateTime();
		UpdateEnemies(window);
		UpdateChests(window);
		UpdateBombs();
		UpdateMusic();
		CheckEndGame();
		UpdateBoss();
		InitializeRoom();
	}
	else if (gameState != PAUSE)
	{
		boomb.damageZone.setPosition(-TILE_SIDE * 2, -TILE_SIDE * 2);
		EndGame(window);
	}
	ProcessEvents(window);
}

void Game::DrawHelp(RenderWindow& window)
{
	Sprite controlsSprite;
	Text helpText;
	Text taskText;
	if (room == 4 && level == ONE)
	{
		controlsSprite.setTexture(mySprites.controlsTexture);
		float x = controlsSprite.getGlobalBounds().width / 2;
		float y = controlsSprite.getGlobalBounds().height / 2;

		controlsSprite.setOrigin(x, y);
		controlsSprite.setPosition(view.getCenter().x, view.getCenter().y - 80);

		helpText.setColor(Color::Black);
		taskText.setColor(Color::Black);
		helpText.setFont(mySprites.font);
		taskText.setFont(mySprites.font);
		helpText.setCharacterSize(15);
		taskText.setCharacterSize(15);
		helpText.setString("You can destroy rocks with bombs");
		taskText.setString("To go to next level you need to clear each room\nThe portal is in the right-up room\nAfter clearing all levels kill boss");
		helpText.setOrigin(helpText.getGlobalBounds().width / 2, helpText.getGlobalBounds().height / 2);
		taskText.setOrigin(taskText.getGlobalBounds().width / 2, taskText.getGlobalBounds().height / 2);
		helpText.setPosition(view.getCenter().x, view.getCenter().y + 50);
		taskText.setPosition(view.getCenter().x, view.getCenter().y + 100);

		window.draw(controlsSprite);
		window.draw(helpText);
		window.draw(taskText);
	}
}

void Game::DrawBackground(RenderWindow& window)
{
	mySprites.wallBackgroundSprite.setOrigin(mySprites.wallBackgroundSprite.getGlobalBounds().width / 2, mySprites.wallBackgroundSprite.getGlobalBounds().height / 2);
	mySprites.wallBackgroundSprite.setPosition(view.getCenter().x, view.getCenter().y);
	mySprites.floorBackgroundSprite.setOrigin(mySprites.floorBackgroundSprite.getGlobalBounds().width / 2, mySprites.floorBackgroundSprite.getGlobalBounds().height / 2);
	mySprites.floorBackgroundSprite.setPosition(view.getCenter().x, view.getCenter().y);
	mySprites.wallBulletSprite.setOrigin(mySprites.wallBulletSprite.getGlobalBounds().width / 2, mySprites.wallBulletSprite.getGlobalBounds().height / 2);
	mySprites.wallBulletSprite.setPosition(view.getCenter().x, view.getCenter().y);
	

	window.draw(mySprites.wallBackgroundSprite);
	window.draw(mySprites.floorBackgroundSprite);
	window.draw(mySprites.wallBulletSprite);

	DrawHelp(window);
}

void Game::DrawBombCount(RenderWindow& window)
{
	Sprite bombCountSprite;
	bombCountSprite.setTexture(mySprites.bombCount);
	bombCountSprite.setPosition(view.getCenter().x - WINDOW_WIDTH / 2 + BOMB_IMAGE_SHIFT.x, view.getCenter().y - WINDOW_HEIGHT / 2 + BOMB_IMAGE_SHIFT.y);
	bombCountSprite.setScale(BOMB_IMAGE_SCALE, BOMB_IMAGE_SCALE);
	window.draw(bombCountSprite);

	Text textBombs;
	textBombs.setFont(mySprites.font);
	textBombs.setPosition(view.getCenter().x - WINDOW_WIDTH / 2 + TEXT_SHIFT.x, view.getCenter().y - WINDOW_HEIGHT / 2 + TEXT_SHIFT.y);
	textBombs.setCharacterSize(FONT_INTERFACE_SIZE);

	textBombs.setString(to_string(player.bombCount));

	window.draw(textBombs);
}

void Game::DrawPlayersHealth(RenderWindow& window)
{
	Sprite fullHP;
	fullHP.setTexture(mySprites.heartTexture);
	fullHP.setTextureRect(IntRect(0, 0, HEALTH_TEXTURE_SIZE, HEALTH_TEXTURE_SIZE));
	fullHP.setScale(HP_SCALE, HP_SCALE);
	Sprite halfHP;
	halfHP.setTexture(mySprites.heartTexture);
	halfHP.setTextureRect(IntRect(HEALTH_TEXTURE_SIZE, 0, HEALTH_TEXTURE_SIZE, HEALTH_TEXTURE_SIZE));
	halfHP.setScale(HP_SCALE, HP_SCALE);
	Sprite emptySprite;
	emptySprite.setTexture(mySprites.heartTexture);
	emptySprite.setTextureRect(IntRect(HEALTH_TEXTURE_SIZE * 2, 0, HEALTH_TEXTURE_SIZE, HEALTH_TEXTURE_SIZE));
	emptySprite.setScale(HP_SCALE, HP_SCALE);

	for (int i = 1; i <= MAX_PLAYER_HEALTH; i++)
	{
		emptySprite.setPosition(view.getCenter().x - WINDOW_WIDTH / 2 + i * HP_SHIFT.x, view.getCenter().y - WINDOW_HEIGHT / 2 + HP_SHIFT.y);
		window.draw(emptySprite);
	}
	if (player.health > 0)
	{
		for (int i = 1; i <= player.health; i++)
		{
			fullHP.setPosition(view.getCenter().x - WINDOW_WIDTH / 2 + i * HP_SHIFT.x, view.getCenter().y - WINDOW_HEIGHT / 2 + HP_SHIFT.y);
			window.draw(fullHP);
		}
		if (player.health - int(player.health) != 0)
		{
			halfHP.setPosition(view.getCenter().x - WINDOW_WIDTH / 2 + int(player.health + 1) * HP_SHIFT.x, view.getCenter().y - WINDOW_HEIGHT / 2 + HP_SHIFT.y);
			window.draw(halfHP);
		}
	}
}

void Game::DrawEnemies(RenderWindow& window)
{
	for (auto& enemy: enemies)
	{
		if (enemy.alive == true)
		{
			if (enemy.enemyRoom == room)
			{
				window.draw(enemy.sprite);
				if (enemy.name == "EnemyFollow")
				{
					window.draw(enemy.headSprite);
				}
			}
		}
		else
		{
			enemy.DestroyEffect(gameTime, window, mySprites.poofTexture, time, mySounds.flyHurt, mySounds.enemyHurt);
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
	boomb.Draw(window, mySprites.bombState, mySprites.bombExplosion, gameTime, time);	
}

bool Game::IsRoomCleared()
{
	bool isAllDead = true;

	for (auto& enemy: enemies)
	{
		if (enemy.enemyRoom == room && enemy.health > 0)
		{
			return false;
		}
	}
	if (myTileMap.isOpened == false)
	{
		mySounds.doorOpening.play();
	}
	return true;
}

bool Game::IsRoomEmpty()
{
	bool isEmpty = true;

	for (auto& enemy : enemies)
	{
		if (enemy.enemyRoom == room)
		{
			isEmpty = false;
		}
	}
	return isEmpty;
}

bool Game::IsChestInRoom()
{
	bool isChestInRoom = false;

	for (auto& chest: chests)
	{
		if (room == chest.room)
		{
			isChestInRoom = true;
		}
	}
	return isChestInRoom;
}

void Game::AddChest(View& view)
{
	if (IsRoomCleared() && !IsRoomEmpty())
	{
		if (IsChestInRoom() == false)
		{
			chests.push_back(Chest(Vector2f(view.getCenter().x, view.getCenter().y - TILE_SIDE / 2), room));
			mySounds.chestDrop.play();
		}
	}
}

void Game::DrawMap(RenderWindow& window)
{
	myTileMap.DrawTiles(myMap, window, IsRoomCleared());
}

void Game::DrawChest(RenderWindow& window)
{
	for (auto& chest: chests)
	{
		if (chest.room == room)
		{
			chest.DrawText(window, gameTime, player.position.y, view);
			chest.DrawChest(window, mySprites);
		}
		
	}
}

void Game::SetCorrectDrawOrder(RenderWindow& window)
{
	if (player.position.y + player.size.y < boomb.position.y + TILE_SIDE)
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

void Game::JumpNextLevel(RenderWindow& window)
{
	if (enemies.size() == 0 && gameState != BOSS)
	{
		Sprite manholeSprite;
		manholeSprite.setTexture(mySprites.manholeTexture);
		manholeSprite.setPosition(WINDOW_WIDTH * 3 - WINDOW_WIDTH / 2 - TILE_SIDE, TILE_SIDE * 2);
		window.draw(manholeSprite);
		if (Collision::PixelPerfectTest(player.sprite, manholeSprite))
		{
			switch (level)
			{
			case ONE: level = TWO; break;
			case TWO: level = THREE; break;
			case THREE: level = BOSS; break;
			}
			Restart();
			gameState = GAME;
		}
	}
}

void Game::DrawPause(RenderWindow& window)
{
	window.draw(pauseRect);
	window.draw(pauseSprite);
	window.draw(continueText);
	window.draw(menuText);
	window.draw(exitText);
}

void Game::DrawEndGame(RenderWindow& window)
{
	window.draw(pauseRect);
	window.draw(pauseSprite);
	window.draw(continueText);
	window.draw(menuText);
	window.draw(exitText);
}

void Game::DrawBoss(RenderWindow& window)
{
	if (boss.bossRoom == room && level == BOSS)
	{
		boss.Draw(window);
		boss.DrawHealth(mySprites.healthBar, window);
	}
}

void Game::DrawWindow(RenderWindow& window)
{
	window.setView(view);
	if (gameState == MAIN_MENU)
	{
		menu.Draw(window, gameState, event);
	}
	else
	{
		DrawBackground(window);
		DrawMap(window);
		DrawPlayersHealth(window);
		DrawBombCount(window);
		DrawChest(window);
		JumpNextLevel(window);
		SetCorrectDrawOrder(window);
		UpdateBullets(window);
		DrawEnemies(window);
		DrawBoss(window);
		if (gameState == PAUSE)
		{
			SetPause(window);
			DrawPause(window);
		}
		else if (gameState == END_GAME || gameState == FINISHED)
		{
			DrawEndGame(window);
		}
	}
}

