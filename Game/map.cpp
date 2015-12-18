#include "map.h"
#include "constants.h"

void tileMap::LoadMapSprites()
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