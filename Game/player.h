#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#include "map.h"
#include "character.h"
#include "bullet.h"
#include "bomb.h"
#include "enemy.h"
#include "boss.h"

struct Player :
	public Character
{
	float damage;
	float speed;
	float lastBombPlant;
	float CurrentFrame;
	float lastHitTime;
	float bombHitTime;
	float hitTimer;
	float range;
	float timeBetweenShoots;
	int bombCount;
	
	bool canMove;
	bool isSetSpeed;

	Sprite headSprite;

	Player() {};
	Player(Texture & image, Vector2f& pos, Vector2i& Size, String Name, float Health, Texture& headTexture) :Character(image, pos, Size, Name, health)
	{
		dir = STAND;
		size.x = Size.x;
		size.y = Size.y;
		position.x = pos.x;
		position.y = pos.y;
		health = MAX_PLAYER_HEALTH;
		bombCount = 2;
		damage = 0.5f;
		speed = 0.1f;
		lastBombPlant = 0;
		CurrentFrame = 0;
		lastHitTime = 0;
		bombHitTime = 0;
		hitTimer = 0;
		range = 250.f;
		timeBetweenShoots = 0.7f;

		sprite.setTextureRect(IntRect(0, 0, size.x, size.y));
		headSprite.setTexture(headTexture);
		headSprite.setScale(2, 2);
	}


	void setFrame(float& time);

	bool DiagonalMoving(float& time);
	void StrightMoving(float& time);
	void MakeShoot(vector<Bullet>& bullets, float gameTime, float &lastShot, Sound& tearFire);
	void PlantBomb(Boomb& bomb, float& time);
	void Control(Boomb& bomb, vector<Bullet>& bullets, float& time, float& gameTime, float &lastShot, Sound& tearFire);

	void SetShootAnimation(int& dir);

	void Shoot(vector<Bullet>& bullets, float gameTime, float &lastShootPlayer, int dir, Sound& tearFire);

	bool IsIntersectsPlayerEnemy(Enemy& enemy);
	bool IsIntersectsMap(vector<Map>& myMap, View& view, bool areDoorsOpened);
	void CheckExplosionCollision(Boomb& boomb, float& gameTime, Sound& playerHurts);
	void CheckEnemyCollidesPlayer(vector<Enemy>& enemies, Boss& boss, float& gameTime, Sound& playerHurts);
	void DoorCollision(vector<Map>& myMap, View& view, bool& areDoorsOpened);
	void SpikeCollision(vector<Map>& myMap, float& gameTime, Sound& playerHurts);
	void ChangeColorAfterHit(float& gameTime);

	void Moving(float& time, vector<Map>& myMap, View& view, bool areDoorsOpened, Sprite& wallSprite);
};