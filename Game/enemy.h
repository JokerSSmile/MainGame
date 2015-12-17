#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const int TIME_BETWEEN_SHOOT_ENEMY_STAND = 1;

struct Enemy:
	public Character
{
private:
	float moveTimer = 0;
	float currentFrame = 0;
	int randNum;
	int bulletStartX = 0;
	int bulletStartY = 0;

public:
	int level = 0;
	float lastShootEnemyStand = 0;
	float damage = 0.5;
	Enemy() {};
	Enemy(Texture & image, float X, float Y, int W, int H, String Name, float Health, int Level) :Character(image, X, Y, w, h, Name, health)
	{
		w = W;
		h = H;
		x = X;
		y = Y;
		health = Health;
		level = Level;
		if (name == "EnemyFly")
		{
			dx = -0.1;
		}
		else if (name == "EnemyStandAndShoot")
		{
			//
		}
		else if (name == "EnemyFollowPlayer")
		{
			dx = 0;
			dy = 0;
		}
	}

	void CheckCollosionFly()//ф-ция взаимодействия с картой
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

	void CheckCollisionZombie()
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

	void Shoot(float gameTime, int dir, int bulletStartX, int bulletStartY)
	{
		Bullet bullet;
		bullet.isPlayers = false;
		bullet.life = true;
		bullet.x = bulletStartX;
		bullet.y = bulletStartY;
		bullet.timeShot = gameTime;
		bullet.direction = dir;
		bullet.speed = 0.2;
		bullet.damage = damage;
		lastShootEnemyStand = bullet.timeShot;
		bullets.push_back(bullet);
	}


	void Update(float time, float gameTime, RenderWindow & window, int gameLevel)
	{
		if (gameLevel == level)
		{
			if (name == "EnemyFly")
			{
				currentFrame += 0.005 * time;
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
						Shoot(gameTime, i, sprite.getPosition().x + sprite.getGlobalBounds().width / 2 - 16, sprite.getPosition().y + 32);
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

			x += dx * time;
			y += dy * time;

			sprite.setPosition(x, y);
		}
	}
	
};
