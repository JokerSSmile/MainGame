#include "boss.h"

void Boss::Shoot(vector<Bullet>& bullets, float& gameTime, int dir)
{
	Bullet bullet;
	bullet.isPlayers = false;
	bullet.alive = true;
	bullet.y = sprite.getPosition().y + sprite.getLocalBounds().height / 2 - BULLET_SHIFT_IF_SHOOT_UP;
	bullet.x = sprite.getPosition().x ;
	bullet.timeShot = gameTime;
	bullet.direction = dir;
	bullet.speed = BOSS_BULLET_SPEED;
	bullet.damage = damage;
	bullet.startPos = position;
	bullet.isDel = false;
	lastShootBoss = bullet.timeShot;
	bullets.push_back(bullet);
}

void Boss::UpdateReflect(Vector2f& playerPosition)
{
	if (playerPosition.x > position.x)
	{
		sprite.setScale(-2, 2);
	}
	else
	{
		sprite.setScale(2, 2);
	}
}

void Boss::UpdateState(vector<Bullet>& bullets, float& gameTime, Vector2f& playerPosition, float& time)
{
	switch (state)
	{
	case STAY:
	{
		sprite.setTextureRect(IntRect(0, 0, size.x, size.y));
		if (bossTime > 0.5)
		{
			clock.restart();
			state = JUMP_UP;
		}
	}
	break;
	case JUMP_UP:
	{
		sprite.setTextureRect(IntRect(80, 112, size.x, size.y));
		position.y -= speed * time;
		lastPlayerPosition = playerPosition;
		if (bossTime > 1)
		{
			clock.restart();
			position.x = lastPlayerPosition.x;
			state = JUMP_DOWN;
		}
	}
	break;
	case JUMP_DOWN:
	{
		sprite.setTextureRect(IntRect(0, 112, size.x, size.y));
		if (position.y >= lastPlayerPosition.y - 200 + size.y)
		{
			clock.restart();
			state = SHOOT;
		}
		else
		{
			position.y += speed * time;
		}
	}
	break;
	case SHOOT:
	{
		if (bossTime > 1 && bossTime < 1.5)
		{
			if (gameTime > lastShootBoss + 1)
			{
				for (unsigned i = 0; i < 8; i++)
				{
					Shoot(bullets, gameTime, i);
				}
			}
			sprite.setTextureRect(IntRect(240, 0, size.x, size.y));
		}
		else if (bossTime > 2)
		{
			sprite.setTextureRect(IntRect(80, 0, size.x, size.y));
			clock.restart();
			state = STAY;
		}
		else
		{
			sprite.setTextureRect(IntRect(0, 0, size.x, size.y));
		}
	}
	break;
	default:
		break;
	}
}

void Boss::UpdateAlive()
{
	if (health <= 0)
	{
		alive = false;
	}
	else
	{
		alive = true;
	}
}

void Boss::Update(vector<Bullet>& bullets, float& gameTime, Vector2f& playerPosition, float& time)
{
	UpdateAlive();
	UpdateReflect(playerPosition);
	bossTime = clock.getElapsedTime().asSeconds();
	UpdateState(bullets, gameTime, playerPosition, time);
}

void Boss::Draw(RenderWindow& window)
{
	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
}