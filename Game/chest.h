#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <random>
#include "time.h"

using namespace sf;

enum
{
	IncreaseSpeed, IncreaseDamage, Health, Bomb
} filling;

struct Chest
{
private:
	Texture chestTexture;
	Texture increaseSpeedTexture;
	Texture IncreaseDamageTexture;
	Texture HealthTexture;
	Texture BombTexture;
public:
	int level;
	float x;
	float y;
	int h;
	int w;
	Sprite chestSpriteOpened;
	Sprite chestSpriteClosed;
	Sprite increaseSpeedSprite;
	Sprite increaseDamageSprite;
	Sprite healthSprite;
	Sprite bombSprite;

	bool isOpened = false;
	int present;
	bool areTexturesLoaded = false;
	bool isPresentTaken = false;
	Chest() {};
	Chest(float X, float Y, int Level)
	{
		x = X;
		y = Y;
		chestTexture.loadFromFile("images/chest.png");
		chestSpriteOpened.setTextureRect(IntRect(64, 0, 64, 64));
		chestSpriteClosed.setTextureRect(IntRect(0, 0, 64, 64));
		h = chestSpriteClosed.getGlobalBounds().height;
		w = chestSpriteClosed.getGlobalBounds().width;
		level = Level;
	}

	void LoadTextures()
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

	int RandomNumber()
	{
		return (double)rand() / (RAND_MAX + 1) * 4;
	}

	void SetFilling()
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

	void CheckOpening(Player& p)
	{
		if (Collision::PixelPerfectTest(p.sprite, chestSpriteClosed))
		{
			isOpened = true;
		}
	}

	void GiveFirstPresent(RenderWindow& window)
	{
		increaseSpeedSprite.setPosition(x, y + TILE_SIDE / 2);
		window.draw(increaseSpeedSprite);
	}

	void GiveSecondPresent(RenderWindow& window)
	{
		increaseDamageSprite.setPosition(x, y + TILE_SIDE / 2);
		window.draw(increaseDamageSprite);
	}

	void GiveThirdPresent(RenderWindow& window)
	{
		healthSprite.setPosition(x, y + TILE_SIDE / 2);
		window.draw(healthSprite);
	}

	void GiveForthPresent(RenderWindow& window)
	{
		bombSprite.setPosition(x, y + TILE_SIDE / 2);
		window.draw(bombSprite);
	}

	void SetPresent(RenderWindow& window)
	{
		switch (filling)
		{
		case IncreaseSpeed: GiveFirstPresent(window); break;
		case IncreaseDamage: GiveSecondPresent(window); break;
		case Health: GiveThirdPresent(window); break;
		case Bomb: GiveForthPresent(window); break;
		}
	}

	void CheckCollisionWithPresent(Player& p)
	{
		if (Collision::PixelPerfectTest(p.sprite, increaseSpeedSprite))
		{
			isPresentTaken = true;
			p.speed += 0.05;
		}
		else if (Collision::PixelPerfectTest(p.sprite, increaseDamageSprite))
		{
			isPresentTaken = true;
			p.damage += 0.5;
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
				p.health += 1;
			}
		}
		else if (Collision::PixelPerfectTest(p.sprite, bombSprite))
		{
			isPresentTaken = true;
			p.bombCount += 1;
		}
	}

	void Update(RenderWindow& window, Player& p)
	{
		chestSpriteOpened.setTexture(chestTexture);
		chestSpriteClosed.setTexture(chestTexture);
		LoadTextures();
		if (isOpened == false)
		{
			SetFilling();
			chestSpriteClosed.setPosition(x - w / 2, y - h / 2);
			CheckOpening(p);
			window.draw(chestSpriteClosed);
		}
		else
		{
			chestSpriteOpened.setPosition(x - w / 2, y - h / 2);
			window.draw(chestSpriteOpened);
			if (isPresentTaken == false)
			{
				SetPresent(window);
				CheckCollisionWithPresent(p);
			}
		}
	}
};
