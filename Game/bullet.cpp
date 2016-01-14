#include "bullet.h"
#include "map.h"

void Bullet::CheckCollisionBullet(float& gameTime, vector<Map>& myMap, Sprite& wallBulletSprite, Sound& destroyBullet)
{
	if (alive == true)
	{
		for (auto& map: myMap)
		{
			if (Collision::PixelPerfectTest(bulletSprite, map.collisionSprite))
			{
				deathTime = gameTime;
				alive = false;
				destroyBullet.play();
			}
		}
		if (Collision::PixelPerfectTest(bulletSprite, wallBulletSprite))
		{
			deathTime = gameTime;
			alive = false;
			destroyBullet.play();
		}
	}
}

void Bullet::DeleteBullet(float& gameTime, Sound& destroyBullet, float& playersShootRange)
{
	if (alive == true)
	{
		if (isPlayers == false)
		{
			if (abs(startPos.x - position.x) > BULLET_MAX_DISTANCE || abs(startPos.y - position.y) > BULLET_MAX_DISTANCE)
			{
				deathTime = gameTime;
				alive = false;
				destroyBullet.play();
			}
		}
		else
		{
			if (abs(startPos.x - position.x) > playersShootRange || abs(startPos.y - position.y) > playersShootRange)
			{
				deathTime = gameTime;
				alive = false;
				destroyBullet.play();
			}
		}
	}
}	

void Bullet::BulletDestroyEffect(float& gameTime, RenderWindow& window)
{
	if (isPlayers == true)
	{
		if (gameTime < deathTime + BULLET_ANIMATION_STEP_TIME)
		{
			bulletEffectSprite.setTextureRect(IntRect(0, 64, 64, 64));
			bulletEffectSprite.setPosition(position.x - 16, position.y - 16);
			window.draw(bulletEffectSprite);
		}
		else if (gameTime > deathTime + BULLET_ANIMATION_STEP_TIME && gameTime < deathTime + BULLET_ANIMATION_STEP_TIME * 2)
		{
			bulletEffectSprite.setTextureRect(IntRect(0, 128, 64, 64));
			bulletEffectSprite.setPosition(position.x - 16, position.y - 16);
			window.draw(bulletEffectSprite);
		}
		else if (gameTime > deathTime + BULLET_ANIMATION_STEP_TIME * 2)
		{
			isDel = true;
		}
	}
	else
	{
		if (gameTime < deathTime + BULLET_ANIMATION_STEP_TIME)
		{
			bulletEnemyEffectSprite.setTextureRect(IntRect(192, 0, 64, 64));
			bulletEnemyEffectSprite.setPosition(position.x - 16, position.y - 16);
			window.draw(bulletEnemyEffectSprite);
		}
		else if (gameTime > deathTime + BULLET_ANIMATION_STEP_TIME && gameTime < deathTime + BULLET_ANIMATION_STEP_TIME * 2)
		{
			bulletEnemyEffectSprite.setTextureRect(IntRect(64, 64, 64, 64));
			bulletEnemyEffectSprite.setPosition(position.x - 16, position.y - 16);
			window.draw(bulletEnemyEffectSprite);
		}
		else if (gameTime > deathTime + BULLET_ANIMATION_STEP_TIME * 2)
		{
			isDel = true;
		}
	}
}

void Bullet::SetSpeed()
{
	switch (direction)
	{
	case 0: moving.x = float(-speed*0.66); moving.y = float(-speed*0.66); break;
	case 1: moving.x = float(-speed*0.66); moving.y = float(speed*0.66); break;
	case 2: moving.x = float(speed*0.66); moving.y = float(-speed*0.66); break;
	case 3: moving.x = float(speed*0.66); moving.y = float(speed*0.66); break;
	case 4: moving.x = -speed; moving.y = 0; break;
	case 5: moving.x = 0; moving.y = -speed; break;
	case 6: moving.x = 0; moving.y = speed; break;
	case 7: moving.x = speed; moving.y = 0; break;
	case 8: moving.x = 0; moving.y = speed; break;
	}
}

void Bullet::UpdateBullet(float& time, RenderWindow & window, float gameTime, Texture & bulletTexture, Texture& bulletEffectTexture, Texture& bulletEnemyEffectTexture)
{
	if (alive == true)
	{
		bulletSprite.setTexture(bulletTexture);
		bulletEffectSprite.setTexture(bulletEffectTexture);
		bulletEnemyEffectSprite.setTexture(bulletEnemyEffectTexture);
		if (isPlayers == true)
		{
			bulletSprite.setTextureRect(IntRect(96, 96, BULLET_SIDE, BULLET_SIDE));
		}
		else
		{
			bulletSprite.setTextureRect(IntRect(96, 32, BULLET_SIDE, BULLET_SIDE));
		}

		SetSpeed();

		position.x += moving.x * time;
		position.y += moving.y * time;

		bulletSprite.setPosition(position.x, position.y);
	}
}

void Bullet::DrawBullet(RenderWindow & window)
{
	window.draw(bulletSprite);
}
