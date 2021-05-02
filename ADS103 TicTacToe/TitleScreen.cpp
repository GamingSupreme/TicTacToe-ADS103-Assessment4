#include "TitleScreen.h"

TitleScreen::TitleScreen(SDL_Renderer* renderer)
{
	this->renderer = renderer;

	title = IMG_LoadTexture(renderer, "assets/Title.png");
	playervsai = IMG_LoadTexture(renderer, "assets/PlayerVSAi.png");
	playerVSplayer = IMG_LoadTexture(renderer, "assets/PlayerVsPlayer.png");
}

TitleScreen::~TitleScreen()
{
	SDL_DestroyTexture(title);
	SDL_DestroyTexture(playervsai);
	SDL_DestroyTexture(playerVSplayer);
}

void TitleScreen::update()
{
}

void TitleScreen::draw()
{
	SDL_Rect drawRect;
	drawRect.x = titleX;
	drawRect.y = titleY;
	drawRect.w = 458;
	drawRect.h = 75;
	SDL_RenderCopy(renderer, title, NULL, &drawRect);

	drawRect.x = playerAiX;
	drawRect.y = playerAiY;
	drawRect.w = 466;
	drawRect.h = 91;
	SDL_RenderCopy(renderer, playervsai, NULL, &drawRect);

	drawRect.x = playerVsPX;
	drawRect.y = playerVsPY;
	drawRect.w = 634;
	drawRect.h = 91;
	SDL_RenderCopy(renderer, playerVSplayer, NULL, &drawRect);

}

void TitleScreen::getTileXYBasedOnPixlXY(int pixelX, int pixelY, int& tileX, int& tileY)
{
	//if  pixel is not on board
	if (pixelX < playerAiX || pixelX > playerAiX + 466
		|| pixelY < playerAiY || pixelY > playerAiY + 91)
	{
		tileX = -1;
		tileY = -1;
		return; //bail not a valid move
	}

	//simplify math to ignore board offset
	pixelX = pixelX - playerAiX;
	pixelY = pixelY - playerAiY;

	//divide pixel values by tilesize to get board index values
	tileX = pixelX / 466;
	tileY = pixelY / 91;

	if (tileX == (pixelX / 466) && tileY == (pixelY / 91))
	{
		gameState = 2;
	}
}

int TitleScreen::checkForClick(SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
	{
		int tileX, tileY;
		//convert mouse coordinates to board index coordinates
		getTileXYBasedOnPixlXY(event.button.x, event.button.y, tileX, tileY);
		if (tileX != -1 && tileY != -1)
		{
			//is a valid move, try set it here
			return gameState;
		}
	}


	return 1;
}



void TitleScreen::clearScreen()
{
	SDL_RenderClear(renderer);
}
