#ifndef DEF_PAUSESTATE
#define DEF_PAUSESTATE

#include "State.h"

class PauseState : public State
{
private:
	GameDataRef data;

	sf::Sprite background;
	sf::Sprite homeButton;
	sf::Sprite resumeButton;
public:
	PauseState(GameDataRef _data);
	~PauseState();

	void init();
	void handleInput();

	void update(float dt);
	void render(float dt);
};
#endif // !DEF_PAUSESTATE