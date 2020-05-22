#include <iostream>
#include <sstream>

#include "Definitions.h"
#include "MainMenuState.h"
#include "PlayState.h"

MainMenuState::MainMenuState(GameDataRef _data) : data(_data)
{

}

MainMenuState::~MainMenuState()
{
}

void MainMenuState::init()
{
	//Texture loading
	data->assetManager.loadTexture("Main Menu Background", MAIN_MENU_BACKGROUND_FILEPATH);
	data->assetManager.loadTexture("Play Button", PLAY_BUTTON_FILEPATH);
	data->assetManager.loadTexture("Play Button Outer", PLAY_BUTTON_OUTER_FILEPATH);
	data->assetManager.loadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);

	//Sprites init
	backgroundSprite.setTexture(this->data->assetManager.getTexture("Main Menu Background"));
	playButtonSprite.setTexture(this->data->assetManager.getTexture("Play Button"));
	playButtonOuterSprite.setTexture(this->data->assetManager.getTexture("Play Button Outer"));
	titleSprite.setTexture(this->data->assetManager.getTexture("Game Title"));

	//set sprites positions
	titleSprite.setPosition(
		(SCREEN_WIDTH / 2) - (titleSprite.getGlobalBounds().width / 2),
		50.f
	);

	playButtonSprite.setPosition(
		(SCREEN_WIDTH / 2) - (playButtonSprite.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 2) - (playButtonSprite.getGlobalBounds().height / 2)
	);

	playButtonOuterSprite.setPosition(
		(playButtonSprite.getPosition().x) - (playButtonSprite.getGlobalBounds().width / 2) - 10,
		(playButtonSprite.getPosition().y) + (playButtonSprite.getGlobalBounds().height / 2) - 5
	);
}

void MainMenuState::handleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->data->window.close();

		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			this->data->window.close();

		if (data->inputManager.isSpriteClicked(playButtonSprite, sf::Mouse::Left, data->window))
			data->stateMachine.addState(StateRef(new PlayState(data)), true);
	}
}

void MainMenuState::update(float dt)
{
}

void MainMenuState::render(float dt)
{
	this->data->window.clear();

	this->data->window.draw(backgroundSprite);
	this->data->window.draw(playButtonOuterSprite);
	this->data->window.draw(playButtonSprite);
	this->data->window.draw(titleSprite);

	this->data->window.display();
}
