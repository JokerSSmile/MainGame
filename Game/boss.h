#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

#include "character.h"
#include "bullet.h"
#include "bomb.h"

using namespace sf;
using namespace std;

struct Boss :
	public Character
{
	Clock clock;
	int bossRoom = 0;
	float bossTime;
	float lastShootBoss = 0;
	float damage = 1;
	float deathTime = 0;
	float bombHitTime = 0;
	float playerHitTime = 0;
	bool isShoot;
	bool isNeedDeathSound;
	Sprite poofSprite;
	Vector2f lastPlayerPosition;
	Vector2f spriteCenterPos;
	BossState state;

	Boss() {};
	Boss(Texture & image, Vector2f& pos, Vector2i& Size, String Name, float Health, int Room) :Character(image, pos, Size, Name, health)
	{
		speed = BOSS_JUMP_SPEED / 2;
		size.x = Size.x;
		size.y = Size.y;
		position.x = pos.x;
		position.y = pos.y;
		health = Health;
		sprite.setOrigin(float(size.x / 2), float(size.y / 2));
		state = SHOOT;
		bossRoom = Room;
	}
	
	void Shoot(vector<Bullet>& bullets, float& gameTime, int dir);

	void UpdateReflect(Vector2f& playerPosition);
	void UpdateState(vector<Bullet>& bullets, float & gameTime, Vector2f & playerPosition, float & time);
	void PlaySound(Sound& lands, Sound& shoots, Sound& dies);
	void UpdateAlive();
	void ChangeColor(float & gameTime);
	void DrawHealth(Sprite& healthBar, RenderWindow& window);
	void ExplosionCollision(Boomb & boomb, float & gameTime);
	void Update(vector<Bullet>& bullets, float& gameTime, Vector2f& playerPosition, float& time);

	void Draw(RenderWindow& window);
};

