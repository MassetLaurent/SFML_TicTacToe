#ifndef DEF_GAME
#define DEF_GAME

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "AssetManager.h"
#include "InputManager.h"
#include "StateMachine.h"

struct GameData
{
	StateMachine stateMachine;
	sf::RenderWindow window;
	AssetManager assetManager;
	InputManager inputManager;
};

typedef std::shared_ptr<GameData> GameDataRef;

class Game
{
private:
	GameDataRef data = std::make_shared<GameData>();
	sf::Clock clock;
	const float dt = 1.0f / 60.0f;
	
	void run();

public:
	Game(int _width, int _height, std::string _title);
	~Game();
};

#endif // !DEF_GAME