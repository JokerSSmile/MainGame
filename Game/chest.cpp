#include "chest.h"

void Chest::SetFilling()
{
	int rand = int(RandomNumber(0, 6));
	if (rand == 0)
	{
		filling = INCREASE_SPEED;
	}
	else if (rand == 1)
	{
		filling = INCREASE_DAMAGE;
	}
	else if (rand == 2)
	{
		filling = HEALTH;
	}
	else if (rand == 3)
	{
		filling = BOMB;
	}
	else if (rand == 4)
	{
		filling = RANGE_UP;
	}
	else if (rand == 5)
	{
		filling = FIRE_RATE_UP;
	}
}

void Chest::CheckOpening(Player& p, Sound& openingSound)
{
	if (Collision::PixelPerfectTest(p.sprite, chestSpriteClosed))
	{
		isOpened = true;
		openingSound.play();
	}
}

void Chest::GiveFirstPresent(RenderWindow& window, Sprite& increaseSpeedSprite)
{
	increaseSpeedSprite.setPosition(position.x, verticalPosition);
	window.draw(increaseSpeedSprite);
}

void Chest::GiveSecondPresent(RenderWindow& window, Sprite& increaseDamageSprite)
{
	increaseDamageSprite.setPosition(position.x, verticalPosition);
	window.draw(increaseDamageSprite);
}

void Chest::GiveThirdPresent(RenderWindow& window, Sprite& healthSprite)
{
	healthSprite.setPosition(position.x, verticalPosition);
	window.draw(healthSprite);
}

void Chest::GiveForthPresent(RenderWindow& window, Sprite& bombSprite)
{
	bombSprite.setPosition(position.x, verticalPosition);
	window.draw(bombSprite);
}

void Chest::GiveFifthPresent(RenderWindow& window, Sprite& rangeSprite)
{
	rangeSprite.setPosition(position.x, verticalPosition);
	window.draw(rangeSprite);
}

void Chest::GiveSixthPresent(RenderWindow& window, Sprite& fireRateUp)
{
	fireRateUp.setPosition(position.x, verticalPosition);
	window.draw(fireRateUp);
}

void Chest::SetPresent(RenderWindow& window, Sprites& mySprites)
{
	switch (filling)
	{
	case INCREASE_SPEED: GiveFirstPresent(window, mySprites.increaseSpeedSprite); break;
	case INCREASE_DAMAGE: GiveSecondPresent(window, mySprites.increaseDamageSprite); break;
	case HEALTH: GiveThirdPresent(window, mySprites.healthSprite); break;
	case BOMB: GiveForthPresent(window, mySprites.bombSprite); break;
	case RANGE_UP: GiveFifthPresent(window, mySprites.rangeUpSprite); break;
	case FIRE_RATE_UP: GiveSixthPresent(window, mySprites.fireRateUpSprite);
	}
}

void Chest::CheckCollisionWithPresent(Player& p, Sprites& mySprites)
{
	if (Collision::PixelPerfectTest(p.sprite, mySprites.increaseSpeedSprite))
	{
		isPresentTaken = true;
		p.speed += SPEED_BONUS;
	}
	else if (Collision::PixelPerfectTest(p.sprite, mySprites.increaseDamageSprite))
	{
		isPresentTaken = true;
		p.damage += DAMAGE_BONUS;
	}
	else if (Collision::PixelPerfectTest(p.sprite, mySprites.healthSprite))
	{
		isPresentTaken = true;
		if (p.health >= MAX_PLAYER_HEALTH - 1)
		{
			p.health = MAX_PLAYER_HEALTH;
		}
		else
		{
			p.health += HEAL_BONUS;
		}
	}
	else if (Collision::PixelPerfectTest(p.sprite, mySprites.bombSprite))
	{
		isPresentTaken = true;
		p.bombCount += BOMB_BONUS;
	}
	else if (Collision::PixelPerfectTest(p.sprite, mySprites.rangeUpSprite))
	{
		isPresentTaken = true;
		p.range += RANGE_BONUS;
	}
	else if (Collision::PixelPerfectTest(p.sprite, mySprites.fireRateUpSprite))
	{
		isPresentTaken = true;
		p.timeBetweenShoots -= FIRE_RATE_UP_BONUS;
	}
}

void Chest::UpdateDrawText(Font& font, RenderWindow& window, View& view)
{
	bonusText.setFont(font);
	bonusText.setCharacterSize(15);
	bonusText.setPosition(view.getCenter().x - WINDOW_WIDTH / 2 + BONUS_TEXT_SHIFT.x, view.getCenter().y + WINDOW_HEIGHT / 2 - BONUS_TEXT_SHIFT.y);
	bonusText.setColor(Color::White);
	switch (filling)
	{
	case INCREASE_SPEED:  bonusText.setString("SPEED UP");
		break;
	case INCREASE_DAMAGE: bonusText.setString("INCREASE DAMAGE");
		break;
	case HEALTH: bonusText.setString("HEAL");
		break;
	case BOMB: bonusText.setString("ADD BOMB");
		break;
	case RANGE_UP: bonusText.setString("RANGE UP");
		break;
	case FIRE_RATE_UP: bonusText.setString("FIRE RATE UP");
		break;
	default:
		break;
	}
	
}

void Chest::DrawText(RenderWindow& window, float& gameTime, float& playerY, View& view)
{
	if (isOpened == false)
	{
		if (playerY > view.getCenter().y - TILE_SIDE / 2)
		{
			verticalPosition = view.getCenter().y - TILE_SIDE;
		}
		else
		{
			verticalPosition = view.getCenter().y;
		}
	}
	if (isPresentTaken == false)
		{
			takePresentTime = gameTime;
		}
	if (gameTime > takePresentTime && gameTime < takePresentTime + TIME_FOR_SHOW_BONUS_TYPE_TEXT)
	{

		window.draw(bonusText);
	}
}

void Chest::Update(Player& p, Sound& openingSound, Sprites& mySprites)
{
	chestSpriteOpened.setTexture(chestTexture);
	chestSpriteClosed.setTexture(chestTexture);
	if (isOpened == false)
	{
		CheckOpening(p, openingSound);
		SetFilling();
		chestSpriteClosed.setPosition(position.x - size.x / 2, position.y - size.y / 2);
	}
	else
	{
		chestSpriteOpened.setPosition(position.x - size.x / 2, position.y - size.y / 2);
		if (isPresentTaken == false)
		{
			CheckCollisionWithPresent(p, mySprites);
		}
	}
}

void Chest::DrawChest(RenderWindow& window, Sprites& mySprites)
{
	if (isOpened == false)
	{
		window.draw(chestSpriteClosed);
	}
	else
	{
		if (chestSpriteOpened.getPosition().x != 0)
		{
			window.draw(chestSpriteOpened);
		}
		if (isPresentTaken == false)
		{
			SetPresent(window, mySprites);
		}
	}
}