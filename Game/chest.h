#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <random>
#include "time.h"

#include "player.h"
#include "constants.h"
#include "collision.h"
#include "sprites.h"

using namespace sf;

struct Chest
{
	ChestFilling filling;
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
	bool isPresentTaken;
	bool isOpened;

	Chest() {};
	Chest(Vector2f pos, int Room)
	{
		position.x = pos.x;
		position.y = pos.y;
		chestTexture.loadFromFile("resources/images/chest.png");
		chestSpriteOpened.setTextureRect(IntRect(64, 0, 64, 64));
		chestSpriteClosed.setTextureRect(IntRect(0, 0, 64, 64));
		size.x = int(chestSpriteClosed.getGlobalBounds().height);
		size.y = int(chestSpriteClosed.getGlobalBounds().width);
		room = Room;
		isPresentTaken = false;
		isOpened = false;
	}

	void SetFilling();
	void CheckOpening(Player& p, Sound& openingSound);

	void GiveFirstPresent(RenderWindow& window, Sprite& increaseSpeedSprite);
	void GiveSecondPresent(RenderWindow & window, Sprite & increaseDamageSprite);
	void GiveThirdPresent(RenderWindow & window, Sprite & healthSprite);
	void GiveForthPresent(RenderWindow & window, Sprite & bombSprite);

	void GiveFifthPresent(RenderWindow & window, Sprite & bombSprite);

	void GiveSixthPresent(RenderWindow & window, Sprite & fireRateUp);

	void SetPresent(RenderWindow & window, Sprites& mySprites);
	void CheckCollisionWithPresent(Player& p, Sprites& mySprites);

	void UpdateDrawText(Font& font, RenderWindow& window, View& view);

	void DrawText(RenderWindow & window, float & gameTime, float& playerY, View& view);

	void Update(Player& p, Sound& openingSound, Sprites& mySprites);

	void DrawChest(RenderWindow& window, Sprites& mySprites);
};
