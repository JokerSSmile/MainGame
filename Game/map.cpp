#include "map.h"
#include "constants.h"

const String ROCK_TEXTURE_PATH = "resources/images/Rock.png";
const String ROCK_BUL_TEXTURE_PATH = "resources/images/Rock_bullet.png";
const String SPIKE_TEXTURE_PATH = "resources/images/spike.png";
const String DOOR_CLOSED_TEXTURE_PATH = "resources/images/Door.png";
const String DOOR_OPENED_TEXTURE_PATH = "resources/images/openedDoor.png";

void tileMap::LoadMapSprites()
{
	//rock
	rockTexture.loadFromFile(ROCK_TEXTURE_PATH);
	rockSprite.setTexture(rockTexture);
	rockSprite.setScale(2, 2);

	rockBulTexture.loadFromFile(ROCK_BUL_TEXTURE_PATH);
	rockBulSprite.setTexture(rockBulTexture);
	rockBulSprite.setScale(2, 2);

	//spike
	spikeTexture.loadFromFile(SPIKE_TEXTURE_PATH);
	spikeSprite.setTexture(spikeTexture);

	//closed door
	closedDoorTexture.loadFromFile(DOOR_CLOSED_TEXTURE_PATH);
	closedDoorSprite.setTexture(closedDoorTexture);
	closedDoorSprite.setScale(2, 2);

	//opened door
	openedDoorTexture.loadFromFile(DOOR_OPENED_TEXTURE_PATH);
	openedDoorSprite.setTexture(openedDoorTexture);
	openedDoorSprite.setScale(2, 2);
}

void tileMap::setDoorType(Map& myMap, bool isRoomClear)
{
	if (isRoomClear == false)
	{
		myMap.sprite = closedDoorSprite;
		isOpened = false;
	}
	else
	{
		myMap.sprite = openedDoorSprite;
		isOpened = true;
	}
}

void tileMap::initMap(vector<Map>& myMap, Level& level)
{
	int heightMap = HEIGHT_MAP;
	if (level == 0)
	{
		for (unsigned i = 0; i < 45; i++)
		{
			heightMap = HEIGHT_MAP;
			mapString[i] = levelOneMap[i];
		}
	}
	else if (level == 1)
	{
		for (unsigned i = 0; i < 45; i++)
		{
			heightMap = HEIGHT_BIG_MAP;
			mapString[i] = levelTwoMap[i];
		}
	}
	if (isMapSpritesLoaded == false)
	{
		LoadMapSprites();
		isMapSpritesLoaded = true;
	}
	Map map;
	map.alive = true;
	for (int i = 0; i < heightMap; i++)
	{
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (mapString[i][j] == 's')
			{
				map.position.y = i * TILE_SIDE;
				map.position.x = j * TILE_SIDE;
				map.sprite = rockSprite;
				map.collisionSprite = rockBulSprite;
				map.pos = ROCK;
				myMap.push_back(map);
			}
			else if (mapString[i][j] == 'n')
			{
				map.position.y = i * TILE_SIDE;
				map.position.x = j * TILE_SIDE;
				map.sprite = spikeSprite;
				map.pos = SPIKE;
				myMap.push_back(map);
			}
			else if (mapString[i][j] == '0')
			{
				map.position.y = i * TILE_SIDE;
				map.position.x = j * TILE_SIDE;
				map.sprite = rockSprite;
				map.pos = WALL;
				myMap.push_back(map);
			}
			else if (mapString[i][j] == 'u')
			{
				map.position.y = i * TILE_SIDE - TILE_SIDE;
				map.position.x = j * TILE_SIDE - TILE_SIDE / 2;
				map.pos = UP;
				myMap.push_back(map);
			}
			else if (mapString[i][j] == 'd')
			{
				map.position.y = i * TILE_SIDE;
				map.position.x = j * TILE_SIDE - TILE_SIDE / 2;
				map.pos = DOWN;
				myMap.push_back(map);
			}
			else if (mapString[i][j] == 'r')
			{
				map.position.y = i * TILE_SIDE;
				map.position.x = j * TILE_SIDE;
				map.pos = RIGHT;
				myMap.push_back(map);
			}
			else if (mapString[i][j] == 'l')
			{
				map.position.y = i * TILE_SIDE;
				map.position.x = j * TILE_SIDE - TILE_SIDE;
				map.pos = LEFT;
				myMap.push_back(map);
			}
		}
	}
}

void tileMap::drawTiles(vector<Map>& myMap, RenderWindow& window, bool isRoomClear)
{
	for (auto& map: myMap)
	{
		if (map.pos == ROCK)
		{
			map.sprite.setPosition(float(map.position.x), float(map.position.y));
			map.collisionSprite.setPosition(float(map.position.x), float(map.position.y));
		}
		else if (map.pos == SPIKE)
		{
			map.sprite.setPosition(float(map.position.x), float(map.position.y));
		}
		else if (map.pos == WALL)
		{
			map.sprite.setPosition(float(map.position.x), float(map.position.y));
		}
		else
		{
			if (map.pos == UP)
			{
				setDoorType(map, isRoomClear);
				map.sprite.setPosition(float(map.position.x), float(map.position.y + 5));
				map.sprite.setTextureRect(IntRect(0, 0, 64, 64));
			}
			else if (map.pos == DOWN)
			{
				setDoorType(map, isRoomClear);
				map.sprite.setPosition(float(map.position.x), float(map.position.y - 5));
				map.sprite.setTextureRect(IntRect(64, 0, 64, 64));
			}
			else if (map.pos == LEFT)
			{
				setDoorType(map, isRoomClear);
				map.sprite.setPosition(float(map.position.x - 5), float(map.position.y));
				map.sprite.setTextureRect(IntRect(192, 0, 64, 64));
			}
			else if (map.pos == RIGHT)
			{
				setDoorType(map, isRoomClear);
				map.sprite.setPosition(float(map.position.x + 5), float(map.position.y));
				map.sprite.setTextureRect(IntRect(128, 0, 64, 64));
			}
		}
		if (map.pos != WALL)
		{
			window.draw(map.sprite);
		}
	}
}