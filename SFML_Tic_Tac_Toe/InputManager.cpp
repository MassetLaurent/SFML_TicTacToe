#include "InputManager.h"

bool InputManager::isSpriteClicked(sf::Sprite _sprite, sf::Mouse::Button _mouseButton, sf::RenderWindow & _window)
{
	if (sf::Mouse::isButtonPressed(_mouseButton))
	{
		sf::IntRect tempRect(
			_sprite.getPosition().x,
			_sprite.getPosition().y,
			_sprite.getGlobalBounds().width,
			_sprite.getGlobalBounds().height
		);

		if (tempRect.contains(sf::Mouse::getPosition(_window)))
			return true;
	}

	return false;
}

sf::Vector2i InputManager::getMousePosition(sf::RenderWindow & _window)
{
	return sf::Mouse::getPosition(_window);
}
