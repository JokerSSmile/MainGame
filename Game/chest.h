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

struct Chest
{
	enum
	{
		IncreaseSpeed, IncreaseDamage, Health, Bomb
	} filling;

	Vector2f position;
	Vector2i size;
	Texture chestTexture;
	Sprite chestSpriteOpened;
	Sprite chestSpriteClosed;
	Text bonusText;

	float verticalPosition;
	float takePresentTime;
	int present;
	int room;
	bool isPresentTaken = false;
	bool isOpened = false;

	Chest() {};
	Chest(float X, float Y, int Room)
	{
		position.x = X;
		position.y = Y;
		chestTexture.loadFromFile("resources/images/chest.png");
		chestSpriteOpened.setTextureRect(IntRect(64, 0, 64, 64));
		chestSpriteClosed.setTextureRect(IntRect(0, 0, 64, 64));
		size.x = int(chestSpriteClosed.getGlobalBounds().height);
		size.y = int(chestSpriteClosed.getGlobalBounds().width);
		room = Room;
	}

	//int RandomNumber();
	void SetFilling();
	void CheckOpening(Player& p, Sound& openingSound);

	void GiveFirstPresent(RenderWindow& window, Sprite& increaseSpeedSprite);
	void GiveSecondPresent(RenderWindow & window, Sprite & increaseDamageSprite);
	void GiveThirdPresent(RenderWindow & window, Sprite & healthSprite);
	void GiveForthPresent(RenderWindow & window, Sprite & bombSprite);

	void SetPresent(RenderWindow & window, Sprite & increaseSpeedSprite, Sprite & increaseDamageSprite, Sprite & healthSprite, Sprite & bombSprite);
	void CheckCollisionWithPresent(Player& p, Sprite& increaseSpeedSprite, Sprite& increaseDamageSprite, Sprite& healthSprite, Sprite& bombSprite);

	void UpdateDrawText(Font& font, RenderWindow& window, View& view);

	void DrawText(RenderWindow & window, float & gameTime, float& playerY, View& view);

	void Update(Player& p, Sound& openingSound, Sprite& increaseSpeedSprite, Sprite& increaseDamageSprite, Sprite& healthSprite, Sprite& bombSprite);

	void DrawChest(RenderWindow& window, Sprite& increaseSpeedSprite, Sprite& increaseDamageSprite, Sprite& healthSprite, Sprite& bombSprite);
};
