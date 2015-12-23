#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "constants.h"

using namespace sf;
using namespace std;

struct Boomb
{
	Vector2f position;
	Sprite bombSprite;
	Sprite explosionSprite; 
	float createTime = 0;
	float explosionTime = 0;
	bool isAlive = false;

	void AnimationBombBeforeExplosion(Texture& playersBombTexture, float& gameTime);
	void ExplosionAnimation(Texture& bombExplosionTexture, float& gameTime);
	void Update(float& gameTime);
	void Draw(RenderWindow& window, Texture& playersBombTexture, Texture& bombExplosionTexture, float& gameTime);
};
