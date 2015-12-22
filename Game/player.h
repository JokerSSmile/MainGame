#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#include "map.h"
#include "character.h"
#include "bullet.h"
#include "bomb.h"

struct Player :
	public Character
{
	float CurrentFrame = 0;
	Vector2f playerOldPosition = { x, y };

	enum
	{
		leftUp, leftDown, rightUp, rightDown, left, up, down, right, stay
	} dir;

	float damage = 1;
	float speed = 0.1f;
	int bombCount = 1;
	float lastBombPlant = 0;

	Sprite headSprite;

	Player() {};
	Player(Texture & image, float X, float Y, int W, int H, String Name, float Health, Texture& headTexture) :Character(image, X, Y, w, h, Name, health)
	{
		dir = stay;
		w = W;
		h = H;
		x = X;
		y = Y;
		health = 6;

		sprite.setTextureRect(IntRect(0, 0, w, h));
		headSprite.setTexture(headTexture);
		headSprite.setScale(2, 2);
	}


	void setFrame(float& time);

	bool DiagonalMoving(float& time);
	void StrightMoving(float& time);
	void MakeShoot(vector<Bullet>& bullets, float gameTime, float &lastShot);
	void PlantBomb(vector<Boomb>& bombs, float& time);
	void Control(vector<Boomb>& bombs, vector<Bullet>& bullets, float& time, float& gameTime, float &lastShot);

	void SetShootAnimation(int& dir);

	void Shoot(vector<Bullet>& bullets, float gameTime, float &lastShootPlayer, int dir);

	void SetLastNotCollidedPosition();

	void CheckCollision(vector<Map> myMap, bool &canMove, Sprite& wallSprite, View& view, bool areDoorsOpened);

	void setSpeed();

	void Update(vector<Boomb>& bombs, vector<Map> myMap, vector<Bullet>& bullets, float time, float gameTime, float &lastShootPlayer, Sprite & wallSprite, View & view, bool areDoorsOpened);
};