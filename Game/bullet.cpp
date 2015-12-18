#include "bullet.h"
#include "map.h"

void Bullet::CheckCollisionBullet()
{
	if (life == true)
	{
		for (int i = (y + BULLET_SIDE) / TILE_SIDE; i < (y + BULLET_SIDE) / TILE_SIDE; i++)
			for (int j = (x / TILE_SIDE); j < ((x + BULLET_SIDE) / TILE_SIDE); j++)
			{
				if (mapString[i][j] == '0' || mapString[i][j] == 's')
				{
					life = false;
				}
			}
	}
}

void Bullet::DeleteBullet(float gameTime)
{
	if (life == true)
	{
		if (gameTime > timeShot + LIFE_TIME)
		{
			isPlayers = false;
			life = false;
			x = 0;
			y = 0;
		}

	}
}


void Bullet::UpdateBullet(float time, RenderWindow & window, float gameTime, Texture & bulletTexture)
{
	if (life == true)
	{
		bulletSprite.setTexture(bulletTexture);
		if (isPlayers == true)
		{
			bulletSprite.setTextureRect(IntRect(96, 96, BULLET_SIDE, BULLET_SIDE));
		}
		else
		{
			bulletSprite.setTextureRect(IntRect(96, 32, BULLET_SIDE, BULLET_SIDE));
		}

		switch (direction)
		{
		case 0: dx = float(-speed*0.66); dy = float(-speed*0.66); break;
		case 1: dx = float(-speed*0.66); dy = float(speed*0.66); break;
		case 2: dx = float(speed*0.66); dy = float(-speed*0.66); break;
		case 3: dx = float(speed*0.66); dy = float(speed*0.66); break;
		case 4: dx = -speed; dy = 0; break;
		case 5: dx = 0; dy = -speed; break;
		case 6: dx = 0; dy = speed; break;
		case 7: dx = speed; dy = 0; break;
		case 8: dx = 0; dy = speed; break;
		}

		x += dx * time;
		y += dy * time;

		bulletSprite.setPosition(x, y);

		DeleteBullet(gameTime);
		CheckCollisionBullet();

		window.draw(bulletSprite);
	}
}