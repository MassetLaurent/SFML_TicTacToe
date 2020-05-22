#include <iostream>
#include <sstream>

#include "Definitions.h"
#include "PlayState.h"
#include "MainMenuState.h"
#include "PauseState.h"

PauseState::PauseState(GameDataRef _data): data(_data)
{
}

PauseState::~PauseState()
{
}

void PauseState::init()
{
	//Texture loading
	data->assetManager.loadTexture("Pause Background", PAUSE_BACKGROUND_FILEPATH);
	data->assetManager.loadTexture("Home Button", HOME_BUTTON_FILEPATH);
	data->assetManager.loadTexture("Resume Button", RESUME_BUTTON_FILEPATH);

	//assign textures to sprites
	background.setTexture(data->assetManager.getTexture("Pause Background"));
	homeButton.setTexture(data->assetManager.getTexture("Home Button"));
	resumeButton.setTexture(data->assetManager.getTexture("Resume Button"));

	//sprites positions
	resumeButton.setPosition(
		(data->window.getSize().x / 2) - resumeButton.getGlobalBounds().width / 2,
		(data->window.getSize().y / 3) - resumeButton.getGlobalBounds().height / 2
	);

	homeButton.setPosition(
		(data->window.getSize().x / 2) - homeButton.getGlobalBounds().width / 2,
		((data->window.getSize().y / 3) * 2) - homeButton.getGlobalBounds().height / 2
	);
}

void PauseState::handleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->data->window.close();

		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			this->data->window.close();

		if (data->inputManager.isSpriteClicked(resumeButton, sf::Mouse::Left, data->window))
			data->stateMachine.removeState();

		if (data->inputManager.isSpriteClicked(homeButton, sf::Mouse::Left, data->window))
		{
			data->stateMachine.removeState();
			data->stateMachine.addState(StateRef(new MainMenuState(data)), true);
		}
	}
}

void PauseState::update(float dt)
{
}

void PauseState::render(float dt)
{
	data->window.clear();

	data->window.draw(background);
	data->window.draw(resumeButton);
	data->window.draw(homeButton);

	data->window.display();
}
