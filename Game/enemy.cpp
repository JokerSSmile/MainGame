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

void Enemy::UpdateFollowEnemy(float& gameTime)
{
	if (name == "EnemyFollow")
	{
		sprite.setScale(2, 2);
		sprite.setTextureRect(IntRect(0, 0, 32, 32));
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

void Enemy::Update(Boomb& boomb, vector<Bullet>& bullets, float& time, float& gameTime, RenderWindow & window, int& gameRoom)
{
	if (gameRoom == enemyRoom)
	{
		ChangeColorAfterHit(gameTime, boomb);

		UpdateFly(time);
		UpdateStandAndShoot(bullets, gameTime);
		
		CheckIsAlive();
		
		SetPosition(time);	
	}
}