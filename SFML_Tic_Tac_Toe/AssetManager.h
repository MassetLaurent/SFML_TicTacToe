#ifndef DEF_ASSET_MANAGER
#define DEF_ASSET_MANAGER

#include <map>
#include <SFML/Graphics.hpp>

class AssetManager
{
private:
	std::map<std::string, sf::Texture> texturesMap;
	std::map<std::string, sf::Font> fontsMap;

public:
	AssetManager() {}
	~AssetManager() {}

	void loadTexture(std::string _name, std::string _filePath);
	sf::Texture &getTexture(std::string _name);

	void loadFont(std::string _name, std::string _filePath);
	sf::Font &getFont(std::string _name);
};

#endif // !DEF_ASSET_MANAGER
