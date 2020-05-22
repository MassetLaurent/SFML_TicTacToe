#ifndef DEF_INPUT_MANAGER
#define DEF_INPUT_MANAGER

#include <SFML/Graphics.hpp>

class InputManager
{
public:
	InputManager() {}
	~InputManager() {}

	bool isSpriteClicked(sf::Sprite _sprite, sf::Mouse::Button _mouseButton, sf::RenderWindow &_window);

	sf::Vector2i getMousePosition(sf::RenderWindow &_window);
};

#endif // !DEF_INPUT_MANAGER