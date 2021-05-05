#include "TitleScreen.h"

TitleScreen::TitleScreen(SDL_Renderer* renderer)
{
	this->renderer = renderer;

	title = IMG_LoadTexture(renderer, "assets/Title.png");
	playervsai = IMG_LoadTexture(renderer, "assets/PlayerVSAi.png");
	playerVSplayer = IMG_LoadTexture(renderer, "assets/PlayerVsPlayer.png");
	statsScreen = IMG_LoadTexture(renderer, "assets/StatsScreen.png");
}

TitleScreen::~TitleScreen()
{
	SDL_DestroyTexture(title);
	SDL_DestroyTexture(playervsai);
	SDL_DestroyTexture(playerVSplayer);
	SDL_DestroyTexture(statsScreen);
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

	drawRect.x = statsScreenX;
	drawRect.y = statsScreenY;
	drawRect.w = 463;
	drawRect.h = 75;
	SDL_RenderCopy(renderer, statsScreen, NULL, &drawRect);

}

void TitleScreen::clearScreen()
{
	SDL_RenderClear(renderer);
}
