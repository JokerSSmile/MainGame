#pragma once

#include <SFML\Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

enum DoorPosition
{
	NOTDOOR, UP, DOWN, LEFT, RIGHT
};

struct Map
{
	bool alive = true;
	Vector2f position;
	Sprite sprite;
	Sprite collisionSprite;
	DoorPosition pos;
	String TileMap;
};

static String mapString[45] = {
	"000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000",
	"00           0000           0000           00",
	"00  ssssss   0000           0000 ss     ss 00",
	"00  s    s   r00l           r00l           00",
	"00       s   0000           0000           00",
	"00  ssssss   0000           0000 s       s 00",
	"00           0000           0000           00",
	"0000000d00000000000000d00000000000000d0000000",
	"000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000",
	"0000000u00000000000000u00000000000000u0000000",
	"00           0000           0000 s         00",
	"00   s       0000  s     s  0000           00",
	"00           r00l           r00l s         00",
	"00           0000           0000       s   00",
	"00           0000  s     s  0000           00",
	"00           0000           0000           00",
	"000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000",
};

struct tileMap
{
	bool isMapSpritesLoaded = false;
	bool isOpened = false;

	Image rockImage;
	Texture rockTexture;
	Sprite rockSprite;
	Texture rockBulTexture;
	Sprite rockBulSprite;
	Image closedDoorImage;
	Texture closedDoorTexture;
	Sprite closedDoorSprite;
	Image openedDoorImage;
	Texture openedDoorTexture;
	Sprite openedDoorSprite;

	void LoadMapSprites();

	void setDoorType(Map& myMap, bool isRoomClear);

	void drawMap(vector<Map>& myMap, RenderWindow & window, bool isRoomClear);

	void drawTiles(vector<Map>& myMap, RenderWindow & window);
};
