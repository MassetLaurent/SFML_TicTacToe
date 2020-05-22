#ifndef DEF_GAMEOVERSTATE
#define DEF_GAMEOVERSTATE

#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"

class GameOverState : public State
{
private:
	GameDataRef data;
	sf::Sprite retryButtonSprite;
	sf::Sprite homeButtonSprite;

public:
	GameOverState(GameDataRef _data);
	~GameOverState();

	void init();
	void handleInput();

	void update(float dt);
	void render(float dt);
};

#endif // !DEF_GAMEOVERSTATE
