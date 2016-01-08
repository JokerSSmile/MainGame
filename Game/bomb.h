#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "constants.h"
#include "music.h"

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
	float explosionTime = 0;
	bool isAlive = false;

	void PlaySound(Sound& explosionSound, float& gameTime);
	void AnimationBombBeforeExplosion(Texture& playersBombTexture, float& gameTime, float& time);
	void ExplosionAnimation(Texture& bombExplosionTexture, float& gameTime, float& time);
	void Update(float& gameTime);
	void Draw(RenderWindow& window, Texture& playersBombTexture, Texture& bombExplosionTexture, float& gameTime, float& time);
};
