#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#include "map.h"
#include "character.h"
#include "bullet.h"
#include "bomb.h"
#include "enemy.h"

struct Player :
	public Character
{
	Vector2f playerOldPosition = { position.x, position.y };

	enum
	{
		leftUp, leftDown, rightUp, rightDown, left, up, down, right, stay
	} dir;

	float damage = 1;
	float speed = 0.1f;
	float lastBombPlant = 0;
	float CurrentFrame = 0;
	float lastHitTime = 0;
	float bombHitTime = 0;

	int bombCount;
	
	bool canMove;
	bool isSetSpeed;

	Sprite headSprite;

	Player() {};
	Player(Texture & image, Vector2f& pos, int W, int H, String Name, float Health, Texture& headTexture) :Character(image, pos, w, h, Name, health)
	{
		dir = stay;
		w = W;
		h = H;
		position.x = pos.x;
		position.y = pos.y;

		health = MAX_PLAYER_HEALTH;

		bombCount = 11;

		sprite.setTextureRect(IntRect(0, 0, w, h));
		headSprite.setTexture(headTexture);
		headSprite.setScale(2, 2);
	}


	void setFrame(float& time);

	bool DiagonalMoving(float& time);
	void StrightMoving(float& time);
	void MakeShoot(vector<Bullet>& bullets, float gameTime, float &lastShot);
	void PlantBomb(Boomb& bomb, float& time);
	void Control(Boomb& bomb, vector<Bullet>& bullets, float& time, float& gameTime, float &lastShot);

	void SetShootAnimation(int& dir);

	void Shoot(vector<Bullet>& bullets, float gameTime, float &lastShootPlayer, int dir);

	void SetLastNotCollidedPosition();

	bool IsIntersectsPlayerEnemy(Enemy& enemy);
	void CheckExplosionCollision(Boomb& boomb, float& gameTime);
	void CheckEnemyCollidesPlayer(vector<Enemy>& enemies, float& gameTime, float& hitTimer, Sound& tearDestroy);
	void DiagonalCollision(Map& map);
	void StraightCollision(Map& map);
	void DoorCollision(Map& map, View& view, bool& areDoorsOpened);
	void CheckCollision(vector<Map> myMap, Sprite& wallSprite, View& view, bool areDoorsOpened);
	void ChangeColorAfterHit(float& gameTime, float& hitTimer);

	void setSpeed();

	void Moving(float& time);
};