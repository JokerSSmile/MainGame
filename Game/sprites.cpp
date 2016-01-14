#include "sprites.h"

void Sprites::LoadBackgroundSprites()
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

void Sprites::LoadChestSprites()
{
	increaseSpeedTexture.loadFromFile("resources/images/increaseSpeed.png");
	IncreaseDamageTexture.loadFromFile("resources/images/IncreaseDamage.png");
	healthTexture.loadFromFile("resources/images/addHeart.png");
	bombTexture.loadFromFile("resources/images/addBomb.png");
	rangeUpTexture.loadFromFile(RANGE_TEXTURE_PATH);
	fireRateUpTexture.loadFromFile(FIRE_RATE_UP_TEXTURE_PATH);

	increaseSpeedSprite.setTexture(increaseSpeedTexture);
	increaseDamageSprite.setTexture(IncreaseDamageTexture);
	healthSprite.setTexture(healthTexture);
	bombSprite.setTexture(bombTexture);
	rangeUpSprite.setTexture(rangeUpTexture);
	fireRateUpSprite.setTexture(fireRateUpTexture);

	increaseSpeedSprite.setOrigin(increaseSpeedSprite.getGlobalBounds().width / 2, increaseSpeedSprite.getGlobalBounds().height / 2);
	increaseDamageSprite.setOrigin(increaseDamageSprite.getGlobalBounds().width / 2, increaseDamageSprite.getGlobalBounds().height / 2);
	healthSprite.setOrigin(healthSprite.getGlobalBounds().width / 2, healthSprite.getGlobalBounds().height / 2);
	bombSprite.setOrigin(bombSprite.getGlobalBounds().width / 2, bombSprite.getGlobalBounds().height / 2);
	rangeUpSprite.setOrigin(rangeUpSprite.getGlobalBounds().width / 2, rangeUpSprite.getGlobalBounds().height / 2);
	fireRateUpSprite.setOrigin(fireRateUpSprite.getGlobalBounds().width / 2, fireRateUpSprite.getGlobalBounds().height / 2);

	increaseSpeedSprite.setScale(1.5, 1.5);
	increaseDamageSprite.setScale(1.5, 1.5);
	healthSprite.setScale(1.5, 1.5);
	bombSprite.setScale(1.5, 1.5);
	rangeUpSprite.setScale(1.5, 1.5);
	fireRateUpSprite.setScale(1.5, 1.5);

	healthBarTexture.loadFromFile(HEALTHBAR_TEXTURE_PATH);
	healthBar.setTexture(healthBarTexture);
}

void Sprites::LoadHeroImage()
{
	heroImage.loadFromFile(PLAYERS_BODY_TEXTURE_PATH);
	heroTexture.loadFromImage(heroImage);
	headTexture.loadFromFile(PLAYERS_HEAD_TEXTURE_PATH);
	heartTexture.loadFromFile(HEART_TEXTURES_IN_STATUS_BAR);
}

void Sprites::LoadEnemyImage()
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

void Sprites::LoadBulletTexture()
{
	bulletTexture.loadFromFile(BULLET_TEXTURE_PATH);
	bulletEffectTexture.loadFromFile(TEARS_DESTROY_EFFECT_TEXTURE_PATH);
	bulletEffectTextureEnemy.loadFromFile(ENEMY_BULLET_DESTROY_EFFECT_TEXTURE_PATH);
}

void Sprites::LoadMainMenuTextures()
{
	mainMenuTexture.loadFromFile(MAIN_MENU_TEXTURE_PATH);
	pauseTexture.loadFromFile(PAUSE_TEXTURE_PATH);
}

void Sprites::LoadFont()
{
	font.loadFromFile(FONT_8_BIT_PATH);
}

void Sprites::LoadBombsTextures()
{
	bombExplosion.loadFromFile(BOMB_EXPLOSION_TEXTURE_PATH);
	bombState.loadFromFile(BOMB_BEFORE_EXPLOSION_TEXTURE);
}

void Sprites::LoadBossSprite()
{
	bossTexture.loadFromFile(BOSS_TEXTURE_PATH);
}

void Sprites::InitImages()
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