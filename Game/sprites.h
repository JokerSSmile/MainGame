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
const String ENEMY_WORM_TEXTURE_PATH = "resources/images/worm.png";
const String ENEMY_STAND_AND_SHOOT_TEXTURE_PATH = "resources/images/StandAndShoot.png";
const String ENEMY_DESTROY_EFFECT_TEXTURE_PATH = "resources/images/enemy_destroy_effect.png";
const String ENEMY_FOLLOW_TEXTURE_PATH = "resources/images/enemy_follow.png";
const String ENEMY_FOLLOW_HEAD_TEXTURE_PATH = "resources/images/follow_head.png";
const String BULLET_TEXTURE_PATH = "resources/images/bullets.png";
const String TEARS_DESTROY_EFFECT_TEXTURE_PATH = "resources/images/tears_effect.png";
const String ENEMY_BULLET_DESTROY_EFFECT_TEXTURE_PATH = "resources/images/enemy_tears_effect.png";
const String BOMB_EXPLOSION_TEXTURE_PATH = "resources/images/explosion.png";
const String BOMB_BEFORE_EXPLOSION_TEXTURE = "resources/images/bomb_state.png";
const String HEART_TEXTURES_IN_STATUS_BAR = "resources/images/hearts.png";
const String MANHOLE_TEXTURE_PATH = "resources/images/manhole.png";
const String BOSS_TEXTURE_PATH = "resources/images/boss.png";
const String CONTROLS_TEXTURE_PATH = "resources/images/controls.png";
const String HEALTHBAR_TEXTURE_PATH = "resources/images/health_bar.png";

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

	//controls
	Texture controlsTexture;

	//manhole
	Texture manholeTexture;

	//hero
	Image heroImage;
	Texture heroTexture;

	//images in health bar
	Texture heartTexture;
	Texture healthBarTexture;
	Sprite healthBar;

	//enemies
	Image enemyImage;
	Texture enemyTexture;
	Image poofImage;
	Texture poofTexture;
	Texture enemyFollowHead;
	Image standAndShootImage;
	Texture  standAndShootTexture;
	Texture enemyFollowTexture;
	Texture wormTexture;

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

	//chest
	Texture increaseSpeedTexture;
	Texture IncreaseDamageTexture;
	Texture HealthTexture;
	Texture BombTexture;
	Sprite increaseSpeedSprite;
	Sprite increaseDamageSprite;
	Sprite healthSprite;
	Sprite bombSprite;

	//boss
	Texture bossTexture;

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
		controlsTexture.loadFromFile(CONTROLS_TEXTURE_PATH);

		manholeTexture.loadFromFile(MANHOLE_TEXTURE_PATH);

		bombCount.loadFromFile(BOMB_TEXTURE_IN_STATUS_BAR);
	}

	void LoadChestSprites()
	{
		increaseSpeedTexture.loadFromFile("resources/images/increaseSpeed.png");
		IncreaseDamageTexture.loadFromFile("resources/images/IncreaseDamage.png");
		HealthTexture.loadFromFile("resources/images/addHeart.png");
		BombTexture.loadFromFile("resources/images/addBomb.png");

		increaseSpeedSprite.setTexture(increaseSpeedTexture);
		increaseDamageSprite.setTexture(IncreaseDamageTexture);
		healthSprite.setTexture(HealthTexture);
		bombSprite.setTexture(BombTexture);

		increaseSpeedSprite.setOrigin(increaseSpeedSprite.getGlobalBounds().width / 2, increaseSpeedSprite.getGlobalBounds().height / 2);
		increaseDamageSprite.setOrigin(increaseDamageSprite.getGlobalBounds().width / 2, increaseDamageSprite.getGlobalBounds().height / 2);
		healthSprite.setOrigin(healthSprite.getGlobalBounds().width / 2, healthSprite.getGlobalBounds().height / 2);
		bombSprite.setOrigin(bombSprite.getGlobalBounds().width / 2, bombSprite.getGlobalBounds().height / 2);

		increaseSpeedSprite.setScale(1.5, 1.5);
		increaseDamageSprite.setScale(1.5, 1.5);
		healthSprite.setScale(1.5, 1.5);
		bombSprite.setScale(1.5, 1.5);
		healthBarTexture.loadFromFile(HEALTHBAR_TEXTURE_PATH);
		healthBar.setTexture(healthBarTexture);
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
		enemyFollowHead.loadFromFile(ENEMY_FOLLOW_HEAD_TEXTURE_PATH);
		wormTexture.loadFromFile(ENEMY_WORM_TEXTURE_PATH);
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

	void LoadBossSprite()
	{
		bossTexture.loadFromFile(BOSS_TEXTURE_PATH);
	}

	void InitImages()
	{
		LoadBossSprite();
		LoadChestSprites();
		LoadMainMenuTextures();
		LoadBackgroundSprites();
		LoadHeroImage();
		LoadEnemyImage();
		LoadBulletTexture();
		LoadBombsTextures();
	}
};
