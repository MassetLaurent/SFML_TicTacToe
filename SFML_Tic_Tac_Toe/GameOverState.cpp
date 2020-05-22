#include <iostream>
#include <sstream>

#include "Definitions.h"
#include "MainMenuState.h"
#include "GameOverState.h"
#include "PlayState.h"

GameOverState::GameOverState(GameDataRef _data) : data(_data)
{

}

GameOverState::~GameOverState()
{
}

void GameOverState::init()
{
	data->assetManager.loadTexture("Retry Button", RETRY_BUTTON_FILEPATH);
	data->assetManager.loadTexture("Home Button", HOME_BUTTON_FILEPATH);

	retryButtonSprite.setTexture(data->assetManager.getTexture("Retry Button"));
	homeButtonSprite.setTexture(data->assetManager.getTexture("Home Button"));

	//sprites positions
	retryButtonSprite.setPosition(
		(data->window.getSize().x / 2) - retryButtonSprite.getGlobalBounds().width / 2,
		(data->window.getSize().y / 3) - retryButtonSprite.getGlobalBounds().height / 2
	);

	homeButtonSprite.setPosition(
		(data->window.getSize().x / 2) - homeButtonSprite.getGlobalBounds().width / 2,
		((data->window.getSize().y / 3) * 2) - homeButtonSprite.getGlobalBounds().height / 2
	);
}

void GameOverState::handleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->data->window.close();

		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			this->data->window.close();

		if (data->inputManager.isSpriteClicked(retryButtonSprite, sf::Mouse::Left, data->window))
			data->stateMachine.addState(StateRef(new PlayState(data)), true);

		if (data->inputManager.isSpriteClicked(homeButtonSprite, sf::Mouse::Left, data->window))
		{
			data->stateMachine.addState(StateRef(new MainMenuState(data)), true);
		}
	}
}

void GameOverState::update(float dt)
{
}

void GameOverState::render(float dt)
{
	this->data->window.clear(sf::Color(150,50,50));

	this->data->window.draw(retryButtonSprite);
	this->data->window.draw(homeButtonSprite);

	this->data->window.display();
}
