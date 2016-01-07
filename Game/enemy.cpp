#include "enemy.h"

#include "map.h"

void Enemy::CheckCollosionFly(vector<Map>& myMap, Sprite& wallSprite)
{
	for (auto& map : myMap)
	{
		if (Collision::PixelPerfectTest(sprite, map.sprite) || Collision::PixelPerfectTest(sprite, wallSprite))
		{
			if (moving.x > 0)
			{
				position.x -= 1;
			}
			else if (moving.x < 0)
			{
				position.x += 1;
			}
			moving.x = -moving.x;
			moving.y = -moving.y;
		}
	}
}

void Enemy::Shoot(vector<Bullet>& bullets, float& gameTime, int& dir, float bulletStartX, float bulletStartY)
{
	Bullet bullet;
	bullet.isPlayers = false;
	bullet.alive = true;
	bullet.x = bulletStartX;
	bullet.y = bulletStartY;
	bullet.timeShot = gameTime;
	bullet.direction = dir;
	bullet.speed = ENEMY_BULLET_SPEED;
	bullet.damage = damage;
	bullet.startPos = position;
	lastShootEnemyStand = bullet.timeShot;
	bullets.push_back(bullet);
}

void Enemy::DestroyEffect(float& gameTime, RenderWindow& window, Texture& poofTexture, float& time)
{
	poofSprite.setTexture(poofTexture);
	poofSprite.setScale(1.5, 1.5);
	poofSprite.setOrigin(TILE_SIDE / 2, TILE_SIDE / 2);
	poofSprite.setPosition(lastPosition.x + sprite.getGlobalBounds().width / 2, lastPosition.y + sprite.getGlobalBounds().height / 2);

	if (gameTime > deathTime && gameTime < deathTime + ENEMY_DESTROY_EFFECT * 4)
	{
		if (currentFrame < EXPLOSION_FRAMES_COUNT)
		{
			currentFrame += FRAME_CHANGE_TIME_EXPLOSION * time;
		}
		poofSprite.setTextureRect(IntRect(EXPLOSION_TEXTURE_IMAGE_SIZE * (int(currentFrame) % EXPLOSION_FRAME_COUNT), EXPLOSION_TEXTURE_IMAGE_SIZE * (int(currentFrame) / EXPLOSION_FRAME_COUNT), EXPLOSION_TEXTURE_IMAGE_SIZE, EXPLOSION_TEXTURE_IMAGE_SIZE));
		window.draw(poofSprite);
	}
}

void Enemy::ExplosionCollision(Boomb& boomb, float& gameTime)
{
	if (sprite.getGlobalBounds().intersects(boomb.damageZone.getGlobalBounds()))
	{
		if (gameTime > bombHitTime + TIME_BEFORE_EXPLOSION && gameTime < boomb.explosionTime + FRAME_CHANGE_TIME)
		{
			health -= BOMB_DAMAGE;
			bombHitTime = gameTime;
		}
		if (gameTime > boomb.explosionTime + TIME_FOR_EXPLOSION / 2.f)
		{
			boomb.isAlive = false;
		}
	}
}


void Enemy::ChangeColorAfterHit(float& gameTime, Boomb& boomb)
{
	if (gameTime < playerHitTime + CHANGE_COLOR_EFFECT || (gameTime > bombHitTime && gameTime < bombHitTime + FRAME_CHANGE_TIME))
	{
		sprite.setColor(COLOR_AFTER_HIT);
	}
	else
	{
		sprite.setColor(Color::White);
	}
}

void Enemy::UpdateFly(float& time, vector<Map>& myMap, Sprite& wallSprite)
{
	if (name == "EnemyFly")
	{
		currentFrame += FLY_UPDATE_FRAME_TIME * time;
		if (currentFrame > 2) currentFrame -= 2;
		sprite.setTextureRect(IntRect(FLY_SIZE.x * int(currentFrame), 0, FLY_SIZE.x, FLY_SIZE.y));
		CheckCollosionFly(myMap, wallSprite);
		position.x += moving.x * time;
		position.y += moving.y * time;
		sprite.setPosition(position.x, position.y);
	}
}

void Enemy::UpdateStandAndShoot(vector<Bullet>& bullets, float& gameTime)
{
	if (name == "EnemyStandAndShoot")
	{
		if (gameTime > (lastShootEnemyStand + TIME_BETWEEN_SHOOT_ENEMY_STAND))
		{
			for (int i = 4; i <= 7; i++)
			{
				Shoot(bullets, gameTime, i, sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - 16, sprite.getPosition().y + 32);
			}
		}
		sprite.setScale(2, 2);
		sprite.setPosition(position);
		if (lastShootEnemyStand + ENEMY_STAND_AND_SHOOT_FRAME_TIME <= gameTime && lastShootEnemyStand != 0)
		{
			sprite.setTextureRect(IntRect(0, 0, STAND_AND_SHOOT_SIZE.x, STAND_AND_SHOOT_SIZE.y));
		}
		else
		{
			sprite.setTextureRect(IntRect(STAND_AND_SHOOT_SIZE.x, 0, STAND_AND_SHOOT_SIZE.x, STAND_AND_SHOOT_SIZE.y));
		}
	}
}

void Enemy::SetDirection(Vector2f& playerPosition)
{
	if (position.x >= playerPosition.x - PLAYER_WIDTH / 2 && position.x <= playerPosition.x + PLAYER_WIDTH + PLAYER_WIDTH / 2)
	{
		if (position.y > playerPosition.y)
		{
			dir = up;
		}
		else
		{
			dir = down;
		}
	}
	else if (position.y <= playerPosition.y - PLAYER_HEIGHT / 2 && position.y <= playerPosition.y + PLAYER_HEIGHT + PLAYER_WIDTH / 2)
	{
		if (position.x > playerPosition.x)
		{
			dir = left;
		}
		else
		{
			dir = right;
		}
	}
	if (position.x > playerPosition.x && position.y > playerPosition.y)
	{
		dir = leftUp;
	}
	else if (position.x > playerPosition.x && position.y < playerPosition.y)
	{
		dir = leftDown;
	}
	else if (position.x < playerPosition.x && position.y > playerPosition.y)
	{
		dir = rightUp;
	}
	else if (position.x < playerPosition.x && position.y < playerPosition.y)
	{
		dir = rightDown;
	}
}

void Enemy::SetFrameFollowEnemy(float& time)
{
	if (dir == left || dir == leftUp || dir == leftDown)
	{
		currentFrame += 0.005f * time;
		if (currentFrame > 4)
		{
			currentFrame -= 4;
		}
		sprite.setTextureRect(IntRect(36 * int(currentFrame), 60, 36, 26));
	}
	else
	{
		currentFrame += 0.005f * time;
		if (currentFrame > 4)
		{
			currentFrame -= 4;
		}
		sprite.setTextureRect(IntRect(36 * int(currentFrame), 34, 36, 26));
	}
}

bool Enemy::IsIntersectsMap(vector<Map>& myMap)
{
	for (auto& map : myMap)
	{
		if (Collision::BoundingBoxTest(sprite, map.sprite))
		{
			return true;
		}
	}
	return false;
}

void Enemy::MoveFollowEnemy(float& gameTime, Vector2f& playerPosition, vector<Map>& myMap, float& time)
{
	if (name == "EnemyFollow")
	{
		SetDirection(playerPosition);
		SetFrameFollowEnemy(time);
		Vector2f(playerOldPosition) = sprite.getPosition();
		SetPosition(time, speed);
		sprite.setPosition(position);
		if (IsIntersectsMap(myMap) == true)
		{
			sprite.setPosition(playerOldPosition);
			if (position.x != playerOldPosition.x && position.y != playerOldPosition.y)
			{
				sprite.setPosition(playerOldPosition.x, position.y);
				if (IsIntersectsMap(myMap) == true)
				{
					sprite.setPosition(position.x, playerOldPosition.y);
					if (IsIntersectsMap(myMap) == true)
					{
						sprite.setPosition(playerOldPosition);
					}
				}
			}
		}
		position = sprite.getPosition();
	}
}

void Enemy::CheckIsAlive()
{
	if (health > 0)
	{
		alive = true;
	}
	else
	{
		currentFrame = 0;
		alive = false;
	}
}

void Enemy::Update(Boomb& boomb, float& gameTime)
{
	ChangeColorAfterHit(gameTime, boomb);
	CheckIsAlive();
	lastPosition = position;
}