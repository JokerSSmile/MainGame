#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

static double RandomNumber(int minNum, int maxNum)
{
	return minNum + (double)rand() / (RAND_MAX + 1) * maxNum;
}

enum Direction
{
	LEFT_UP,
	LEFT_DOWN,
	RIGHT_UP,
	RIGHT_DOWN,
	LEFT,
	UP,
	DOWN,
	RIGHT,
	STAND
};

enum GameState
{
	MAIN_MENU,
	GAME,
	PAUSE,
	END_GAME,
	FINISHED
};

enum TileState
{
	WALL,
	ROCK,
	SPIKE,
	D_UP,
	D_DOWN,
	D_LEFT,
	D_RIGHT
};

enum Level
{
	ONE,
	TWO,
	THREE,
	BOSS
};

enum RoomNum
{
	NOT_STATED,
	FIRST,
	SECOND,
	THIRD,
	FORTH,
	FIFTH,
	SIXTH,
	SEVENTH,
	EIGHTH,
	NINTH
};

enum FollowState
{
	FAR,
	NEAR
};

enum ShootingState
{
	SHOOTING,
	STANDING
};

enum BossState
{
	STAY,
	JUMP_UP,
	JUMP_DOWN,
	SHOOT
};

enum ChestFilling
{
	INCREASE_SPEED,
	INCREASE_DAMAGE,
	HEALTH,
	BOMB,
	RANGE_UP,
	FIRE_RATE_UP
};

enum PlayerState
{
	NORMAL,
	TAKE_GIFT
};

//global
const float GAME_TIME_DIFFERENCE = 500;

//start hp
const float STAND_AND_SHOOT_HP_1 = 1.5;
const float STAND_AND_SHOOT_HP_2 = 2;
const float STAND_AND_SHOOT_HP_3 = 4;

const float WORM_HP_1= 2;
const float WORM_HP_2 = 3.5;
const float WORM_HP_3 = 5;

const float FLY_HP_1 = 1;
const float FLY_HP_2 = 1.5;
const float FLY_HP_3 = 2.5;

const float FOLLOW_HP_1 = 2;
const float FOLLOW_HP_2 = 3;
const float FOLLOW_HP_3 = 4.5;

//colors
const Color COLOR_AFTER_HIT = { 200, 15, 15 };
const Color COLOR_WHILE_MOUSE_ON_TEXT = { 125, 125, 135 };

//main menu
const Vector2f START_GAME_TEXT_SHIFT = { 10, 100 };
const Vector2f EXIT_GAME_TEXT_SHIFT = { -10, -100 };

//player
const float PLAYER_POSITION_X = 250;
const float PLAYER_POSITION_Y = 200;
const Vector2i PLAYER_SIZE = { 36, 26 };
const float MAX_PLAYER_HEALTH = 8;// == start health
const float TIME_BETWEEN_SHOOTS_PLAYER = 0.5f;//0.5
const float TIME_FOR_SHOOT_ANIMATION = 0.2f;//0.2
const float TIME_FOR_PLAYER_HIT_CD = 1;
const Vector2f SHIFT_FOR_HEAD = { 14, 43 };

//enemy
const float FLY1_POSITION_X = 200;
const float FLY1_POSITION_Y = 200;
const float FLY2_POSITION_X = 250;
const float FLY2_POSITION_Y = 300;
const float FLY_UPDATE_FRAME_TIME = 0.005f;
const float ENEMY_STAND_AND_SHOOT_FRAME_TIME = 0.3f;
const int TIME_BETWEEN_SHOOT_ENEMY_STAND = 1;
const Vector2i FLY_SIZE = { 17, 14 };
const Vector2i STAND_AND_SHOOT_SIZE = { 38, 43 };
const Vector2i ZOMBIE_SIZE = { 32, 32 };
const Vector2i WORM_SIZE = { 64, 64 };
const float  ENEMY_DESTROY_EFFECT = 0.07f;
const float CHANGE_COLOR_EFFECT = 0.3f;
const float ENEMY_FOLLOW_SPEED_NORMAL = 0.05f;
const float ENEMY_FOLLOW_SPEED_FAST = 0.08f;
const float WORM_FOLLOW_SPEED = 0.15f;
const float SPIKE_DAMAGE = 0.5f;

//boss
const float BOSS_JUMP_SPEED = 5;
const float BOSS_FALL_DAMAGE = 2;
const float BOSS_BULLET_SPEED = 0.3f;
const float BOSS_HEALTH = 40;

//map
const int HEIGHT_SMALL_MAP = 10;
const int HEIGHT_MAP = 20;
const int HEIGHT_BIG_MAP = 30;
const int WIDTH_MAP = 45;

//window
const int WINDOW_WIDTH = 960;
const int WINDOW_HEIGHT = 640;

//tile
const int TILE_SIDE = 64;

//bullets
const int BULLET_SIDE = 32;
const float PLAYERS_BULLET_SPEED = 0.2f;//0.2
const float ENEMY_BULLET_SPEED = 0.24f;//0.24
const float BULLET_MAX_DISTANCE = 300.f;//300
const float BULLET_ANIMATION_STEP_TIME = 0.05f;//0.05
const float BULLET_SHIFT_IF_SHOOT_UP = 20.f;

//bonuses
const float SPEED_BONUS = 0.01f;
const float DAMAGE_BONUS = 0.5f;
const float HEAL_BONUS = 1.f;
const int BOMB_BONUS = 1;
const float RANGE_BONUS = 25.f;
const float FIRE_RATE_UP_BONUS = 0.05f;

//bomb
const float TIME_BEFORE_EXPLOSION = 2.f;
const float TIME_FOR_EXPLOSION = 1.f;
const float BOMB_DAMAGE = 1.f;//1
const int EXPLOSION_FRAMES_COUNT = 12;
const Vector2f EXPLOSION_ANIMATION_SHIFT = { 64, 128 };
const Vector2f BOMB_DAMAGE_ZONE_SHIFT = { 23.f, 20.f };
const int EXPLOSION_TEXTURE_IMAGE_SIZE = 64;
const int EXPLOSION_FRAME_COUNT = 4;
const float FRAME_CHANGE_TIME_EXPLOSION = 0.02f;

//interface
const int FONT_INTERFACE_SIZE = 20;
const float BOMB_IMAGE_SCALE = 1.5;
const Vector2f BOMB_IMAGE_SHIFT = { 28, 32 };
const Vector2f TEXT_SHIFT = { 80, 45 };
const Vector2f HP_SHIFT = { 35, 10 };
const Vector2f BONUS_TEXT_SHIFT = { 10, 30 };
const int HEALTH_TEXTURE_SIZE = 16;
const float HP_SCALE = 2;
const float FRAME_CHANGE_TIME = 0.5f;
const float TIME_FOR_SHOW_BONUS_TYPE_TEXT = 3.f;
const Vector2f BAR_SIZE = { 400, 64 };