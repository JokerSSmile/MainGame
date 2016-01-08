#pragma once
#include <SFML/Graphics.hpp>

#include "character.h"
#include "bullet.h"
#include "bomb.h"

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
	int enemyRoom = 0;
	float lastShootEnemyStand = 0;
	float damage = 0.5;
	float deathTime = 0;
	float bombHitTime = 0;
	float playerHitTime = 0;
	float speed;
	Sprite poofSprite;
	Vector2f lastPosition = {0, 0};
	Vector2f enemyOldPosition = { position.x, position.y };
	bool canMove = true;
	bool isSetSpeed;


	Enemy() {};
	Enemy(Texture & image, Vector2f& pos, int W, int H, String Name, float Health, int Room) :Character(image, pos, w, h, Name, health)
	{
		speed = ENEMY_FOLLOW_SPEED;
		w = W;
		h = H;
		position.x = pos.x;
		position.y = pos.y;
		health = Health;
		enemyRoom = Room;

		if (name == "EnemyFly")
		{
			moving.x = 0.1f;
		}
		else if (name == "EnemyFollow")
		{
			dir = stay;
		}
	}

	void CheckCollosionFly(vector<Map>& myMap, Sprite& wallSprite, float& time);
	void ExplosionCollision(Boomb& boomb, float& gameTime);
	void DestroyEffect(float& gameTime, RenderWindow& window, Texture& poofTexture, float& time);
	void Shoot(vector<Bullet>& bullets, float& gameTime, int& dir, float bulletStartX, float bulletStartY);
	void ChangeColorAfterHit(float& gameTime, Boomb& boomb);
	void UpdateFly(float& time, vector<Map>& myMap, Sprite& wallSprite);
	void UpdateStandAndShoot(vector<Bullet>& bullets, float& gameTime);

	void SetFrameFollowEnemy(float& time);
	bool IsIntersectsMap(vector<Map>& myMap);
	void SetDirection(Vector2f& playerPosition);

	void MoveFollowEnemy(float& gameTime, Vector2f& playerPosition, vector<Map>& myMap, float& time);
	void CheckIsAlive();
	void Update(Boomb& boomb, float& gameTime);
};
