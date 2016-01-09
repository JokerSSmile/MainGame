#pragma once

#include <SFML\Graphics.hpp>
#include <string>
#include <iostream>
#include "constants.h"

using namespace sf;
using namespace std;

struct Map
{
	bool alive;
	Vector2i position;
	Sprite sprite;
	Sprite collisionSprite;
	TileState pos;
	String TileMap;
};

static String levelOneMap[45] = {
	"000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000",
	"00           0000           0000           00",
	"00  ssssss   0000           0000 ss     ss 00",
	"00           r00l           0000    s s    00",
	"00           0000           0000    s s    00",
	"00  ssssss   0000           0000 s  sss  s 00",
	"00           0000           0000           00",
	"0000000d00000000000000d00000000000000d0000000",
	"000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000",
	"0000000u00000000000000u00000000000000u0000000",
	"00           0000           0000 s         00",
	"00           0000  s     s  0000           00",
	"00           0000           r00l           00",
	"00        nn 0000           0000       s   00",
	"00           0000        s  0000           00",
	"00           0000           0000           00",
	"000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000",
};

static String levelTwoMap[45] = {
	"000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000",
	"00s          0000 s         0000  s        00",
	"00           0000           0000           00",
	"00           r00l           0000           00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"0000000d00000000000000d00000000000000d0000000",
	"000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000",
	"0000000u00000000000000u00000000000000u0000000",
	"00           0000   n   n   0000           00",
	"00s          0000    n n    0000  s        00",
	"00           0000  n     n  r00l           00",
	"00           0000    nnn    0000           00",
	"00           0000  n     n  0000           00",
	"00           0000           0000           00",
	"0000000d00000000000000d00000000000000d0000000",
	"000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000",
	"0000000u00000000000000u00000000000000u0000000",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"00s          0000 s         r00l  s        00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000",
};

static String mapString[45];

struct tileMap
{
	bool isMapSpritesLoaded = false;
	bool isOpened = false;

	Texture rockTexture;
	Sprite rockSprite;
	Texture rockBulTexture;
	Sprite rockBulSprite;
	Texture closedDoorTexture;
	Sprite closedDoorSprite;
	Texture openedDoorTexture;
	Sprite openedDoorSprite;
	Texture spikeTexture;
	Sprite spikeSprite;

	void LoadMapSprites();

	void setDoorType(Map& myMap, bool isRoomClear);

	void initMap(vector<Map>& myMap, Level& level);

	void drawTiles(vector<Map>& myMap, RenderWindow & window, bool isRoomClear);
};
