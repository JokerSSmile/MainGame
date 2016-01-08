#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

const String MAIN_MENU_TEXTURE_PATH = "resources/images/main_menu.png";
const String PAUSE_TEXTURE_PATH = "resources/images/pause_menu.png";
const String FONT_8_BIT_PATH = "resources/fonts/8bitfont.ttf";
const String WALL_TEXTURE_PATH = "resources/images/walls.png";
const String WALL_BULLET_TEXTURE_PATH = "resources/images/bullet_wall.png";
const String FLOOR_TEXTURE_PATH = "resources/images/floor.png";
const String BOMB_TEXTURE_IN_STATUS_BAR = "resources/images/addBomb.png";
const String PLAYERS_BODY_TEXTURE_PATH = "resources/images/body_1.png";
const String PLAYERS_HEAD_TEXTURE_PATH = "resources/images/head.png";
const String ENEMY_FLY_TEXTURE_PATH = "resources/images/fly.png";
const String ENEMY_STAND_AND_SHOOT_TEXTURE_PATH = "resources/images/StandAndShoot.png";
const String ENEMY_DESTROY_EFFECT_TEXTURE_PATH = "resources/images/enemy_destroy_effect.png";
const String ENEMY_FOLLOW_TEXTURE_PATH = "resources/images/enemy_follow.png";
const String BULLET_TEXTURE_PATH = "resources/images/bullets.png";
const String TEARS_DESTROY_EFFECT_TEXTURE_PATH = "resources/images/tears_effect.png";
const String ENEMY_BULLET_DESTROY_EFFECT_TEXTURE_PATH = "resources/images/enemy_tears_effect.png";
const String BOMB_EXPLOSION_TEXTURE_PATH = "resources/images/explosion.png";
const String BOMB_BEFORE_EXPLOSION_TEXTURE = "resources/images/bomb_state.png";
const String HEART_TEXTURES_IN_STATUS_BAR = "resources/images/hearts.png";

struct Sprites
{
	//menu
	Texture mainMenuTexture;
	Texture pauseTexture;

	//background wall
	Image wallBackground;
	Texture wallBackgroundTexture;
	Sprite wallBackgroundSprite;
	Texture bombCount;
	Texture wallBulletTexture;
	Sprite wallBulletSprite;

	//background floor
	Image floorBackground;
	Texture floorBackgroundTexture;
	Sprite floorBackgroundSprite;

	//hero
	Image heroImage;
	Texture heroTexture;

	//images in health bar
	Texture heartTexture;

	//enemy image
	Image enemyImage;
	Texture enemyTexture;
	Image poofImage;
	Texture poofTexture;

	//standAndShoot
	Image standAndShootImage;
	Texture  standAndShootTexture;

	//enemy follow
	Texture enemyFollowTexture;

	//bullets
	Texture bulletTexture;
	Texture bulletEffectTexture;
	Texture bulletEffectTextureEnemy;

	//hero Head
	Texture headTexture;

	//bombs
	Texture bombExplosion;
	Texture bombState;

	//font
	Font font;

	void LoadBackgroundSprites()
	{
		wallBackground.loadFromFile(WALL_TEXTURE_PATH);
		wallBackgroundTexture.loadFromImage(wallBackground);
		wallBackgroundSprite.setTexture(wallBackgroundTexture);
		floorBackground.loadFromFile(FLOOR_TEXTURE_PATH);
		floorBackgroundTexture.loadFromImage(floorBackground);
		floorBackgroundSprite.setTexture(floorBackgroundTexture);
		wallBulletTexture.loadFromFile(WALL_BULLET_TEXTURE_PATH);
		wallBulletSprite.setTexture(wallBulletTexture);

		bombCount.loadFromFile(BOMB_TEXTURE_IN_STATUS_BAR);
	}

	void LoadHeroImage()
	{
		heroImage.loadFromFile(PLAYERS_BODY_TEXTURE_PATH);
		heroTexture.loadFromImage(heroImage);
		headTexture.loadFromFile(PLAYERS_HEAD_TEXTURE_PATH);
		heartTexture.loadFromFile(HEART_TEXTURES_IN_STATUS_BAR);
	}

	void LoadEnemyImage()
	{
		enemyImage.loadFromFile(ENEMY_FLY_TEXTURE_PATH);
		enemyTexture.loadFromImage(enemyImage);
		standAndShootImage.loadFromFile(ENEMY_STAND_AND_SHOOT_TEXTURE_PATH);
		standAndShootTexture.loadFromImage(standAndShootImage);
		poofImage.loadFromFile(ENEMY_DESTROY_EFFECT_TEXTURE_PATH);
		poofTexture.loadFromImage(poofImage);
		enemyFollowTexture.loadFromFile(ENEMY_FOLLOW_TEXTURE_PATH);
	}

	void LoadBulletTexture()
	{
		bulletTexture.loadFromFile(BULLET_TEXTURE_PATH);
		bulletEffectTexture.loadFromFile(TEARS_DESTROY_EFFECT_TEXTURE_PATH);
		bulletEffectTextureEnemy.loadFromFile(ENEMY_BULLET_DESTROY_EFFECT_TEXTURE_PATH);
	}

	void LoadMainMenuTextures()
	{
		mainMenuTexture.loadFromFile(MAIN_MENU_TEXTURE_PATH);
		pauseTexture.loadFromFile(PAUSE_TEXTURE_PATH);
	}

	void LoadFont()
	{
		font.loadFromFile(FONT_8_BIT_PATH);
	}

	void LoadBombsTextures()
	{
		bombExplosion.loadFromFile(BOMB_EXPLOSION_TEXTURE_PATH);
		bombState.loadFromFile(BOMB_BEFORE_EXPLOSION_TEXTURE);
	}

	void InitImages()
	{
		LoadMainMenuTextures();
		LoadBackgroundSprites();
		LoadHeroImage();
		LoadEnemyImage();
		LoadBulletTexture();
		LoadBombsTextures();
	}
};
