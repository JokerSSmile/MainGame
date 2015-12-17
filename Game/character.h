#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;

struct Character
{
public:
	float dx, dy, x, y, speed, health;
	int w, h;
	bool life;
	Texture texture;
	Sprite sprite;
	String name;
	Character() {};
	Character(Texture & texture, float X, float Y, int W, int H, String Name, float Health)
	{
		x = X;
		y = Y;
		w = W;
		h = H;
		name = Name;
		speed = 0;
		health = Health;
		dx = 0;
		dy = 0;
		life = true;
		sprite.setTexture(texture);
	}
};