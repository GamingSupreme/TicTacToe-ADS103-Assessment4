#include "GameBoard.h"

char GameBoard::BLANK = '-';
char GameBoard::CROSS = 'X';
char GameBoard::NAUGHT = 'O';

GameBoard::GameBoard(SDL_Renderer* renderer)
{
	this->renderer = renderer;

	blank = IMG_LoadTexture(renderer, "assets/blank.png");
	cross = IMG_LoadTexture(renderer, "assets/cross.png");
	naught = IMG_LoadTexture(renderer, "assets/naught.png");

	clearBoard();
}

GameBoard::~GameBoard()
{
	SDL_DestroyTexture(blank);
	SDL_DestroyTexture(cross);
	SDL_DestroyTexture(naught);
}

void GameBoard::clearBoard()
{
	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			board[x][y] = BLANK;
		}
	}
}

bool GameBoard::setTile(char type, int x, int y)
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

void GameBoard::getTileXYBasedOnPixlXY(int pixelX, int pixelY, int& tileX, int& tileY)
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

bool GameBoard::checkForClick(SDL_Event& event, char type)
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

bool GameBoard::checkForWin(char type)
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

bool GameBoard::checkIfAnyPlacesFree()
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

void GameBoard::draw()
{
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
	}
}

//player is maximiser (+10 for winning)
//opponent is minimiser (-10 for winning)
//0 for no wins or draw
int GameBoard::evaluate()
{
	if (checkForWin(player))
		return 10;
	if (checkForWin(opponent))
		return -10;

	return 0; //no winner
}

//minimax is a recursive function that explores all possible game playouts from 
//current board
int GameBoard::minimax(int depth, bool isMax)
{
	minimaxCount++;
	int score = evaluate();

	//if maximiser has won the game return his/her evaluated score
	if (score == 10)
		return score;

	//if minimiser has won do the same
	if (score == -10)
		return score;

	//if no winner and no moves return 0
	if (checkIfAnyPlacesFree() == false)
		return 0;

	//IF this is maximisers move
	if (isMax)
	{
		int best = -1000;

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				//check if cell is empty
				if (board[x][y] == BLANK)
				{
					//make the move
					board[x][y] = player;

					//call minimax
					best = max(best, minimax(depth + 1, !isMax));

					//undo move
					board[x][y] = BLANK;
				}
			}
		}
		return best;
	}
	else //minimisers turn
	{
		int best = 1000;

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				//check if cell is empty
				if (board[x][y] == BLANK)
				{
					//make the move
					board[x][y] = opponent;

					//call minimax
					best = min(best, minimax(depth + 1, !isMax));

					//undo move
					board[x][y] = BLANK;
				}
			}

		}
		return best;
	}
}

int GameBoard::minimax(int depth, bool isMax, int alpha, int beta)
{
	minimaxCount++;
	int score = evaluate();

	//if maximiser has won the game return his/her evaluated score
	if (score == 10)
		return score;

	//if minimiser has won do the same
	if (score == -10)
		return score;

	//if no winner and no moves return 0
	if (checkIfAnyPlacesFree() == false)
		return 0;

	bool breakLoops = false;

	//IF this is maximisers move
	if (isMax)
	{
		int best = -1000;

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				//check if cell is empty
				if (board[x][y] == BLANK)
				{
					//make the move
					board[x][y] = player;

					//call minimax
					best = max(best, minimax(depth + 1, !isMax, alpha, beta));

					//undo move
					board[x][y] = BLANK;

					alpha = max(alpha, best);
					if (beta <= alpha)
						breakLoops = true;

					if (breakLoops)
						break;
				}
				if (breakLoops)
					break;
			}
		}
		return best;
	}
	else //minimisers turn
	{
		int best = 1000;

		for (int x = 0; x < 3; x++)
		{
			for (int y = 0; y < 3; y++)
			{
				//check if cell is empty
				if (board[x][y] == BLANK)
				{
					//make the move
					board[x][y] = opponent;

					//call minimax
					best = min(best, minimax(depth + 1, !isMax, alpha, beta));

					//undo move
					board[x][y] = BLANK;

					beta = min(beta, best);
					if (beta <= alpha)
						breakLoops = true;

					if (breakLoops)
						break;
				}
				if (breakLoops)
					break;
			}

		}
		return best;
	}
}

Move GameBoard::findBestMove(char type)
{
	minimaxCount = 0;

	bool isMaximiser = true;// if type == player
	if (type == opponent)
		isMaximiser = false;

	int bestVal = -1000;
	if (!isMaximiser)
		bestVal = 1000;

	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	for (int x = 0; x < 3; x++)
	{
		for (int y = 0; y < 3; y++)
		{
			//check if cell is empty
			if (board[x][y] == BLANK)
			{
				//make a move
				board[x][y] = type;

				int moveVal = minimax(0, !isMaximiser, -1000, 1000);

				board[x][y] = BLANK; // undo move

				//MAXIMISER is this move better than previously computed ones
				if (isMaximiser && moveVal > bestVal)
				{
					bestMove.row = x;
					bestMove.col = y;
					bestVal = moveVal;
				}

				//MINIMISER is this move better than previously computed ones
				if (!isMaximiser && moveVal < bestVal)
				{
					bestMove.row = x;
					bestMove.col = y;
					bestVal = moveVal;
				}
			}

		}

	}


	cout << "The Value of the best move is " << bestVal << endl;
	cout << "Number of minimaxs run: " << minimaxCount << endl;

	return bestMove;
}
