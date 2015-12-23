#include "bomb.h"

void Boomb::AnimationBombBeforeExplosion(Texture& playersBombTexture, float& gameTime)
{
	bombSprite.setTexture(playersBombTexture);
	bombSprite.setScale(2, 2);
	if (gameTime < createTime + TIME_BEFORE_EXPLOSION * 0.25)
	{
		bombSprite.setPosition(position.x, position.y);
		bombSprite.setTextureRect(IntRect(0, 32, 32, 32));
		bombSprite.setColor(Color::White);
	}
	else if (gameTime > createTime + TIME_BEFORE_EXPLOSION * 0.25 && gameTime < createTime + TIME_BEFORE_EXPLOSION * 0.5)
	{
		bombSprite.setPosition(position.x + 3, position.y + 3);
		bombSprite.setTextureRect(IntRect(32, 32, 32, 32));
		bombSprite.setColor(Color::Red);
	}
	else if (gameTime > createTime + TIME_BEFORE_EXPLOSION * 0.5 && gameTime < createTime + TIME_BEFORE_EXPLOSION * 0.75)
	{
		bombSprite.setPosition(position.x, position.y);
		bombSprite.setTextureRect(IntRect(0, 32, 32, 32));
		bombSprite.setColor(Color::White);
	}
	else if (gameTime > createTime + TIME_BEFORE_EXPLOSION * 0.75 && gameTime < createTime + TIME_BEFORE_EXPLOSION)
	{
		bombSprite.setPosition(position.x + 3, position.y + 3);
		bombSprite.setTextureRect(IntRect(32, 32, 32, 32));
		bombSprite.setColor(Color::Red);
	}
}

void Boomb::ExplosionAnimation(Texture& bombExplosionTexture, float& gameTime)
{
	explosionSprite.setPosition(position.x - 64, position.y - 128);
	explosionSprite.setTexture(bombExplosionTexture);
	explosionSprite.setScale(2, 2);
	if (gameTime < explosionTime + TIME_FOR_EXPLOSION * 0.1)
	{
		explosionSprite.setTextureRect(IntRect(0, 0, 96, 96));
	}
	else if (gameTime > explosionTime + TIME_FOR_EXPLOSION * 0.1 && gameTime < explosionTime + TIME_FOR_EXPLOSION * 0.2)
	{
		explosionSprite.setTextureRect(IntRect(96, 0, 96, 96));
	}
	else if (gameTime > explosionTime + TIME_FOR_EXPLOSION * 0.2 && gameTime < explosionTime + TIME_FOR_EXPLOSION * 0.3)
	{
		explosionSprite.setTextureRect(IntRect(192, 0, 96, 96));
	}
	else if (gameTime > explosionTime + TIME_FOR_EXPLOSION * 0.3 && gameTime < explosionTime + TIME_FOR_EXPLOSION * 0.4)
	{
		explosionSprite.setTextureRect(IntRect(288, 0, 96, 96));
	}
	else if (gameTime > explosionTime + TIME_FOR_EXPLOSION * 0.4 && gameTime < explosionTime + TIME_FOR_EXPLOSION * 0.5)
	{
		explosionSprite.setTextureRect(IntRect(0, 96, 96, 96));
	}
	else if (gameTime > explosionTime + TIME_FOR_EXPLOSION * 0.5 && gameTime < explosionTime + TIME_FOR_EXPLOSION * 0.6)
	{
		explosionSprite.setTextureRect(IntRect(96, 96, 96, 96));
	}
	else if (gameTime > explosionTime + TIME_FOR_EXPLOSION * 0.6 && gameTime < explosionTime + TIME_FOR_EXPLOSION * 0.7)
	{
		explosionSprite.setTextureRect(IntRect(192, 96, 96, 96));
	}
	else if (gameTime > explosionTime + TIME_FOR_EXPLOSION * 0.7 && gameTime < explosionTime + TIME_FOR_EXPLOSION * 0.8)
	{
		explosionSprite.setTextureRect(IntRect(288, 96, 96, 96));
	}
	else if (gameTime > explosionTime + TIME_FOR_EXPLOSION * 0.8 && gameTime < explosionTime + TIME_FOR_EXPLOSION * 0.9)
	{
		explosionSprite.setTextureRect(IntRect(96, 192, 96, 96));
	}
	else if (gameTime > explosionTime + TIME_FOR_EXPLOSION * 0.9 && gameTime < explosionTime + TIME_FOR_EXPLOSION * 1.0)
	{
		explosionSprite.setTextureRect(IntRect(192, 192, 96, 96));
	}
}

void Boomb::Update(float& gameTime)
{
	if (gameTime > explosionTime + TIME_FOR_EXPLOSION)
	{
		isAlive = false;
	}
}

void Boomb::Draw(RenderWindow& window, Texture& playersBombTexture, Texture& bombExplosionTexture, float& gameTime)
{
	AnimationBombBeforeExplosion(playersBombTexture, gameTime);
	ExplosionAnimation(bombExplosionTexture, gameTime);
	if (gameTime < createTime + TIME_BEFORE_EXPLOSION)
	{
		window.draw(bombSprite);
	}
	else if (gameTime > explosionTime && gameTime < explosionTime + TIME_FOR_EXPLOSION)
	{
		window.draw(explosionSprite);
	}
}