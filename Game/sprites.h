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
	Texture bombCount;

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
	Image poofImage;
	Texture poofTexture;

	//standAndShoot
	Image standAndShootImage;
	Texture  standAndShootTexture;

	//bullets
	Texture bulletTexture;
	Texture bulletEffectTexture;
	Texture bulletEffectTextureEnemy;

	//hero Head
	Texture headTexture;

	//bombs
	Texture bombExplosion;
	Texture bombState;

	Font font;

	void LoadBackgroundSprites()
	{
		wallBackground.loadFromFile("images/walls.png");
		wallBackgroundTexture.loadFromImage(wallBackground);
		wallBackgroundSprite.setTexture(wallBackgroundTexture);
		floorBackground.loadFromFile("images/floor.png");
		floorBackgroundTexture.loadFromImage(floorBackground);
		floorBackgroundSprite.setTexture(floorBackgroundTexture);

		bombCount.loadFromFile("images/addBomb.png");
	}

	void LoadHeroImage()
	{
		heroImage.loadFromFile("images/body_1.png");
		heroTexture.loadFromImage(heroImage);
		headTexture.loadFromFile("images/head.png");
	}

	void LoadEnemyImage()
	{
		enemyImage.loadFromFile("images/fly.png");
		enemyTexture.loadFromImage(enemyImage);
		standAndShootImage.loadFromFile("images/StandAndShoot.png");
		standAndShootTexture.loadFromImage(standAndShootImage);
		poofImage.loadFromFile("images/enemy_destroy_effect.png");
		poofTexture.loadFromImage(poofImage);
	}

	void LoadBulletTexture()
	{
		bulletTexture.loadFromFile("images/bullets.png");
		bulletEffectTexture.loadFromFile("images/tears_effect.png");
		bulletEffectTextureEnemy.loadFromFile("images/enemy_tears_effect.png");
	}

	void LoadFont()
	{
		font.loadFromFile("fonts/8bitfont.ttf");
	}

	void LoadBombsTextures()
	{
		bombExplosion.loadFromFile("images/explosion.png");
		bombState.loadFromFile("images/bomb_state.png");
	}

	void InitImages()
	{
		LoadBackgroundSprites();
		LoadHeroImage();
		LoadEnemyImage();
		LoadBulletTexture();
		LoadBombsTextures();
	}
};
