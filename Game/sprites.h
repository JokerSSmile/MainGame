#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

struct Sprites
{
	//background wall
	Image wallBackground;
	Texture wallBackgroundTexture;
	Sprite wallBackgroundSprite;
	
	//background floor
	Image floorBackground;
	Texture floorBackgroundTexture;
	Sprite floorBackgroundSprite;
	
	//hero
	Image heroImage;
	Texture heroTexture;

	//enemy image
	Image enemyImage;
	Texture enemyTexture;
	
	//standAndShoot
	Image standAndShootImage;
	Texture  standAndShootTexture;

	//bullets
	Texture bulletTexture;

	void LoadBackgroundSprites()
	{
		wallBackground.loadFromFile("images/walls.png");
		wallBackgroundTexture.loadFromImage(wallBackground);
		wallBackgroundSprite.setTexture(wallBackgroundTexture);
		floorBackground.loadFromFile("images/floor.png");
		floorBackgroundTexture.loadFromImage(floorBackground);
		floorBackgroundSprite.setTexture(floorBackgroundTexture);
	}

	void LoadHeroImage()
	{
		heroImage.loadFromFile("images/body_1.png");
		heroTexture.loadFromImage(heroImage);
	}

	void LoadEnemyImage()
	{
		enemyImage.loadFromFile("images/fly.png");
		enemyTexture.loadFromImage(enemyImage);
		standAndShootImage.loadFromFile("images/StandAndShoot.png");
		standAndShootTexture.loadFromImage(standAndShootImage);
	}

	void LoadBulletTexture()
	{
		bulletTexture.loadFromFile("images/bullets.png");
	}

	void InitImages()
	{
		LoadBackgroundSprites();
		LoadHeroImage();
		LoadEnemyImage();
		LoadBulletTexture();
	}
};
