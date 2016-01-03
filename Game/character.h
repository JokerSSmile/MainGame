#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;

struct Character
{
public:
	Vector2f moving;
	//float dx;
	//float dy; 
	Vector2f position;
	//float x;
	//float y; 
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
		//x = X;
		//y = Y;
		position.x = pos.x;
		position.y = pos.y;
		w = W;
		h = H;
		name = Name;
		speed = 0;
		health = Health;
		moving.x = 0;
		moving.y = 0;
		//dx = 0;
		//dy = 0;
		alive = true;
		sprite.setTexture(texture);
	}
};