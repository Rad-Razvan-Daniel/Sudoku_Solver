#include "GameSprite.h"


size_t GameSprite::newSprite(const std::string& PATH)
{
	//std::unique_ptr<sf::Texture>texture = std::make_unique<sf::Texture>();
	auto texture = std::make_unique<sf::Texture>();
	texture->loadFromFile(PATH);
	sf::Sprite sprite;

	sprite.setTexture(*texture);

	sprites.push_back(sprite);
	textures.push_back(std::move(texture));

	return sprites.size();
}

GameSprite::GameSprite()
{

}
