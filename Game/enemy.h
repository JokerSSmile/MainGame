#pragma once
#include <SFML/Graphics.hpp>

#include "character.h"
#include "bullet.h"

using namespace sf;
using namespace std;

const int TIME_BETWEEN_SHOOT_ENEMY_STAND = 1;

struct Enemy :
	public Character
{
	float moveTimer = 0;
	float currentFrame = 0;
	int randNum;
	int bulletStartX = 0;
	int bulletStartY = 0;
	int enemyLevel = 0;
	float lastShootEnemyStand = 0;
	float damage = 0.5;
	float deathTime = 0;

	Vector2f lastPosition = {0, 0};

	//Texture poofTexture;
	//Sprite poofSprite;

	Enemy() {};
	Enemy(Texture & image, float X, float Y, int W, int H, String Name, float Health, int Level) :Character(image, X, Y, w, h, Name, health)
	{
		w = W;
		h = H;
		x = X;
		y = Y;
		health = Health;
		enemyLevel = Level;
		//poofTexture.loadFromFile("images/enemy_destroy_effect.png");
		//poofSprite.setTexture(poofTexture);
		if (name == "EnemyFly")
		{
			dx = -0.1f;
		}
		else if (name == "EnemyStandAndShoot")
		{
			
		}
		else if (name == "EnemyFollowPlayer")
		{
			dx = 0;
			dy = 0;
		}
	}

	void CheckCollosionFly();

	void CheckCollisionZombie();

	void DestroyEffect(float& gameTime, RenderWindow& window, Texture& poofTexture);

	void Shoot(vector<Bullet>& bullets, float gameTime, int dir, int bulletStartX, int bulletStartY);

	void Update(vector<Bullet>& bullets, float& time, float& gameTime, RenderWindow & window, int& gameLevel);
};
