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
	float bossTime;
	float currentFrame = 0;
	int bulletStartX = 0;
	int bulletStartY = 0;
	int bossRoom = 0;
	float lastShootBoss = 0;
	float damage = 2;
	float deathTime = 0;
	float bombHitTime = 0;
	float playerHitTime = 0;
	float speed;
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
		bossRoom = Room;
		sprite.setOrigin(size.x / 2, size.y / 2);
		state = SHOOT;
	}
	
	void Update(float& gameTime, Vector2f& playerPosition, float& time);

	void Draw(RenderWindow & window);

};

