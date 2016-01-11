#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

#include "character.h"
#include "bullet.h"
#include "bomb.h"

using namespace sf;
using namespace std;

struct Enemy :
	public Character
{
	float moveTimer = 0;
	float currentFrame = 0;
	int randNum;
	int enemyRoom = 0;
	float lastShootEnemyStand = 0;
	float damage = 0.5;
	float deathTime = 0;
	float bombHitTime = 0;
	float playerHitTime = 0;
	float speed;
	bool isRemove;
	Sprite poofSprite;
	Sprite headSprite;
	FollowState followState;
	Vector2f lastPosition = {0, 0};
	Vector2f spriteCenterPos;
	Vector2f enemyOldPosition = { position.x, position.y };

	Enemy() {};
	Enemy(Texture & image, Vector2f& pos, Vector2i& Size, String Name, float Health, int Room) :Character(image, pos, Size, Name, health)
	{
		speed = ENEMY_FOLLOW_SPEED_NORMAL;
		size.x = Size.x;
		size.y = Size.y;
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

	void CheckCollosionFly(vector<Map>& myMap, float& time);
	void ExplosionCollision(Boomb& boomb, float& gameTime);
	void DestroyEffect(float& gameTime, RenderWindow& window, Texture& poofTexture, float& time, Sound& flyHurt, Sound& enemyHurt);
	void Shoot(vector<Bullet>& bullets, float& gameTime, int& dir, float bulletStartX, float bulletStartY);
	void ChangeColorAfterHit(float& gameTime, Boomb& boomb);
	void UpdateFly(float& time, vector<Map>& myMap);
	void UpdateStandAndShoot(vector<Bullet>& bullets, float& gameTime);

	void SetFrameFollowEnemy(float& time, Vector2f& playerPosition);
	bool IsIntersectsMap(vector<Map>& myMap);
	void UpdateState(Vector2f & playerPosition);
	bool isIntersectEnemy(vector<Enemy>& enemies);
	void SetDirection(Vector2f& playerPosition);

	void UpdateHeadFrame(Texture & followHeadTexture, float& gameTime);

	void MoveFollowEnemy(float& gameTime, Vector2f& playerPosition, vector<Map>& myMap, float& time, vector<Enemy>& enemies);
	void isNeedRemove(float& gameTime);
	void CheckIsAlive(float& gameTime);
	void Update(Boomb& boomb, float& gameTime);
};
