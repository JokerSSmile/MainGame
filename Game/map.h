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

static String levelOneMap[45] =
{
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"b0           0000           0000           0b",
	"b0   n   n   0000           0000           0b",
	"b0           r00l           r000           0b",
	"b0           0000           0000           0b",
	"b0   n   n   0000           0000           0b",
	"b0           0000           0000           0b",
	"b000000d00000000000000d00000000000000d000000b",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"b000000u00000000000000u00000000000000u000000b",
	"b0           0000           0000           0b",
	"b0           0000           0000           0b",
	"b0           r00l           r00l           0b",
	"b0           0000           0000           0b",
	"b0           0000           0000           0b",
	"b0           0000           0000           0b",
	"b0000000000000000000000000000000000000000000b",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
};

static String levelTwoMap[45] =
{
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"000000000000000000000000000000000000000000000",
	"00s          0000 s         0000  s        00",
	"00           0000           0000           00",
	"00           r00l           r000           00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"0000000d00000000000000d00000000000000d0000000",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"0000000u00000000000000u00000000000000u0000000",
	"00           0000   n   n   0000           00",
	"00           0000    n n    0000  s        00",
	"00           0000  n     n  0000           00",
	"00           0000    nnn    0000           00",
	"00           0000  n     n  0000           00",
	"00           0000           0000           00",
	"0000000000000000000000d00000000000000d0000000",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"000000000000000000000000000000000000000000000",
	"0000000000000000000000u00000000000000u0000000",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"00           r00l           r00l           00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"000000000000000000000000000000000000000000000",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
};

static String levelThreeMap[45] =
{
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"000000000000000000000000000000000000000000000",
	"00s          0000 s         0000  s        00",
	"00           0000           0000           00",
	"00           r00l           r000           00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"0000000d00000000000000d00000000000000d0000000",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"0000000u00000000000000u00000000000000u0000000",
	"00           0000           0000           00",
	"00s          0000           0000  s        00",
	"00           0000           r00l           00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"0000000d00000000000000d00000000000000d0000000",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb",
	"000000000000000000000000000000000000000000000",
	"0000000u00000000000000u00000000000000u0000000",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"00s          0000 s         r00l  s        00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"00           0000           0000           00",
	"000000000000000000000000000000000000000000000",
	"bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb"
};

static String levelBossMap[45] =
{
	"bbbbbbbbbbbbbbb",
	"000000000000000",
	"00           00",
	"00           00",
	"00           00",
	"00           00",
	"00           00",
	"00           00",
	"000000000000000",
	"bbbbbbbbbbbbbbb",
	"bbbbbbbbbbbbbbb",
	"0000000u0000000",
	"00           00",
	"00           00",
	"00           00",
 	"00           00",
 	"00           00",
 	"00           00",
 	"000000000000000",
 	"bbbbbbbbbbbbbbb"
};

static String mapString[30];

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

	void InitLevel(Level& level, Vector2i& mapSize);

	void InitMap(vector<Map>& myMap, Level& level);

	void DrawTiles(vector<Map>& myMap, RenderWindow & window, bool isRoomClear);
};
