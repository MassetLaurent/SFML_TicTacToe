#include <iostream>
#include <sstream>

#include "Definitions.h"
#include "SplashState.h"
#include "MainMenuState.h"

//constructor
SplashState::SplashState(GameDataRef _data) : data(_data)
{

}

SplashState::~SplashState()
{

}

//methodes
void SplashState::init()
{
	this->data->assetManager.loadTexture("Splash_Background", SPLASH_STATE_BACKGROUND_FILEPATH);

	this->backgroundSprite.setTexture(this->data->assetManager.getTexture("Splash_Background"));
}

void SplashState::handleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->data->window.close();

		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape ))
			this->data->window.close();
	}
}

void SplashState::update(float dt)
{
	if (clock.getElapsedTime().asSeconds() > SPLASH_SCREEN_DURATION)
		this->data->stateMachine.addState(StateRef(new MainMenuState(data)), true);
}

void SplashState::render(float dt)
{
	this->data->window.clear(sf::Color::Red);

	this->data->window.draw(backgroundSprite);

	this->data->window.display();
}
