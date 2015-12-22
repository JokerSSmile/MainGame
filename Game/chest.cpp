#include "chest.h"


void Chest::LoadTextures()
{
	if (areTexturesLoaded == false)
	{
		increaseSpeedTexture.loadFromFile("images/increaseSpeed.png");
		IncreaseDamageTexture.loadFromFile("images/IncreaseDamage.png");
		HealthTexture.loadFromFile("images/addHeart.png");
		BombTexture.loadFromFile("images/addBomb.png");

		increaseSpeedSprite.setTexture(increaseSpeedTexture);
		increaseDamageSprite.setTexture(IncreaseDamageTexture);
		healthSprite.setTexture(HealthTexture);
		bombSprite.setTexture(BombTexture);

		increaseSpeedSprite.setOrigin(increaseSpeedSprite.getGlobalBounds().width / 2, increaseSpeedSprite.getGlobalBounds().height / 2);
		increaseDamageSprite.setOrigin(increaseDamageSprite.getGlobalBounds().width / 2, increaseDamageSprite.getGlobalBounds().height / 2);
		healthSprite.setOrigin(healthSprite.getGlobalBounds().width / 2, healthSprite.getGlobalBounds().height / 2);
		bombSprite.setOrigin(bombSprite.getGlobalBounds().width / 2, bombSprite.getGlobalBounds().height / 2);

		increaseSpeedSprite.setScale(1.5, 1.5);
		increaseDamageSprite.setScale(1.5, 1.5);
		healthSprite.setScale(1.5, 1.5);
		bombSprite.setScale(1.5, 1.5);

		areTexturesLoaded = true;
	}
}

int Chest::RandomNumber()
{
	return (double)rand() / (RAND_MAX + 1) * 4;
}

void Chest::SetFilling()
{
	int rand = RandomNumber();
	if (rand == 0)
	{
		filling = IncreaseSpeed;
	}
	else if (rand == 1)
	{
		filling = IncreaseDamage;
	}
	else if (rand == 2)
	{
		filling = Health;
	}
	else if (rand == 3)
	{
		filling = Bomb;
	}
}

void Chest::CheckOpening(Player& p)
{
	if (Collision::PixelPerfectTest(p.sprite, chestSpriteClosed))
	{
		isOpened = true;
	}
}

void Chest::GiveFirstPresent(RenderWindow& window)
{
	increaseSpeedSprite.setPosition(x, y + TILE_SIDE / 2);
	window.draw(increaseSpeedSprite);
}

void Chest::GiveSecondPresent(RenderWindow& window)
{
	increaseDamageSprite.setPosition(x, y + TILE_SIDE / 2);
	window.draw(increaseDamageSprite);
}

void Chest::GiveThirdPresent(RenderWindow& window)
{
	healthSprite.setPosition(x, y + TILE_SIDE / 2);
	window.draw(healthSprite);
}

void Chest::GiveForthPresent(RenderWindow& window)
{
	bombSprite.setPosition(x, y + TILE_SIDE / 2);
	window.draw(bombSprite);
}

void Chest::SetPresent(RenderWindow& window)
{
	switch (filling)
	{
	case IncreaseSpeed: GiveFirstPresent(window); break;
	case IncreaseDamage: GiveSecondPresent(window); break;
	case Health: GiveThirdPresent(window); break;
	case Bomb: GiveForthPresent(window); break;
	}
}

void Chest::CheckCollisionWithPresent(Player& p)
{
	if (Collision::PixelPerfectTest(p.sprite, increaseSpeedSprite))
	{
		isPresentTaken = true;
		p.speed += SPEED_BONUS;
	}
	else if (Collision::PixelPerfectTest(p.sprite, increaseDamageSprite))
	{
		isPresentTaken = true;
		p.damage += DAMAGE_BONUS;
	}
	else if (Collision::PixelPerfectTest(p.sprite, healthSprite))
	{
		isPresentTaken = true;
		if (p.health >= MAX_PLAYER_HEALTH - 1)
		{
			p.health = MAX_PLAYER_HEALTH;
		}
		else
		{
			p.health += HEAL_BONUS;
		}
	}
	else if (Collision::PixelPerfectTest(p.sprite, bombSprite))
	{
		isPresentTaken = true;
		p.bombCount += BOMB_BONUS;
	}
}

void Chest::Update(Player& p)
{
	chestSpriteOpened.setTexture(chestTexture);
	chestSpriteClosed.setTexture(chestTexture);
	LoadTextures();
	if (isOpened == false)
	{
		SetFilling();
		chestSpriteClosed.setPosition(x - w / 2, y - h / 2);
		CheckOpening(p);
	}
	else
	{
		chestSpriteOpened.setPosition(x - w / 2, y - h / 2);
		if (isPresentTaken == false)
		{
			CheckCollisionWithPresent(p);
		}
	}
}

void Chest::DrawChest(RenderWindow& window)
{
	if (isOpened == false)
	{
		window.draw(chestSpriteClosed);
	}
	else
	{
		if (chestSpriteOpened.getPosition().x != 0)
		{
			window.draw(chestSpriteOpened);
		}
		if (isPresentTaken == false)
		{
			SetPresent(window);
		}
	}
}