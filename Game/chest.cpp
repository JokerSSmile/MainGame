#include "chest.h"

int Chest::RandomNumber()
{
	return (double)rand() / (RAND_MAX + 1) * 4;
}

void Chest::SetFilling()
{
	int rand = RandomNumber();
	if (rand == 0)
	{
		filling = IncreaseSpeed;
	}
	else if (rand == 1)
	{
		filling = IncreaseDamage;
	}
	else if (rand == 2)
	{
		filling = Health;
	}
	else if (rand == 3)
	{
		filling = Bomb;
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

void Chest::SetPresent(RenderWindow& window, Sprite& increaseSpeedSprite, Sprite& increaseDamageSprite, Sprite& healthSprite, Sprite& bombSprite)
{
	switch (filling)
	{
	case IncreaseSpeed: GiveFirstPresent(window, increaseSpeedSprite); break;
	case IncreaseDamage: GiveSecondPresent(window, increaseDamageSprite); break;
	case Health: GiveThirdPresent(window, healthSprite); break;
	case Bomb: GiveForthPresent(window, bombSprite); break;
	}
}

void Chest::CheckCollisionWithPresent(Player& p, Sprite& increaseSpeedSprite, Sprite& increaseDamageSprite, Sprite& healthSprite, Sprite& bombSprite)
{
	if (Collision::PixelPerfectTest(p.sprite, increaseSpeedSprite))
	{
		isPresentTaken = true;
		p.speed += SPEED_BONUS;
	}
	else if (Collision::PixelPerfectTest(p.sprite, increaseDamageSprite))
	{
		isPresentTaken = true;
		p.damage += DAMAGE_BONUS;
	}
	else if (Collision::PixelPerfectTest(p.sprite, healthSprite))
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
	else if (Collision::PixelPerfectTest(p.sprite, bombSprite))
	{
		isPresentTaken = true;
		p.bombCount += BOMB_BONUS;
	}
}

void Chest::UpdateDrawText(Font& font, RenderWindow& window, View& view)
{
	bonusText.setFont(font);
	bonusText.setCharacterSize(15);
	bonusText.setPosition(view.getCenter().x, view.getCenter().y);
	bonusText.setColor(Color::White);
	switch (filling)
	{
	case IncreaseSpeed:  bonusText.setString("SPEED UP");
		break;
	case IncreaseDamage: bonusText.setString("INCREASE DAMAGE");
		break;
	case Health: bonusText.setString("HEAL");
		break;
	case Bomb: bonusText.setString("ADD BOMB");
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

void Chest::Update(Player& p, Sound& openingSound, Sprite& increaseSpeedSprite, Sprite& increaseDamageSprite, Sprite& healthSprite, Sprite& bombSprite)
{
	chestSpriteOpened.setTexture(chestTexture);
	chestSpriteClosed.setTexture(chestTexture);
	if (isOpened == false)
	{
		SetFilling();
		chestSpriteClosed.setPosition(position.x - size.x / 2, position.y - size.y / 2);
		CheckOpening(p, openingSound);
	}
	else
	{
		chestSpriteOpened.setPosition(position.x - size.x / 2, position.y - size.y / 2);
		if (isPresentTaken == false)
		{
			CheckCollisionWithPresent(p, increaseSpeedSprite, increaseDamageSprite, healthSprite, bombSprite);
		}
	}
}

void Chest::DrawChest(RenderWindow& window, Sprite& increaseSpeedSprite, Sprite& increaseDamageSprite, Sprite& healthSprite, Sprite& bombSprite)
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
			SetPresent(window, increaseSpeedSprite, increaseDamageSprite, healthSprite, bombSprite);
		}
	}
}