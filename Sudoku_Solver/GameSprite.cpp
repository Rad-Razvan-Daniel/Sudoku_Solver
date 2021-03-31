#include "GameSprite.h"


size_t GameSprite::pushSprite(const std::string& PATH)
{
	//std::unique_ptr<sf::Texture>texture = std::make_unique<sf::Texture>();
	auto texture = std::make_unique<sf::Texture>();
	texture->loadFromFile("Resources\\Textures\\" + PATH);
	sf::Sprite sprite;

	sprite.setTexture(*texture);

	sprites.push_back(sprite);
	textures.push_back(std::move(texture));

	return sprites.size();
}

void GameSprite::popSprite()
{
	textures.pop_back();  
}

GameSprite::GameSprite()
{

}
