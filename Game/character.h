#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "collision.h"


using namespace sf;
using namespace std;

struct Character
{
public:
	enum
	{
		leftUp, leftDown, rightUp, rightDown, left, up, down, right, stay
	} dir;

	Vector2f moving; 
	Vector2f position;
	float speed;
	float health;
	int w;
	int h;
	bool alive;
	Texture texture;
	Sprite sprite;
	String name;
	Character() {};
	Character(Texture & texture, Vector2f& pos, int W, int H, String Name, float Health)
	{
		position.x = pos.x;
		position.y = pos.y;
		w = W;
		h = H;
		name = Name;
		speed;
		health = Health;
		moving.x = 0;
		moving.y = 0;
		alive = true;
		sprite.setTexture(texture);
	}

	void Character::SetPosition(float& time, float& speed)
	{
		switch (dir)
		{
		case right: moving.x = speed; moving.y = 0; break;
		case left: moving.x = -speed; moving.y = 0; break;
		case down: moving.x = 0; moving.y = speed; break;
		case up: moving.x = 0; moving.y = -speed; break;
		case leftUp: moving.x = -speed*0.66f; moving.y = -speed*0.66f; break;
		case leftDown: moving.x = -speed*0.66f; moving.y = speed*0.66f; break;
		case rightUp: moving.x = speed*0.66f; moving.y = -speed*0.66f; break;
		case rightDown: moving.x = speed*0.66f; moving.y = speed*0.66f; break;
		case stay: moving.x = 0; moving.y = 0;
		}
		position.x += moving.x * time;
		position.y += moving.y * time;
	}
 };