#include "PlayerVsPlayer.h"

char PlayerVsPlayer::BLANK = '-';
char PlayerVsPlayer::CROSS = 'X';
char PlayerVsPlayer::NAUGHT = 'O';

PlayerVsPlayer::PlayerVsPlayer(SDL_Renderer* renderer)
{
	this->renderer = renderer;

	blank = IMG_LoadTexture(renderer, "assets/blank.png");
	cross = IMG_LoadTexture(renderer, "assets/cross.png");
	naught = IMG_LoadTexture(renderer, "assets/naught.png");
	playerOneWin = IMG_LoadTexture(renderer, "assets/PlayerOneWin.png");
	playerTwoWin = IMG_LoadTexture(renderer, "assets/PlayerTwoWin.png");
	playAgain = IMG_LoadTexture(renderer, "assets/PlayAgain.png");
	drawGame = IMG_LoadTexture(renderer, "assets/Draw.png");
	exitGame = IMG_LoadTexture(renderer, "assets/Exit.png");

	clearBoard();
}

PlayerVsPlayer::~PlayerVsPlayer()
{
	SDL_DestroyTexture(blank);
	SDL_DestroyTexture(cross);
	SDL_DestroyTexture(naught);
	SDL_DestroyTexture(playerOneWin);
	SDL_DestroyTexture(playerTwoWin);
	SDL_DestroyTexture(playAgain);
	SDL_DestroyTexture(drawGame);
}

void PlayerVsPlayer::clearBoard()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			board[x][y] = BLANK;
		}
	}
}

bool PlayerVsPlayer::setTile(char type, int x, int y)
{
	//if xy is on board, try set tile
	if (x >= 0 && x <= 2 && y >= 0 && y <= 2)
	{
		//set if this tile is blank
		if (board[x][y] == BLANK)
		{
			board[x][y] = type;
			return true;
		}
	}


	return false;
}

void PlayerVsPlayer::getTileXYBasedOnPixlXY(int pixelX, int pixelY, int& tileX, int& tileY)
{
	//if  pixel is not on board
	if (pixelX < boardX || pixelX > boardX + (tileSize * 3)
		|| pixelY < boardY || pixelY > boardY + (tileSize * 3))
	{
		tileX = -1;
		tileY = -1;
		return; //bail not a valid move
	}

	//simplify math to ignore board offset
	pixelX = pixelX - boardX;
	pixelY = pixelY - boardY;

	//divide pixel values by tilesize to get board index values
	tileX = pixelX / tileSize;
	tileY = pixelY / tileSize;
}

bool PlayerVsPlayer::checkForClick(SDL_Event& event, char type)
{
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
	{
		int tileX, tileY;
		//convert mouse coordinates to board index coordinates
		getTileXYBasedOnPixlXY(event.button.x, event.button.y, tileX, tileY);
		if (tileX != -1 && tileY != -1)
		{
			//is a valid move, try set it here
			return setTile(type, tileX, tileY);
		}
	}


	return false;
}

bool PlayerVsPlayer::checkForWin(char type)
{
	//check horizontals
	for (int x = 0; x < 3; x++)
	{
		if (board[x][0] == type && board[x][1] == type && board[x][2] == type)
			return true;
	}

	//check verticals
	for (int y = 0; y < 3; y++)
	{
		if (board[0][y] == type && board[1][y] == type && board[2][y] == type)
			return true;
	}

	//check diagonals
	if (board[0][0] == type && board[1][1] == type && board[2][2] == type)
		return true;
	if (board[2][0] == type && board[1][1] == type && board[0][2] == type)
		return true;

	return false;
}

bool PlayerVsPlayer::checkIfAnyPlacesFree()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			if (board[x][y] == BLANK)
				return true;
		}
	}

	return false;
}

void PlayerVsPlayer::clearScreen()
{
	SDL_RenderClear(renderer);
}

void PlayerVsPlayer::draw()
{
	SDL_Rect drawRect;
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			SDL_Rect drawRect;
			drawRect.x = boardX + (x * tileSize);
			drawRect.y = boardY + (y * tileSize);
			drawRect.w = tileSize;
			drawRect.h = tileSize;

			if (board[x][y] == BLANK)
				SDL_RenderCopy(renderer, blank, NULL, &drawRect);
			if (board[x][y] == CROSS)
				SDL_RenderCopy(renderer, cross, NULL, &drawRect);
			if (board[x][y] == NAUGHT)
				SDL_RenderCopy(renderer, naught, NULL, &drawRect);
		}

		drawRect.x = 0;
		drawRect.y = 700;
		drawRect.h = 77;
		drawRect.w = 294;
		SDL_RenderCopy(renderer, exitGame, NULL, &drawRect);

		if (checkForWin(playerTwo))
		{
			//Ai win text to screen
			drawRect.x = 175;
			drawRect.y = 50;
			drawRect.h = 89;
			drawRect.w = 680;
			SDL_RenderCopy(renderer, playerTwoWin, NULL, &drawRect);

			//Play again text to screen
			drawRect.x = 50;
			drawRect.y = 400;
			drawRect.h = 91;
			drawRect.w = 959;
			SDL_RenderCopy(renderer, playAgain, NULL, &drawRect);
		}
		else if (checkForWin(playerOne))
		{
			//Computer win text to screen
			drawRect.x = 175;
			drawRect.y = 50;
			drawRect.h = 91;
			drawRect.w = 656;
			SDL_RenderCopy(renderer, playerOneWin, NULL, &drawRect);

			//Play again text to screen
			drawRect.x = 50;
			drawRect.y = 400;
			drawRect.h = 91;
			drawRect.w = 959;
			SDL_RenderCopy(renderer, playAgain, NULL, &drawRect);
		}
		else if (!checkIfAnyPlacesFree())
		{
			drawRect.x = 375;
			drawRect.y = 50;
			drawRect.h = 72;
			drawRect.w = 234;
			SDL_RenderCopy(renderer, drawGame, NULL, &drawRect);

			//Play again text to screen
			drawRect.x = 50;
			drawRect.y = 400;
			drawRect.h = 91;
			drawRect.w = 959;
			SDL_RenderCopy(renderer, playAgain, NULL, &drawRect);
		}
	}
}
