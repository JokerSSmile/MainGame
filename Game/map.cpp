#include "map.h"
#include "constants.h"

const String ROCK_TEXTURE_PATH = "resources/images/Rock.png";
const String DOOR_CLOSED_TEXTURE_PATH = "resources/images/Door.png";
const String DOOR_OPENED_TEXTURE_PATH = "resources/images/openedDoor.png";

void tileMap::LoadMapSprites()
{
	//rock
	rockTexture.loadFromFile(ROCK_TEXTURE_PATH);
	rockSprite.setTexture(rockTexture);
	rockSprite.setScale(2, 2);

	//closed door
	closedDoorTexture.loadFromFile(DOOR_CLOSED_TEXTURE_PATH);
	closedDoorSprite.setTexture(closedDoorTexture);
	closedDoorSprite.setScale(2, 2);

	//opened door
	openedDoorTexture.loadFromFile(DOOR_OPENED_TEXTURE_PATH);
	openedDoorSprite.setTexture(openedDoorTexture);
	openedDoorSprite.setScale(2, 2);
}

void tileMap::setDoorType(Map& myMap, bool isLevelClear)
{
	if (isLevelClear == false)
	{
		myMap.sprite = closedDoorSprite;
	}
	else
	{
		myMap.sprite = openedDoorSprite;
	}
}

void tileMap::drawMap(vector<Map>& myMap, RenderWindow& window, bool isLevelClear)
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
				setDoorType(map, isLevelClear);
				map.y = i * TILE_SIDE - TILE_SIDE;
				map.x = j * TILE_SIDE - TILE_SIDE / 2;
				map.pos = UP;
				myMap.push_back(map);
				counter++;
			}
			else if (mapString[i][j] == 'd')
			{
				setDoorType(map, isLevelClear);
				map.y = i * TILE_SIDE;
				map.x = j * TILE_SIDE - TILE_SIDE / 2;
				map.pos = DOWN;
				myMap.push_back(map);
				counter++;
			}
			else if (mapString[i][j] == 'r')
			{
				setDoorType(map, isLevelClear);
				map.y = i * TILE_SIDE;
				map.x = j * TILE_SIDE;
				map.pos = RIGHT;
				myMap.push_back(map);
				counter++;
			}
			else if (mapString[i][j] == 'l')
			{
				setDoorType(map, isLevelClear);
				map.y = i * TILE_SIDE;
				map.x = j * TILE_SIDE - TILE_SIDE;
				map.pos = LEFT;
				myMap.push_back(map);
				counter++;
			}
		}
	}
	drawTiles(myMap, window);
}

void tileMap::drawTiles(vector<Map>& myMap, RenderWindow& window)
{
	for (auto& map: myMap)
	{
		if (map.pos == 0)
		{
			map.sprite.setPosition(map.x, map.y);
		}
		else
		{
			if (map.pos == UP)
			{
				map.sprite.setTextureRect(IntRect(0, 0, 64, 64));
				map.sprite.setPosition(map.x, map.y);
			}
			else if (map.pos == DOWN)
			{
				map.sprite.setTextureRect(IntRect(64, 0, 64, 64));
				map.sprite.setPosition(map.x, map.y);
			}
			else if (map.pos == LEFT)
			{
				map.sprite.setTextureRect(IntRect(192, 0, 64, 64));
				map.sprite.setPosition(map.x, map.y);
			}
			else if (map.pos == RIGHT)
			{
				map.sprite.setTextureRect(IntRect(128, 0, 64, 64));
				map.sprite.setPosition(map.x, map.y);
			}
		}
		window.draw(map.sprite);
	}
}