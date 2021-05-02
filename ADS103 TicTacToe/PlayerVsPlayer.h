#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "res_path.h"

using namespace std;

class PlayerVsPlayer
{
public:
	static char BLANK;
	static char CROSS;
	static char NAUGHT;

	SDL_Renderer* renderer;
	SDL_Texture* blank, * cross, * naught, * playerOneWin, * playerTwoWin, * playAgain, * drawGame, * exitGame;

	char board[3][3];
	int boardX = 425, boardY = 200;
	int tileSize = 50;
	int gameState = 3;

	char playerOne = CROSS, playerTwo = NAUGHT;

	PlayerVsPlayer(SDL_Renderer* renderer);
	~PlayerVsPlayer();
	void clearBoard();
	bool setTile(char type, int x, int y);
	void getTileXYBasedOnPixlXY(int pixelX, int pixelY, int& tileX, int& tileY);
	bool checkForClick(SDL_Event& event, char type);
	bool checkForWin(char type);
	bool checkIfAnyPlacesFree();
	void clearScreen();

	void draw();
};

