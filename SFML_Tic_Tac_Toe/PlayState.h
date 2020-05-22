#ifndef DEF_PLAYSTATE
#define DEF_PLAYSTATE

#include <SFML/Graphics.hpp>

#include "State.h"
#include "Game.h"
#include "IA.h"

class PlayState : public State
{
private:
	GameDataRef data;
	sf::Sprite backgroundSprite;
	sf::Sprite pauseButtonSprite;
	sf::Sprite gridSprite;
	sf::Sprite gridPieces[3][3];
	sf::Clock clock;

	IA *ia;
	int gridArray[3][3];
	int turn;
	int gameState;

	void initGridPieces();
	void checkAndPlacePiece();
	void checkPlayerWon(int _turn);
	void checkThreePiecesForMatch(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _pieceToCheck);
public:
	PlayState(GameDataRef _data);
	~PlayState();

	void init();
	void handleInput();

	void update(float dt);
	void render(float dt);
};

#endif // !DEF_PLAYSTATE
