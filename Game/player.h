#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

#include "map.h"
#include "character.h"
#include "bullet.h"

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


	void setFrame(float time);

	//player Control
	void Control(vector<Bullet>& bullets, float time, float gameTime, float &lastShot);

	void SetShootAnimation(int& dir);

	//player shoots
	void Shoot(vector<Bullet>& bullets, float gameTime, float &lastShootPlayer, int dir);

	void SetLastNotCollidedPosition();

	void CheckCollision(vector<Map> myMap, bool &canMove, Sprite& wallSprite, View& view, bool areDoorsOpened);

	void setSpeed();

	void Update(vector<Map> myMap, vector<Bullet>& bullets, float time, float gameTime, float &lastShootPlayer, Sprite & wallSprite, View & view, bool areDoorsOpened);
};