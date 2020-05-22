#include <iostream>
#include <sstream>

#include "Definitions.h"
#include "PlayState.h"
#include "PauseState.h"
#include "GameOverState.h"

//constructor
PlayState::PlayState(GameDataRef _data) : data(_data)
{

}

PlayState::~PlayState()
{
	delete ia;
}

//privates methodes
void PlayState::initGridPieces()
{
	sf::Vector2u tempSpriteSize = data->assetManager.getTexture("X Piece").getSize();

	for (size_t x = 0; x < 3; x++)
	{
		for (size_t y = 0; y < 3; y++)
		{
			gridPieces[x][y].setTexture(data->assetManager.getTexture("X Piece"));

			gridPieces[x][y].setPosition(
				gridSprite.getPosition().x + (tempSpriteSize.x * x) - 7 ,
				gridSprite.getPosition().y + (tempSpriteSize.y * y) - 7
			);

			gridPieces[x][y].setColor(sf::Color(255, 255, 255, 0));
		}
	}
}

void PlayState::checkAndPlacePiece()
{
	sf::Vector2i clickPoint = data->inputManager.getMousePosition(data->window);
	sf::FloatRect gridSize = gridSprite.getGlobalBounds();
	sf::Vector2f gapOutsideOfGrid = sf::Vector2f((SCREEN_WIDTH - gridSize.width) / 2, (SCREEN_HEIGHT - gridSize.height) / 2);
	sf::Vector2f gridLocalTouchPos = sf::Vector2f(clickPoint.x - gapOutsideOfGrid.x, clickPoint.y - gapOutsideOfGrid.y);
	sf::Vector2f gridSectionSize = sf::Vector2f(gridSize.width / 3, gridSize.height / 3);

	int column(0), row(0);

	//define column of the click
	if (gridLocalTouchPos.x < gridSectionSize.x)
		column = 1;
	else if (gridLocalTouchPos.x < gridSectionSize.x * 2)
		column = 2;
	else if (gridLocalTouchPos.x < gridSize.width)
		column = 3;

	//define row of the click
	if (gridLocalTouchPos.y < gridSectionSize.y)
		row = 1;
	else if (gridLocalTouchPos.y < gridSectionSize.y * 2)
		row = 2;
	else if (gridLocalTouchPos.y < gridSize.height)
		row = 3;

	if (gridArray[column - 1][row - 1] == EMPTY_PIECE)
	{
		gridArray[column - 1][row - 1] = turn;

		if (turn == PLAYER_PIECE)
		{
			gridPieces[column - 1][row - 1].setTexture(data->assetManager.getTexture("X Piece"));

			checkPlayerWon(turn);
		}

		gridPieces[column - 1][row - 1].setColor(sf::Color(255, 255, 255, 255));
	}
}

void PlayState::checkPlayerWon(int _turn)
{
	checkThreePiecesForMatch(0, 0, 1, 0, 2, 0, _turn);
	checkThreePiecesForMatch(0, 1, 1, 1, 2, 1, _turn);
	checkThreePiecesForMatch(0, 2, 1, 2, 2, 2, _turn);
	checkThreePiecesForMatch(0, 0, 0, 1, 0, 2, _turn);
	checkThreePiecesForMatch(1, 0, 1, 1, 1, 2, _turn);
	checkThreePiecesForMatch(2, 0, 2, 1, 2, 2, _turn);
	checkThreePiecesForMatch(0, 0, 1, 1, 2, 2, _turn);
	checkThreePiecesForMatch(0, 2, 1, 1, 2, 0, _turn);

	if (gameState != STATE_WON)
	{
		gameState = STATE_IA_PLAYING;

		ia->placePiece(&gridArray, gridPieces, &gameState);

		checkThreePiecesForMatch(0, 0, 1, 0, 2, 0, IA_PIECE);
		checkThreePiecesForMatch(0, 1, 1, 1, 2, 1, IA_PIECE);
		checkThreePiecesForMatch(0, 2, 1, 2, 2, 2, IA_PIECE);
		checkThreePiecesForMatch(0, 0, 0, 1, 0, 2, IA_PIECE);
		checkThreePiecesForMatch(1, 0, 1, 1, 1, 2, IA_PIECE);
		checkThreePiecesForMatch(2, 0, 2, 1, 2, 2, IA_PIECE);
		checkThreePiecesForMatch(0, 0, 1, 1, 2, 2, IA_PIECE);
		checkThreePiecesForMatch(0, 2, 1, 1, 2, 0, IA_PIECE);
	}

	int emptyNum = 9;

	for (size_t x = 0; x < 3; x++)
	{
		for (size_t y = 0; y < 3; y++)
		{
			if (gridArray[x][y] != EMPTY_PIECE)
			{
				emptyNum--;
			}
		}
	}

	if (emptyNum == 0 && (gameState != STATE_WON) && (gameState != STATE_LOSE))
	{
		gameState = STATE_DRAW;
	}

	if (gameState == STATE_DRAW || gameState == STATE_LOSE || gameState == STATE_WON)
	{
		clock.restart();
	}
}

void PlayState::checkThreePiecesForMatch(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _pieceToCheck)
{
	if (_pieceToCheck == gridArray[_x1][_y1] && _pieceToCheck == gridArray[_x2][_y2] && _pieceToCheck == gridArray[_x3][_y3])
	{
		std::string winningPieceStr;

		if (_pieceToCheck == O_PIECE)
			winningPieceStr = "O win Piece";
		else
			winningPieceStr = "X win Piece";

		gridPieces[_x1][_y1].setTexture(data->assetManager.getTexture(winningPieceStr));
		gridPieces[_x2][_y2].setTexture(data->assetManager.getTexture(winningPieceStr));
		gridPieces[_x3][_y3].setTexture(data->assetManager.getTexture(winningPieceStr));

		if (_pieceToCheck == PLAYER_PIECE)
			gameState = STATE_WON;
		else
			gameState = STATE_LOSE;
	}
}

//methodes
void PlayState::init()
{
	gameState = STATE_PLAYING;
	turn = PLAYER_PIECE;
	ia = new IA(turn, data);

	data->assetManager.loadTexture("Pause Button", PAUSE_BUTTON_FILEPATH);
	data->assetManager.loadTexture("Grid Sprite", GRID_SPRITE_FILEPATH);
	data->assetManager.loadTexture("X Piece", X_PIECE_FILEPATH);
	data->assetManager.loadTexture("O Piece", O_PIECE_FILEPATH);
	data->assetManager.loadTexture("X win Piece", X_WIN_FILEPATH);
	data->assetManager.loadTexture("O win Piece", O_WIN_FILEPATH);

	backgroundSprite.setTexture(data->assetManager.getTexture("Main Menu Background"));
	pauseButtonSprite.setTexture(data->assetManager.getTexture("Pause Button"));
	gridSprite.setTexture(data->assetManager.getTexture("Grid Sprite"));
	
	gridSprite.setPosition(
		(SCREEN_WIDTH / 2) - (gridSprite.getGlobalBounds().width / 2),
		(SCREEN_HEIGHT / 2) - (gridSprite.getGlobalBounds().height / 2)
	);

	pauseButtonSprite.setPosition(
		data->window.getSize().x - (pauseButtonSprite.getGlobalBounds().width + 20.f),
		20.f
	);

	initGridPieces();

	for (size_t x = 0; x < 3; x++)
	{
		for (size_t y = 0; y < 3; y++)
		{
			gridArray[x][y] = EMPTY_PIECE;
		}
	}
}

void PlayState::handleInput()
{
	sf::Event event;

	while (this->data->window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			this->data->window.close();

		if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
			this->data->window.close();

		if (data->inputManager.isSpriteClicked(pauseButtonSprite, sf::Mouse::Left, data->window))
			data->stateMachine.addState(StateRef(new PauseState(data)), false);

		else if (data->inputManager.isSpriteClicked(gridSprite, sf::Mouse::Left, data->window))
		{
			if (gameState == STATE_PLAYING)
				this->checkAndPlacePiece();
		}
	}
}

void PlayState::update(float dt)
{
	if (gameState == STATE_DRAW || gameState == STATE_LOSE || gameState == STATE_WON)
	{
		if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_SHOW_GAME_OVER)
		{
			data->stateMachine.addState(StateRef(new GameOverState(data)), true);
		}
	}
}

void PlayState::render(float dt)
{
	data->window.clear();

	data->window.draw(backgroundSprite);
	data->window.draw(pauseButtonSprite);
	data->window.draw(gridSprite);

	for (size_t x = 0; x < 3; x++)
	{
		for (size_t y = 0; y < 3; y++)
		{
			data->window.draw(gridPieces[x][y]);
		}
	}

	data->window.display();
}
