#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <random>
#include "time.h"

#include "player.h"
#include "constants.h"
#include "collision.h"

using namespace sf;

static enum
{
	IncreaseSpeed, IncreaseDamage, Health, Bomb
} filling;

struct Chest
{
public:
	int level;
	float x;
	float y;
	int h;
	int w;
	Texture chestTexture;
	Texture increaseSpeedTexture;
	Texture IncreaseDamageTexture;
	Texture HealthTexture;
	Texture BombTexture;
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
		chestTexture.loadFromFile("resources/images/chest.png");
		chestSpriteOpened.setTextureRect(IntRect(64, 0, 64, 64));
		chestSpriteClosed.setTextureRect(IntRect(0, 0, 64, 64));
		h = int(chestSpriteClosed.getGlobalBounds().height);
		w = int(chestSpriteClosed.getGlobalBounds().width);
		level = Level;
	}

	void LoadTextures();
	int RandomNumber();
	void SetFilling();
	void CheckOpening(Player& p);

	void GiveFirstPresent(RenderWindow& window);
	void GiveSecondPresent(RenderWindow& window);
	void GiveThirdPresent(RenderWindow& window);
	void GiveForthPresent(RenderWindow& window);

	void SetPresent(RenderWindow& window);
	void CheckCollisionWithPresent(Player& p);

	void Update(Player& p);

	void DrawChest(RenderWindow& window);
};
