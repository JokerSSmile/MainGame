#pragma once
#include <SFML/Graphics.hpp>

#include "constants.h"

using namespace sf;

const int SIZE_BULLETS = 50;
const float LIFE_TIME = 1;

struct Bullet
{
	float dy;
	float dx;
	int direction;
	float x = 0;
	float y = 0;
	bool life = false;
	float timeShot;
	Sprite bulletSprite;
	bool isPlayers = false;
	float speed;
	float damage = 0;

	void CheckCollisionBullet();

	void DeleteBullet(float gameTime);

	void UpdateBullet(float time, RenderWindow & window, float gameTime, Texture & bulletTexture);
};
