#include "bomb.h"

void Boomb::AnimationBombBeforeExplosion(Texture& playersBombTexture, float& gameTime, float& time)
{
	bombSprite.setTexture(playersBombTexture);
	bombSprite.setScale(2, 2);
	bombSprite.setPosition(position.x, position.y);
	bombSprite.setTextureRect(IntRect(0, 32, 32, 32));

	currentFrame += 0.005f * time;
	if (currentFrame > 3)
	{
		currentFrame -= 3;
	}

	if (int(currentFrame) == 0)
	{
		bombSprite.setColor(Color::White);
	}
	else if (int(currentFrame) == 1)
	{
		bombSprite.setColor(Color::Red);
	}
	else
	{
		bombSprite.setColor(Color::Yellow);
	}
}

void Boomb::ExplosionAnimation(Texture& bombExplosionTexture, float& gameTime, float& time)
{
	explosionSprite.setPosition(position.x - EXPLOSION_ANIMATION_SHIFT.x, position.y - EXPLOSION_ANIMATION_SHIFT.y);
	explosionSprite.setTexture(bombExplosionTexture);
	explosionSprite.setScale(2, 2);

	if (isAlive == true)
	{
		damageZone.setSize(Vector2f(float(explosionSprite.getGlobalBounds().width * 0.75), float(explosionSprite.getGlobalBounds().height / 2)));
		damageZone.setPosition(explosionSprite.getPosition().x + BOMB_DAMAGE_ZONE_SHIFT.x, explosionSprite.getPosition().y + explosionSprite.getGlobalBounds().height / 2 + BOMB_DAMAGE_ZONE_SHIFT.y);
	}
	if (currentExplosionFrame < EXPLOSION_FRAMES_COUNT)
	{
		currentExplosionFrame += 0.006f * time;
	}

	explosionSprite.setTextureRect(IntRect(96 * (int(currentExplosionFrame) % 4), 96 * (int(currentExplosionFrame) / 4), 96, 96));
}

void Boomb::Update(float& gameTime)
{
	if (gameTime > explosionTime + TIME_FOR_EXPLOSION / 3 || gameTime < 1)
	{
		isAlive = false;
		damageZone.setPosition(-TILE_SIDE * 2, -TILE_SIDE * 2);
	}
}

void Boomb::PlaySound(Sound& explosionSound, float& gameTime)
{

	if (currentExplosionFrame == 0 && currentFrame != 0 && gameTime >= explosionTime)
	{
		explosionSound.play();
	}
}

void Boomb::Draw(RenderWindow& window, Texture& playersBombTexture, Texture& bombExplosionTexture, float& gameTime, float& time)
{
	if (gameTime < createTime + TIME_BEFORE_EXPLOSION && createTime != 0)
	{
		AnimationBombBeforeExplosion(playersBombTexture, gameTime, time);
		window.draw(bombSprite);
		currentExplosionFrame = 0;
	}
	else if (gameTime > explosionTime && gameTime < explosionTime + TIME_FOR_EXPLOSION && createTime != 0)
	{
		ExplosionAnimation(bombExplosionTexture, gameTime, time);
		window.draw(explosionSprite);
		currentFrame = 0;
	}
}