#include <iostream>
#include <string>
#include <SDL.h>
#include "GameBoard.h"

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

	GameBoard gameBoard(renderer);

	bool quit = false;
	//Game Loop incoming
	while (!quit)
	{
		//Get user inputs
		SDL_Event e;
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


		SDL_SetRenderDrawColor(renderer, 170, 170, 170, 255); //rgba(0-255) //Use paint to change color of background, the first three numbers colorate to red green and blue
		SDL_RenderClear(renderer);

		gameBoard.draw();



		//swaps the buffers
		SDL_RenderPresent(renderer);

	}

	return 0;
}