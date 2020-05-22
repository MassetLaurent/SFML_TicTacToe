#include <iostream>

#include "IA.h"
#include "Definitions.h"

//constructor
IA::IA(int _playerPiece, GameDataRef _data) : data(_data), playerPiece(_playerPiece)
{
	if (playerPiece == O_PIECE)
		iaPiece = X_PIECE;
	else
		iaPiece = O_PIECE;

	checkMatchVector.push_back({ 0, 2, 1, 2, 2, 2 });
	checkMatchVector.push_back({ 0, 2, 0, 1, 0, 0 });
	checkMatchVector.push_back({ 0, 2, 1, 1, 2, 0 });
	checkMatchVector.push_back({ 2, 2, 1, 2, 0, 2 });
	checkMatchVector.push_back({ 2, 2, 2, 1, 2, 0 });
	checkMatchVector.push_back({ 2, 2, 1, 1, 0, 0 });
	checkMatchVector.push_back({ 0, 0, 0, 1, 0, 2 });
	checkMatchVector.push_back({ 0, 0, 1, 0, 2, 0 });
	checkMatchVector.push_back({ 0, 0, 1, 1, 2, 2 });
	checkMatchVector.push_back({ 2, 0, 2, 1, 2, 2 });
	checkMatchVector.push_back({ 2, 0, 1, 0, 0, 0 });
	checkMatchVector.push_back({ 2, 0, 1, 1, 0, 2 });
	checkMatchVector.push_back({ 0, 1, 1, 1, 2, 1 });
	checkMatchVector.push_back({ 1, 2, 1, 1, 1, 0 });
	checkMatchVector.push_back({ 2, 1, 1, 1, 0, 1 });
	checkMatchVector.push_back({ 1, 0, 1, 1, 1, 2 });
	checkMatchVector.push_back({ 0, 1, 2, 1, 1, 1 });
	checkMatchVector.push_back({ 1, 2, 1, 0, 1, 1 });
	checkMatchVector.push_back({ 0, 2, 2, 0, 1, 1 });
	checkMatchVector.push_back({ 2, 2, 0, 0, 1, 1 });
	checkMatchVector.push_back({ 0, 2, 2, 2, 1, 2 });
	checkMatchVector.push_back({ 0, 0, 2, 0, 1, 0 });
	checkMatchVector.push_back({ 0, 2, 0, 0, 0, 1 });
	checkMatchVector.push_back({ 2, 2, 2, 0, 2, 1 });
}


//private methodes
void IA::checkSection(int _x1, int _y1, int _x2, int _y2, int _x3, int _y3, int _pieceToCheck, int(*_gridArray)[3][3], sf::Sprite _gridPieces[3][3])
{
	if ((*_gridArray)[_x1][_y1] == _pieceToCheck && (*_gridArray)[_x2][_y2] == _pieceToCheck)
	{
		if ((*_gridArray)[_x3][_y3] == EMPTY_PIECE)
		{
			(*_gridArray)[_x3][_y3] = IA_PIECE;
			_gridPieces[_x3][_y3].setTexture(data->assetManager.getTexture("O Piece"));
			_gridPieces[_x3][_y3].setColor(sf::Color(255, 255, 255, 255));

			throw -1;
		}
	}
}

void IA::checkIfPieceIsEmpty(int _x1, int _y1, int(*_gridArray)[3][3], sf::Sprite _gridPieces[3][3])
{
	if ((*_gridArray)[_x1][_y1] == EMPTY_PIECE)
	{
		(*_gridArray)[_x1][_y1] = IA_PIECE;
		_gridPieces[_x1][_y1].setTexture(data->assetManager.getTexture("O Piece"));
		_gridPieces[_x1][_y1].setColor(sf::Color(255, 255, 255, 255));
		throw -2;
	}
}


//public methodes
void IA::placePiece(int(*_gridArray)[3][3], sf::Sprite _gridPieces[3][3], int * _gameState)
{
	try
	{
		for (size_t i = 0; i < checkMatchVector.size(); i++)
		{
			checkSection(checkMatchVector[i][0], checkMatchVector[i][1], checkMatchVector[i][2], checkMatchVector[i][3], checkMatchVector[i][4], checkMatchVector[i][5], IA_PIECE, _gridArray, _gridPieces);
		}

		for (size_t i = 0; i < checkMatchVector.size(); i++)
		{
			checkSection(checkMatchVector[i][0], checkMatchVector[i][1], checkMatchVector[i][2], checkMatchVector[i][3], checkMatchVector[i][4], checkMatchVector[i][5], PLAYER_PIECE, _gridArray, _gridPieces);
		}

		//center is empty
		checkIfPieceIsEmpty(1, 1, _gridArray, _gridPieces);


		//corner empty ?
		checkIfPieceIsEmpty(0, 0, _gridArray, _gridPieces);
		checkIfPieceIsEmpty(0, 2, _gridArray, _gridPieces);
		checkIfPieceIsEmpty(2, 0, _gridArray, _gridPieces);
		checkIfPieceIsEmpty(2, 2, _gridArray, _gridPieces);


		//center line or colomn empty ?
		checkIfPieceIsEmpty(0, 1, _gridArray, _gridPieces);
		checkIfPieceIsEmpty(1, 0, _gridArray, _gridPieces);
		checkIfPieceIsEmpty(1, 2, _gridArray, _gridPieces);
		checkIfPieceIsEmpty(2, 1, _gridArray, _gridPieces);
	}
	catch (int error)
	{

	}

	*_gameState = STATE_PLAYING;
}
