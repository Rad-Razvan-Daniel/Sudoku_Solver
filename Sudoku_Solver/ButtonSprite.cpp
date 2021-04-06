#include "ButtonSprite.h"
ButtonSprite::ButtonSprite(std::string PATH)
	: Sprite(PATH)
{
	activeTexture.loadFromFile("Resources\\Textures\\active_" + PATH);
	hoverTexture.loadFromFile("Resources\\Textures\\hover_" + PATH);

	activeSprite.setTexture(activeTexture);
	hoverSprite.setTexture(hoverTexture);
}