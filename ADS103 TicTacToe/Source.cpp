#include <iostream>
#include <string>
#include <fstream>
#include <SDL.h>
#include <vector>
#include "GameBoard.h"
#include "TitleScreen.h"
#include "PlayerVsPlayer.h"
#include "Buttons.h"
#include "ScoreController.h"

using namespace std;

int main(int argc, char** arrgv)
{

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "Error: " << SDL_GetError() << endl;
		system("pause");
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("TIC TAC TOE", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 1024, 768, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		cout << "Error: " << SDL_GetError() << endl;
		SDL_Quit();
		system("pause");
		return 1;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL)
	{
		cout << "Error: " << SDL_GetError() << endl;
		SDL_DestroyWindow(window);
		system("pause");
		return 1;
	}

	ifstream readfile;
	ofstream Writefile;
	GameBoard gameBoard(renderer);
	TitleScreen titleScreen(renderer);
	PlayerVsPlayer playerVsPlayer(renderer);
	Buttons buttonsControl(renderer);
	ScoreController scores(renderer);

	int gameState = 1;
	vector<int> NumbersV;
	int playerTurn = 1;
	bool gameStarted = true;

	readfile.open("GameScores.txt");

	bool quit = false;
	//Game Loop incoming
	while (!quit)
	{
		SDL_Event e;
		if (gameState == 1)
		{
			//Get user inputs
			while (SDL_PollEvent(&e) != 0)
			{
				//user clicks close button
				if (e.type == SDL_QUIT)
					quit = true;
				if (e.type == SDL_KEYDOWN)
				{
					if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						quit = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_X)
					{
						scores.PlusOneAiGameLost(NumbersV);
					}
				}
				if (gameStarted == true)
				{
					scores.onStartUpdateArr(NumbersV);
					gameStarted = false;
				}
			}


		}
		else if (gameState == 2)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				//user clicks close button
				if (e.type == SDL_QUIT)
					quit = true;
				if (e.type == SDL_KEYDOWN)
				{
					if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						quit = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_RETURN)
					{
						gameBoard.clearBoard();
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_X)
					{
						gameBoard.clearBoard();
						gameBoard.clearScreen();
						titleScreen.draw();
						gameState = 1;
					}
				}

				if (gameBoard.checkForClick(e, GameBoard::CROSS))
				{
					Move aiMove = gameBoard.findBestMove(gameBoard.opponent);
					if (aiMove.row != -1 && aiMove.col != -1)
					{
						gameBoard.setTile(gameBoard.opponent, aiMove.row, aiMove.col);
					}
				}
			}
		}

		else if (gameState == 3)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				//user clicks close button
				if (e.type == SDL_QUIT)
					quit = true;
				if (e.type == SDL_KEYDOWN)
				{
					if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						quit = true;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_RETURN)
					{
						playerVsPlayer.clearBoard();
						playerTurn = 1;
					}
					if (e.key.keysym.scancode == SDL_SCANCODE_X)
					{
						playerVsPlayer.clearBoard();
						playerVsPlayer.clearScreen();
						titleScreen.draw();
						gameState = 1;
					}
				}

				if (playerTurn == 1)
				{
					playerVsPlayer.checkForClick(e, PlayerVsPlayer::CROSS);
					if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
					{
						playerTurn = 2;
					}
				}

				else if (playerTurn == 2)
				{
					playerVsPlayer.checkForClick(e, PlayerVsPlayer::NAUGHT);
					if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
					{
						playerTurn = 1;
					}
				}
			}
		}


		SDL_SetRenderDrawColor(renderer, 170, 170, 170, 255); //rgba(0-255) //Use paint to change color of background, the first three numbers colorate to red green and blue
		SDL_RenderClear(renderer);

		titleScreen.draw();

		if (gameState == 1)
		{
			if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
			{
				if (buttonsControl.playerVsAiButton(e))
				{
					scores.PlusOneAiGamePlayed(NumbersV);
					gameState = 2;
					gameBoard.update();
				}
				else if (buttonsControl.playerVsPlayerButton(e))
				{
					scores.PlusOnePvPGamePlayed(NumbersV);
					gameState = 3;
					playerVsPlayer.update();
				}
			}
		}

		if (gameState == 2)
			gameBoard.update();

		if (gameState == 3)
			playerVsPlayer.update();

		//swaps the buffers
		SDL_RenderPresent(renderer);
	}

	scores.updateOnClose(NumbersV);
	return 0;
}