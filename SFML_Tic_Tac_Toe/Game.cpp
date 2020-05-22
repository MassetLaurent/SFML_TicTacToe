#include "Game.h"
#include "SplashState.h"

//constructor
Game::Game(int _width, int _height, std::string _title)
{
	this->data->window.create(sf::VideoMode(_width, _height), _title, sf::Style::Close | sf::Style::Titlebar);

	//insert the first state of the game
	this->data->stateMachine.addState(StateRef(new SplashState(this->data)), true);

	this->run();
}

Game::~Game()
{
}

//methodes
void Game::run()
{
	float newTime, frameTime, interpolation;
	float currentTime = this->clock.getElapsedTime().asSeconds();
	float accumulator = 0.0f;

	while (data->window.isOpen())
	{
		this->data->stateMachine.processStateChanges();

		newTime = this->clock.getElapsedTime().asSeconds();
		frameTime = newTime - currentTime;

		if (frameTime > 0.25f)
			frameTime = 0.25f;

		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= dt)
		{
			this->data->stateMachine.getActiveState()->handleInput();
			this->data->stateMachine.getActiveState()->update(dt);

			accumulator -= dt;
		}

		interpolation = accumulator / dt;
		this->data->stateMachine.getActiveState()->render(interpolation);
	}
}
