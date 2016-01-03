#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

static FloatRect GetSpriteRect(const Sprite & sprite)
{
	const Vector2f pos = sprite.getPosition();
	const Vector2f size = { sprite.getGlobalBounds().width, sprite.getGlobalBounds().height };
	return FloatRect(pos, size);
	//return sprite.getGlobalBounds();
}

enum GameState
{
	MAIN_MENU,
	GAME,
	PAUSE
};

//colors
const Color COLOR_AFTER_HIT = { 255, 150, 150 };//255,150,150
const Color COLOR_WHILE_MOUSE_ON_TEXT = { 125, 125, 135 };

//main menu
const Vector2f START_GAME_TEXT_SHIFT = { 10, 100 };
const Vector2f EXIT_GAME_TEXT_SHIFT = { -10, -100 };

//player
const float PLAYER_POSITION_X = 250;
const float PLAYER_POSITION_Y = 200;
const int PLAYER_WIDTH = 36;
const int PLAYER_HEIGHT = 26;
const float MAX_PLAYER_HEALTH = 10;// == start health
const float TIME_BETWEEN_SHOOTS_PLAYER = 0.5f;//0.5
const float TIME_FOR_SHOOT_ANIMATION = 0.2f;//0.2
const float TIME_FOR_PLAYER_HIT_CD = 1;

//enemy
const float FLY1_POSITION_X = 350;
const float FLY1_POSITION_Y = 200;
const float FLY2_POSITION_X = 250;
const float FLY2_POSITION_Y = 300;
const int FLY_WIDTH = 57;
const int FLY_HEIGHT = 45;
const float  ENEMY_DESTROY_EFFECT = 0.07f;
const float CHANGE_COLOR_EFFECT = 0.3f;

const int HEIGHT_MAP = 20;
const int WIDTH_MAP = 45;

//window
const int WINDOW_WIDTH = 960;
const int WINDOW_HEIGHT = 640;

//tile
const int TILE_SIDE = 64;

//bullets
const int BULLET_SIDE = 32;
const float PLAYERS_BULLET_SPEED = 0.10f;//0.1
const float ENEMY_BULLET_SPEED = 0.12f;//0.12
const float BULLET_LIFE_TIME = 1.f;//1
const float BULLET_ANIMATION_STEP_TIME = 0.05f;//0.05
const float BULLET_SHIFT_IF_SHOOT_UP = 20.f;

//bonuses
const float SPEED_BONUS = 0.01f;
const float DAMAGE_BONUS = 0.5f;
const float HEAL_BONUS = 1;
const int BOMB_BONUS = 1;

//bomb
const float TIME_BEFORE_EXPLOSION = 2.f;
const float TIME_FOR_EXPLOSION = 1.f;
const float BOMB_DAMAGE = 1.f;//1
const int EXPLOSION_FRAMES_COUNT = 12;
const Vector2f EXPLOSION_ANIMATION_SHIFT = { 64, 128 };
const Vector2f BOMB_DAMAGE_ZONE_SHIFT = { 23.f, 20.f };
