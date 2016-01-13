#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "collision.h"
#include "constants.h"


using namespace sf;
using namespace std;

struct Character
{
public:
	
	Direction dir;
	Vector2f moving; 
	Vector2f position;
	float speed;
	float health;
	Vector2i size;
	bool alive;
	Texture texture;
	Sprite sprite;
	String name;
	Character() {};
	Character(Texture & texture, Vector2f& pos, Vector2i& Size, String Name, float Health)
	{
		position.x = pos.x;
		position.y = pos.y;
		size.x = Size.x;
		size.y = Size.y;
		name = Name;
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
		case RIGHT: moving.x = speed; moving.y = 0; break;
		case LEFT: moving.x = -speed; moving.y = 0; break;
		case DOWN: moving.x = 0; moving.y = speed; break;
		case UP: moving.x = 0; moving.y = -speed; break;
		case LEFT_UP: moving.x = -speed*0.66f; moving.y = -speed*0.66f; break;
		case LEFT_DOWN: moving.x = -speed*0.66f; moving.y = speed*0.66f; break;
		case RIGHT_UP: moving.x = speed*0.66f; moving.y = -speed*0.66f; break;
		case RIGHT_DOWN: moving.x = speed*0.66f; moving.y = speed*0.66f; break;
		case STAND: moving.x = 0; moving.y = 0;
		}
		position.x += moving.x * time;
		position.y += moving.y * time;
	}
 };