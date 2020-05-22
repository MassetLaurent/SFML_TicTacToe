#ifndef DEF_MAINMENUSTATE
#define DEF_MAINMENUSTATE

#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"

class MainMenuState : public State
{
private:
	GameDataRef data;
	sf::Clock clock;
	sf::Sprite backgroundSprite;
	sf::Sprite playButtonSprite;
	sf::Sprite playButtonOuterSprite;
	sf::Sprite titleSprite;

public:
	MainMenuState(GameDataRef _data);
	~MainMenuState();

	void init();
	void handleInput();

	void update(float dt);
	void render(float dt);
};

#endif // !DEF_MAINMENUSTATE
