#include "enemy.h"

#include "map.h"

void Enemy::CheckCollosionFly()//ф-ция взаимодействия с картой
{
	for (int i = position.y / TILE_SIDE; i < (position.y + h) / TILE_SIDE; i++)
		for (int j = position.x / TILE_SIDE; j < (position.x + w) / TILE_SIDE; j++)
		{
			if (mapString[i][j] == '0' || mapString[i][j] == 's')
			{

				if (moving.x > 0)//right
				{
					position.x = j * TILE_SIDE - w;
				}
				else if (moving.x < 0)//left
				{
					position.x = j * TILE_SIDE + TILE_SIDE;
				}
				else if (moving.y > 0)
				{
					position.y = i * TILE_SIDE;
				}
				else if (moving.y < 0)
				{
					position.y = i * TILE_SIDE;
				}
				moving.y = -moving.y;
				moving.x = -moving.x;
			}
		}
}

void Enemy::SetLastNotCollidedPosition()
{
	if (moving.x > 0)
	{
		position.x = enemyOldPosition.x - 1;
	}
	else if (moving.x < 0)
	{
		position.x = enemyOldPosition.x + 1;
	}
	if (moving.y > 0)
	{
		position.y = enemyOldPosition.y - 1;
	}
	else if (moving.y < 0)
	{
		position.y = enemyOldPosition.y + 1;
	}
}

void Enemy::CheckCollisionZombie(vector<Map> myMap, Sprite& wallSprite)
{
	/*
	for (auto& map : myMap)
	{
		//if (Collision::PixelPerfectTest(sprite, map.sprite))
		if (GetSpriteRect(sprite).intersects(GetSpriteRect(map.sprite)))
		{
			if (map.pos == NOTDOOR)
			{
				canMove = false;
				SetLastNotCollidedPosition();
				break;
			}
		}
		else if (Collision::PixelPerfectTest(sprite, wallSprite))
		{
			canMove = false;
			SetLastNotCollidedPosition();
			break;
		}
		else
		{
			enemyOldPosition.x = position.x;
			enemyOldPosition.y = position.y;
			canMove = true;
		}
	}
	*/
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
	lastShootEnemyStand = bullet.timeShot;
	bullets.push_back(bullet);
}

void Enemy::DestroyEffect(float& gameTime, RenderWindow& window, Texture& poofTexture)
{
	poofSprite.setTexture(poofTexture);
	poofSprite.setScale(1.5, 1.5);
	poofSprite.setOrigin(48, 48);
	poofSprite.setPosition(lastPosition.x + sprite.getGlobalBounds().width, lastPosition.y + sprite.getGlobalBounds().height);

	if (gameTime < deathTime + ENEMY_DESTROY_EFFECT)
	{
		poofSprite.setTextureRect(IntRect(64, 0, 64, 64));
		window.draw(poofSprite);
	}
	else if (gameTime > deathTime + ENEMY_DESTROY_EFFECT && gameTime < deathTime + ENEMY_DESTROY_EFFECT * 2)
	{
		poofSprite.setTextureRect(IntRect(192, 0, 64, 64));
		window.draw(poofSprite);
	}
	else if (gameTime > deathTime + ENEMY_DESTROY_EFFECT * 2 && gameTime < deathTime + ENEMY_DESTROY_EFFECT * 3)
	{
		poofSprite.setTextureRect(IntRect(0, 64, 64, 64));
		window.draw(poofSprite);
	}
	else if (gameTime > deathTime + ENEMY_DESTROY_EFFECT * 3 && gameTime < deathTime + ENEMY_DESTROY_EFFECT * 4)
	{
		poofSprite.setTextureRect(IntRect(128, 64, 64, 64));
		window.draw(poofSprite);
	}
}

void Enemy::ExplosionCollision(Boomb& boomb, float& gameTime)
{
	FloatRect spriteRect = GetSpriteRect(sprite);
	if (spriteRect.intersects(boomb.damageZone.getGlobalBounds()))
	{
		if (gameTime > bombHitTime + TIME_BEFORE_EXPLOSION && gameTime < boomb.explosionTime + 0.5)
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
	if (gameTime < playerHitTime + CHANGE_COLOR_EFFECT || (gameTime > bombHitTime && gameTime < bombHitTime + 0.5))
	{
		sprite.setColor(COLOR_AFTER_HIT);
	}
	else
	{
		sprite.setColor(Color::White);
	}
}

void Enemy::UpdateFly(float& time)
{
	if (name == "EnemyFly")
	{
		currentFrame += 0.005f * time;
		if (currentFrame > 2) currentFrame -= 2;
		sprite.setTextureRect(IntRect(57 * int(currentFrame), 0, 57, 45));
		CheckCollosionFly();
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
		if (lastShootEnemyStand + 0.3 <= gameTime)
		{
			sprite.setTextureRect(IntRect(0, 0, 38, 43));
		}
		else
		{
			sprite.setTextureRect(IntRect(38, 0, 38, 43));
		}
	}
}

bool IsRock(vector<Map> myMap, float& y, float& x)
{
	for (auto& map : myMap)
	{
		if (map.sprite.getGlobalBounds().contains(x + PLAYER_WIDTH / 2, y - 5))
		{
			return true;
		}
	}
	return false;
}

void Enemy::DiagonalCollision(Map& map, vector<Map>& myMap)
{
	if (moving.x > 0 && moving.y > 0)
	{
		if (sprite.getPosition().x >= map.x - h / 2)
		{
			position.x = position.x + speed;
			moving.x = 0;
		}
		else
		{
			position.y = position.y + speed;
			moving.y = 0;
		}
		isSetSpeed = true;
	}
	else if (moving.x > 0 && moving.y < 0)
	{
		if (sprite.getPosition().x >= map.x + TILE_SIDE / 2 - h)
		{
			position.x = position.x + speed;
			moving.x = 0;
		}
		else
		{
			position.y = position.y - speed;
			moving.y = 0;
		}
		isSetSpeed = true;
	}
	else if (moving.x < 0 && moving.y < 0)
	{
		if (sprite.getPosition().y + h >= map.y + TILE_SIDE + h / 2 && position.x < map.x + TILE_SIDE - h / 2
			|| map.sprite.getGlobalBounds().contains(position.x - 10, position.y - 5) && IsRock(myMap, position.y, position.x) == true)
		{
			position.x = position.x - speed;
			moving.x = 0;
		}
		else
		{
			position.y = position.y - speed;
			moving.y = 0;
		}
		isSetSpeed = true;
	}
	else if (moving.x < 0 && moving.y > 0)
	{
		if (sprite.getPosition().y + h <= map.y + h / 2)
		{
			position.x = position.x - speed;
			moving.x = 0;
		}
		else
		{
			position.y = position.y + speed;
			moving.y = 0;
		}
		isSetSpeed = true;
	}
}

void Enemy::StraightCollision(Map& map)
{
	if (moving.x == 0 && moving.y > 0)
	{
		position.y = map.sprite.getPosition().y - h;
	}
	else if (moving.x == 0 && moving.y < 0)
	{
		position.y = map.sprite.getPosition().y + TILE_SIDE;
	}
	else if (moving.x > 0 && moving.y == 0)
	{
		position.x = map.sprite.getPosition().x - w;
	}
	else if (moving.x < 0 && moving.y == 0)
	{
		position.x = map.sprite.getPosition().x + TILE_SIDE;
	}
}

void Enemy::SetSpeed()
{
	switch (dir)
	{
	case right: moving.x = speed; moving.y = 0;  break;
	case left: moving.x = -speed; moving.y = 0; break;
	case down: moving.x = 0; moving.y = speed; break;
	case up: moving.x = 0; moving.y = -speed; break;
	case leftUp: moving.x = -speed*0.66f; moving.y = -speed*0.66f; break;
	case leftDown: moving.x = -speed*0.66f; moving.y = speed*0.66f; break;
	case rightUp: moving.x = speed*0.66f; moving.y = -speed*0.66f; break;
	case rightDown: moving.x = speed*0.66f; moving.y = speed*0.66f; break;
	case stay: moving.x = 0; moving.y = 0; break;
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

void Enemy::UpdateFollowEnemy(float& gameTime, Vector2f& playerPosition, vector<Map>& myMap, float& time)
{
	if (name == "EnemyFollow")
	{
		SetFrameFollowEnemy(time);
		//sprite.setTextureRect(IntRect(0, 0, 32, 32));
		isSetSpeed = false;
		for (auto& map : myMap)
		{
			if (GetSpriteRect(sprite).intersects(GetSpriteRect(map.sprite)))
			{
				if (map.pos == NOTDOOR)
				{

					DiagonalCollision(map, myMap);
					StraightCollision(map);
					break;
				}
			}
		}
		if (isSetSpeed == false)
		{
			SetDirection(playerPosition);
			SetSpeed();
			position.x += moving.x * time;
			position.y += moving.y * time;
			sprite.setPosition(position.x, position.y);
		}
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
		alive = false;
	}
}

void Enemy::SetPosition(float& time)
{
	position.x += moving.x * time;
	position.y += moving.y * time;

	sprite.setPosition(position.x, position.y);
}

void Enemy::Update(Boomb& boomb, vector<Bullet>& bullets, float& time, float& gameTime, Vector2f& playerPosition)
{
	ChangeColorAfterHit(gameTime, boomb);

	UpdateFly(time);
	UpdateStandAndShoot(bullets, gameTime);
		
	CheckIsAlive();
	
	if (name != "EnemyFollow")
	{
		SetPosition(time);
	}
}