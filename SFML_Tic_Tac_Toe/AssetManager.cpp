#include "AssetManager.h"

void AssetManager::loadTexture(std::string _name, std::string _filePath)
{
	sf::Texture texture;
	
	if (texture.loadFromFile(_filePath))
		this->texturesMap[_name] = texture;
}

sf::Texture & AssetManager::getTexture(std::string _name)
{
	return texturesMap.at(_name);
}

void AssetManager::loadFont(std::string _name, std::string _filePath)
{
	sf::Font font;

	if (font.loadFromFile(_filePath))
		this->fontsMap[_name] = font;
}

sf::Font & AssetManager::getFont(std::string _name)
{
	return fontsMap.at(_name);
}
