#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "constants.h"

using namespace sf;
using namespace std;

struct Boomb
{
	Boomb() {};

	Vector2f position;
	Sprite bombSprite;
	Sprite explosionSprite;
	RectangleShape damageZone;

	float currentFrame = 0;
	float currentExplosionFrame = 0;
	float createTime = 0;
	float explosionTime;
	bool isAlive = false;

	void AnimationBombBeforeExplosion(Texture& playersBombTexture, float& gameTime, float& time);
	void ExplosionAnimation(Texture& bombExplosionTexture, float& gameTime, float& time);
	void Update(float& gameTime);
	void Draw(RenderWindow& window, Texture& playersBombTexture, Texture& bombExplosionTexture, float& gameTime, float& time);
};
