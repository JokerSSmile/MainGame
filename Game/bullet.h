#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "constants.h"
#include "map.h"
#include "collision.h"
#include "sprites.h"
#include "music.h"

using namespace sf;
using namespace std;

struct Bullet
{
	float dy;
	float dx;
	int direction;
	float x = 0;
	float y = 0;
	Vector2f startPos;
	bool alive = false;
	float timeShot;
	float deathTime = 0;
	Sprite bulletSprite;
	Sprite bulletEffectSprite;
	Sprite bulletEnemyEffectSprite;
	bool isPlayers = false;
	float speed;
	float damage = 0;
	bool isDel;

	void CheckCollisionBullet(float& gameTime, vector<Map>& myMap, Sprite& mySprites, Sound& destroyBullet);
	void DeleteBullet(float& gameTime, Sound& destroyBullet);
	void BulletDestroyEffect(float& gameTime, RenderWindow& window);
	void SetSpeed();
	void UpdateBullet(float& time, RenderWindow & window, float gameTime, Texture& bulletTexture, Texture& bulletEffectTexture, Texture& bulletEnemyEffectTexture);
	void DrawBullet(RenderWindow & window);
};
