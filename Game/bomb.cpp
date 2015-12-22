#include "bomb.h"

void Boomb::AnimationBombBeforeExplosion(Texture& playersBombTexture, float& gameTime)
{
	bombSprite.setPosition(position.x, position.y);
	bombSprite.setTexture(playersBombTexture);
	bombSprite.setScale(2, 2);
	if (gameTime < createTime + TIME_BEFORE_EXPLOSION / 4)
	{
		bombSprite.setTextureRect(IntRect(0, 0, 32, 32));
	}
	else if (gameTime > createTime + TIME_BEFORE_EXPLOSION / 4 && gameTime < createTime + TIME_BEFORE_EXPLOSION / 2)
	{
		bombSprite.setTextureRect(IntRect(0, 32, 32, 32));
	}
	else if (gameTime > createTime + TIME_BEFORE_EXPLOSION / 2 && gameTime < createTime + TIME_BEFORE_EXPLOSION * 0.75)
	{
		bombSprite.setTextureRect(IntRect(0, 0, 32, 32));
	}
	else if (gameTime > createTime + TIME_BEFORE_EXPLOSION * 0.75 && gameTime < createTime + TIME_BEFORE_EXPLOSION)
	{
		bombSprite.setTextureRect(IntRect(0, 32, 32, 32));
	}
}

void Boomb::ExplosionAnimation(Texture& bombExplosionTexture, float& gameTime)
{
	explosionSprite.setPosition(position.x - 48, position.y - 96);
	explosionSprite.setTexture(bombExplosionTexture);
	explosionSprite.setScale(2, 2);
	if (gameTime > createTime + TIME_BEFORE_EXPLOSION && gameTime < createTime + 1 + TIME_BEFORE_EXPLOSION * 0.25)
	{
		cout << "1 " << endl;
		explosionSprite.setTextureRect(IntRect(96, 0, 96, 96));
	}
	else if (gameTime > createTime + 1 + TIME_BEFORE_EXPLOSION * 0.25 && gameTime < createTime + 1 + TIME_BEFORE_EXPLOSION * 0.5)
	{
		cout << "2 " << endl;
		explosionSprite.setTextureRect(IntRect(288, 0, 96, 96));
	}
	else if (gameTime > createTime + 1 + TIME_BEFORE_EXPLOSION * 0.5 && gameTime < createTime + 1 + TIME_BEFORE_EXPLOSION * 0.75)
	{
		cout << "3 " << endl;
		explosionSprite.setTextureRect(IntRect(0, 96, 96, 96));
	}
	else if (gameTime > createTime + 1 + TIME_BEFORE_EXPLOSION * 0.75 && gameTime < createTime + 1 + TIME_BEFORE_EXPLOSION)
	{
		cout << "4 " << endl;
		explosionSprite.setTextureRect(IntRect(288, 96, 96, 96));
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
	else if (gameTime > createTime + TIME_BEFORE_EXPLOSION && gameTime < createTime + TIME_BEFORE_EXPLOSION * 2)
	{
		window.draw(explosionSprite);
	}
}