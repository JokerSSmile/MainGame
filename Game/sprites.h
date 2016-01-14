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
const String RANGE_TEXTURE_PATH = "resources/images/range_up.png";
const String FIRE_RATE_UP_TEXTURE_PATH = "resources/images/fire_rate_up.png";

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

	//chest bonuses
	Texture increaseSpeedTexture;
	Texture IncreaseDamageTexture;
	Texture healthTexture;
	Texture bombTexture;
	Texture rangeUpTexture;
	Texture fireRateUpTexture;
	Sprite increaseSpeedSprite;
	Sprite increaseDamageSprite;
	Sprite healthSprite;
	Sprite bombSprite;
	Sprite rangeUpSprite;
	Sprite fireRateUpSprite;


	//boss
	Texture bossTexture;

	void LoadBackgroundSprites();

	void LoadChestSprites();

	void LoadHeroImage();
	void LoadEnemyImage();
	void LoadBulletTexture();

	void LoadMainMenuTextures();
	void LoadFont();
	void LoadBombsTextures();
	void LoadBossSprite();

	void InitImages();
};
