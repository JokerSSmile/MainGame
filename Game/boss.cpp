#include "boss.h"

void Boss::Shoot(vector<Bullet>& bullets, float& gameTime, int dir)
{
	Bullet bullet;
	bullet.isPlayers = false;
	bullet.alive = true;
	bullet.position.y = sprite.getPosition().y + sprite.getLocalBounds().height / 2 - BULLET_SHIFT_IF_SHOOT_UP;
	bullet.position.x = sprite.getPosition().x ;
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
	bossTime = clock.getElapsedTime().asSeconds();
	switch (state)
	{
	case STAY:
	{
		sprite.setTextureRect(IntRect(0, 0, size.x, size.y));
		if (bossTime > 1)
		{
			bossTime = 0;
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
			bossTime = 0;
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
			bossTime = 0;
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
		isShoot = false;
		if (bossTime > 1 && bossTime < 1.5)
		{
			if (gameTime > lastShootBoss + 1)
			{
				for (unsigned i = 0; i < 8; i++)
				{
					Shoot(bullets, gameTime, i);
					if (i == 0)
					{
						isShoot = true;
					}
				}
			}
			sprite.setTextureRect(IntRect(240, 0, size.x, size.y));
		}
		else if (bossTime > 2)
		{
			bossTime = 0;
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

void Boss::PlaySound(Sound& lands, Sound& shoots, Sound& dies)
{
	if (state == SHOOT && bossTime == 0)
	{
		lands.play();
	}
	else if (isShoot == true)
	{
		shoots.play();
	}
	else if (isNeedDeathSound == true)
	{
		dies.play();
	}
}

void Boss::UpdateAlive()
{
	isNeedDeathSound = false;
	if (alive == true)
	{
		if (health <= 0)
		{
			isNeedDeathSound = true;
			sprite.setPosition(-TILE_SIDE, -TILE_SIDE);
			alive = false;
		}
		else
		{
			alive = true;
		}
	}
}

void Boss::ChangeColor(float& gameTime)
{
	if (gameTime > playerHitTime && gameTime < playerHitTime + CHANGE_COLOR_EFFECT || gameTime > bombHitTime && gameTime < bombHitTime + CHANGE_COLOR_EFFECT)
	{
		sprite.setColor(Color(COLOR_AFTER_HIT));
	}
	else
	{
		sprite.setColor(Color::White);
	}
}

void Boss::DrawHealth(Sprite& healthBar, RenderWindow& window)
{
	healthBar.setPosition(WINDOW_WIDTH / 2 - BAR_SIZE.x / 2, TILE_SIDE / 2);
	healthBar.setTextureRect(IntRect(0, 0, int(health / BOSS_HEALTH * BAR_SIZE.x), int(BAR_SIZE.y)));
	window.draw(healthBar);
}

void Boss::ExplosionCollision(Boomb& boomb, float& gameTime)
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

void Boss::Update(vector<Bullet>& bullets, float& gameTime, Vector2f& playerPosition, float& time)
{
	ChangeColor(gameTime);
	UpdateReflect(playerPosition);
	UpdateState(bullets, gameTime, playerPosition, time);
}

void Boss::Draw(RenderWindow& window)
{
	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
}