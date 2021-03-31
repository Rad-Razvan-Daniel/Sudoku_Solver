#include "GameSprite.h"


int GameSprite::newSprite(std::string PATH)
{
	sf::Texture texture;
	sf::Sprite sprite;
	//set texture and sprite accordingly
	texture.loadFromFile(PATH);
	sprite.setTexture(texture);
	//add the sprite to the vector which keeps track of sprites loaded
	sprites.push_back(sprite);
	//return the position at which the new sprite was inserted
	return sprites.size();
}

GameSprite::GameSprite()
{

}
