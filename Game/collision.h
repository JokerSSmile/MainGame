#pragma once
#include <SFML/Graphics.hpp>
#ifndef COLLISION_H
#define COLLISION_H

namespace Collision {
	//////
	/// Test for a collision between two sprites by comparing the alpha values of overlapping pixels
	/// Supports scaling and rotation
	/// AlphaLimit: The threshold at which a pixel becomes "solid". If AlphaLimit is 127, a pixel with
	/// alpha value 128 will cause a collision and a pixel with alpha value 126 will not.
	/// 
	/// This functions creates bitmasks of the textures of the two sprites by
	/// downloading the textures from the graphics card to memory -> SLOW!
	/// You can avoid this by using the "CreateTextureAndBitmask" function
	//////
	bool PixelPerfectTest(const sf::Sprite& Object1, const sf::Sprite& Object2, sf::Uint8 AlphaLimit = 0);

	//////
	/// Replaces Texture::loadFromFile
	/// Load an imagefile into the given texture and create a bitmask for it
	/// This is much faster than creating the bitmask for a texture on the first run of "PixelPerfectTest"
	/// 
	/// The function returns false if the file could not be opened for some reason
	//////
	bool CreateTextureAndBitmask(sf::Texture &LoadInto, const std::string& Filename);

	//////
	/// Test for collision using circle collision dection
	/// Radius is averaged from the dimensions of the sprite so
	/// roughly circular objects will be much more accurate
	//////
	bool CircleTest(const sf::Sprite& Object1, const sf::Sprite& Object2);

	//////
	/// Test for bounding box collision using the Seperating Axis Theorem
	/// Supports scaling and rotation
	//////
	bool BoundingBoxTest(const sf::Sprite& Object1, const sf::Sprite& Object2);
}

#endif  /* COLLISION_H */