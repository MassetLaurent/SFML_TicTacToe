#ifndef DEF_SPLASHSTATE
#define DEF_SPLASHSTATE

#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"

class SplashState : public State
{
private:
	GameDataRef data;
	sf::Clock clock;
	sf::Sprite backgroundSprite;

public:
	SplashState(GameDataRef _data);
	~SplashState();

	void init();
	void handleInput();

	void update(float dt);
	void render(float dt);
};

#endif // !DEF_SPLASHSTATE
