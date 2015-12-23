#pragma once

//player
const float PLAYER_POSITION_X = 250;
const float PLAYER_POSITION_Y = 200;
const int PLAYER_WIDTH = 36;
const int PLAYER_HEIGHT = 26;
const float MAX_PLAYER_HEALTH = 6;
const float TIME_BETWEEN_SHOOTS_PLAYER = 0.5f;
const float TIME_FOR_SHOOT_ANIMATION = 0.2f;

//enemy
const float FLY1_POSITION_X = 350;
const float FLY1_POSITION_Y = 200;
const float FLY2_POSITION_X = 250;
const float FLY2_POSITION_Y = 300;
const int FLY_WIDTH = 57;
const int FLY_HEIGHT = 45;
const float  ENEMY_DESTROY_EFFECT = 0.07f;

const int HEIGHT_MAP = 20;
const int WIDTH_MAP = 45;

//window
const int WINDOW_WIDTH = 960;
const int WINDOW_HEIGHT = 640;

//tile
const int TILE_SIDE = 64;

//bullets
const int BULLET_SIDE = 32;
const float PLAYERS_BULLET_SPEED = 0.10f;
const float ENEMY_BULLET_SPEED = 0.12f;
const float BULLET_LIFE_TIME = 1.f;
const float BULLET_ANIMATION_STEP_TIME = 0.05f;
const float BULLET_SHIFT_IF_SHOOT_UP = 20;

//bonuses
const float SPEED_BONUS = 0.01f;
const float DAMAGE_BONUS = 0.5f;
const float HEAL_BONUS = 1;
const int BOMB_BONUS = 1;
const float TIME_BEFORE_EXPLOSION = 2;
const float TIME_FOR_EXPLOSION = 1.f;
