#include "boss.h"

void Boss::Update(float& gameTime, Vector2f& playerPosition, float& time)
{
	if (playerPosition.x > position.x)
	{
		sprite.setScale(-2, 2);
	}
	else
	{
		sprite.setScale(2, 2);
	}
	bossTime = clock.getElapsedTime().asSeconds();
	switch (state)
	{
	case STAY: 
	{
		sprite.setTextureRect(IntRect(0, 0, size.x, size.y));
		if (bossTime > 1)
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
			sprite.setTextureRect(IntRect(240, 0, size.x, size.y));
			//lastPlayerPosition = playerPosition;
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

void Boss::Draw(RenderWindow& window)
{
	sprite.setPosition(position.x, position.y);
	window.draw(sprite);
}