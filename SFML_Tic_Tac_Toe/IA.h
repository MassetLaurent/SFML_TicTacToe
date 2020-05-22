#ifndef DEF_IA
#define DEF_IA

#include <SFML/Graphics.hpp>
#include <vector>
#include <array>

#include "Game.h"

class IA
{
private:
	GameDataRef data;
	void checkSection(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _pieceToCheck, int(*_gridArray)[3][3], sf::Sprite _gridPieces[3][3]);
	void checkIfPieceIsEmpty(int _x1, int _y1, int(*_gridArray)[3][3], sf::Sprite _gridPieces[3][3]);
	
	int iaPiece, playerPiece;
	std::vector<std::array<int, 6>> checkMatchVector;

public:
	IA(int _playerPiece, GameDataRef _data);
	void placePiece(int(*_gridArray)[3][3], sf::Sprite _gridPieces[3][3], int *_gameState);
};
#endif // !DEF_IA