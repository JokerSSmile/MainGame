#pragma once
#include <SFML\Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;


sf::String mapString[WIDTH_MAP] = {
	"000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000",
	"00           0000           0000           00",
	"00     sss   0000           0000 ss     ss 00",
	"00           r00l           r00l           00",
	"00           0000           0000 s       s 00",
	"00           0000           0000 s       s 00",
	"00           0000           0000           00",
	"0000000d00000000000000d00000000000000d0000000",
	"000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000",
	"0000000u00000000000000u00000000000000u0000000",
	"00           0000           0000           00",
	"00   s       0000  s     s  0000           00",
	"00           r00l           r00l           00",
	"00           0000           0000     sss   00",
	"00           0000  s     s  0000           00",
	"00           0000           0000           00",
	"000000000000000000000000000000000000000000000",
	"000000000000000000000000000000000000000000000",
};




enum DoorPosition
{
	NOTDOOR, UP, DOWN, LEFT, RIGHT
};

struct Map
{
	int x;
	int y;
	Sprite sprite;
	DoorPosition pos;
	String TileMap;
};

vector<Map> myMap;

struct tileMap
{
private:
	bool isMapSpritesLoaded = false;
public:
	Image rockImage;
	Texture rockTexture;
	Sprite rockSprite;
	Image closedDoorImage;
	Texture closedDoorTexture;
	Sprite closedDoorSprite;
	Image openedDoorImage;
	Texture openedDoorTexture;
	Sprite openedDoorSprite;

	void LoadMapSprites()
	{
		//rock
		rockImage.loadFromFile("images/Rock1.png");
		rockTexture.loadFromImage(rockImage);
		rockSprite.setTexture(rockTexture);

		//closed door
		closedDoorImage.loadFromFile("images/Door.png");
		closedDoorTexture.loadFromImage(closedDoorImage);
		closedDoorSprite.setTexture(closedDoorTexture);
		closedDoorSprite.setScale(2, 2);

		//opened door
		openedDoorImage.loadFromFile("images/openedDoor.png");
		openedDoorTexture.loadFromImage(openedDoorImage);
		openedDoorSprite.setTexture(openedDoorTexture);
		openedDoorSprite.setScale(2, 2);
	}

	void setDoorType(bool isLevelClear, Map& map)
	{
		if (isLevelClear == false)
		{
			map.sprite = closedDoorSprite;
		}
		else
		{
			map.sprite = openedDoorSprite;
		}
	}

	void drawMap(RenderWindow & window, bool isLevelClear)
	{
		if (isMapSpritesLoaded == false)
		{
			LoadMapSprites();
			isMapSpritesLoaded = true;
		}

		int counter = 0;

		myMap.clear();

		Map map;

		for (int i = 0; i < HEIGHT_MAP; i++)
		{
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				if (mapString[i][j] == 's')
				{
					map.y = i * TILE_SIDE;
					map.x = j * TILE_SIDE;
					map.sprite = rockSprite;
					map.pos = NOTDOOR;
					myMap.push_back(map);
					counter++;
				}
				
				else if (mapString[i][j] == 'u')
				{
					setDoorType(isLevelClear, map);
					map.y = i * TILE_SIDE - TILE_SIDE;
					map.x = j * TILE_SIDE - TILE_SIDE / 2;
					map.pos = UP;
					myMap.push_back(map);
					counter++;
				}
				else if (mapString[i][j] == 'd')
				{
					setDoorType(isLevelClear, map);
					map.y = i * TILE_SIDE;
					map.x = j * TILE_SIDE - TILE_SIDE / 2;
					map.pos = DOWN;
					myMap.push_back(map);
					counter++;
				}
				else if (mapString[i][j] == 'r')
				{
					setDoorType(isLevelClear, map);
					map.y = i * TILE_SIDE;
					map.x = j * TILE_SIDE;
					map.pos = RIGHT;
					myMap.push_back(map);
					counter++;
				}
				else if (mapString[i][j] == 'l')
				{
					setDoorType(isLevelClear, map);
					map.y = i * TILE_SIDE;
					map.x = j * TILE_SIDE - TILE_SIDE;
					map.pos = LEFT;
					myMap.push_back(map);
					counter++;
				}			
			}
		}
		drawTiles(window);
	}

	void drawTiles(RenderWindow & window)
	{
		for (vector<Map>::iterator it = myMap.begin(); it != myMap.end(); ++it)
		{
			if (it->pos == 0)
			{
				it->sprite.setPosition(it->x, it->y);
			}
			else
			{
				if (it->pos == UP)
				{
					it->sprite.setTextureRect(IntRect(0, 0, 64, 64));
					it->sprite.setPosition(it->x, it->y);
				}
				else if (it->pos == DOWN)
				{
					it->sprite.setTextureRect(IntRect(64, 0, 64, 64));
					it->sprite.setPosition(it->x, it->y);
				}
				else if (it->pos == LEFT)
				{
					it->sprite.setTextureRect(IntRect(192, 0, 64, 64));
					it->sprite.setPosition(it->x, it->y);
				}
				else if (it->pos == RIGHT)
				{
					it->sprite.setTextureRect(IntRect(128, 0, 64, 64));
					it->sprite.setPosition(it->x, it->y);
				}
			}
			window.draw(it->sprite);
		}
	}
};
