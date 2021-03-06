#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "res_path.h"
#include "ScoreController.h"

using namespace std;

struct Move
{
	int row, col;
};

class GameBoard: public ScoreController
{
public:
	static char BLANK;
	static char CROSS;
	static char NAUGHT;

	SDL_Renderer* renderer;
	SDL_Texture* blank, * cross, * naught, * computerWin, * playerWin, * playAgain, *drawGame, * exitGame;

	char board[3][3];
	int boardX = 425, boardY = 200;
	int tileSize = 50;

	char player = CROSS, opponent = NAUGHT;

	int minimaxCount = 0;

	GameBoard(SDL_Renderer* renderer);
	~GameBoard();
	void clearBoard();
	bool setTile(char type, int x, int y);
	void getTileXYBasedOnPixlXY(int pixelX, int pixelY, int& tileX, int& tileY);
	bool checkForClick(SDL_Event& event, char type);
	bool checkForWin(char type);
	bool checkIfAnyPlacesFree();
	void clearScreen();
	void winner();

	void draw();

	//MiniMax Stuff
	int evaluate();
	//recursive Function
	int minimax(int depth, bool isMax);
	//minimax using alpha beta pruning
	int minimax(int depth, bool isMax, int alpha, int beta);
	Move findBestMove(char type);
	
	void update();

};

