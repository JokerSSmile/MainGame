#include "enemy.h"

#include "map.h"
#include "view.h"

void Enemy::CheckCollosionFly()//ф-ция взаимодействия с картой
{
	for (int i = y / TILE_SIDE; i < (y + h) / TILE_SIDE; i++)
		for (int j = x / TILE_SIDE; j < (x + w) / TILE_SIDE; j++)
		{
			if (mapString[i][j] == '0' || mapString[i][j] == 's')
			{

				if (dx > 0)//right
				{
					x = j * TILE_SIDE - w;
				}
				else if (dx < 0)//left
				{
					x = j * TILE_SIDE + TILE_SIDE;
				}
				else if (dy > 0)
				{
					y = i * TILE_SIDE;
				}
				else if (dy < 0)
				{
					y = i * TILE_SIDE;
				}
				dy = -dy;
				dx = -dx;
			}
		}
}

void Enemy::CheckCollisionZombie()
{
	for (int i = (y + h / 1.5) / TILE_SIDE; i < (y + h) / TILE_SIDE; i++)
		for (int j = (x / TILE_SIDE); j < (x + w) / TILE_SIDE; j++)
		{
			if (mapString[i][j] == '0' || mapString[i][j] == 's')
			{
				if (dy > 0)//вниз
				{
					y--;
				}
				if (dy < 0)//up
				{
					y++;
				}
				if (dx > 0)//right
				{
					//x = j * TILE_SIDE - w;
					x--;
				}
				if (dx < 0)//left
				{
					x++;
				}
			}
			else if (mapString[i][j] == 'd' && dy > 0)
			{
				view.setCenter(view.getCenter().x, view.getCenter().y + WINDOW_HEIGHT);
				y = y + TILE_SIDE * 4 + h / 2;
			}
			else if (mapString[i][j] == 'u' && dy < 0)
			{
				view.setCenter(view.getCenter().x, view.getCenter().y - WINDOW_HEIGHT);
				y = y - TILE_SIDE * 4 - h / 2;
			}
			else if (mapString[i][j] == 'l' && dx < 0)
			{
				view.setCenter(view.getCenter().x - WINDOW_WIDTH, view.getCenter().y);
				x = x - TILE_SIDE * 4 - w - 5;
			}
			else if (mapString[i][j] == 'r' && dx > 0)
			{
				view.setCenter(view.getCenter().x + WINDOW_WIDTH, view.getCenter().y);
				x = x + TILE_SIDE * 4 + w + 5;
			}
		}
}

void Enemy::Shoot(vector<Bullet>& bullets, float& gameTime, int& dir, float bulletStartX, float bulletStartY)
{
	Bullet bullet;
	bullet.isPlayers = false;
	bullet.life = true;
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

const FloatRect GetSpriteRect(const Sprite & sprite)
{
	const Vector2f pos = sprite.getPosition();
	const Vector2f size = { sprite.getGlobalBounds().width, sprite.getGlobalBounds().height };
	return FloatRect(pos, size);
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
			cout << "1" << endl;
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
		sprite.setColor(Color(250, 150, 150));
	}
	else
	{
		sprite.setColor(Color::White);
	}
}

void Enemy::Update(Boomb& boomb, vector<Bullet>& bullets, float& time, float& gameTime, RenderWindow & window, int& gameLevel)
{
	if (gameLevel == enemyLevel)
	{
		ChangeColorAfterHit(gameTime, boomb);

		if (name == "EnemyFly")
		{
			currentFrame += 0.005f * time;
			if (currentFrame > 2) currentFrame -= 2;
			sprite.setTextureRect(IntRect(57 * int(currentFrame), 0, 57, 45));
			CheckCollosionFly();
		}

		else if (name == "EnemyStandAndShoot")
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

		if (health > 0)
		{
			life = true;
		}
		else
		{
			life = false;
		}

		x += dx * time;
		y += dy * time;

		sprite.setPosition(x, y);
	}
}