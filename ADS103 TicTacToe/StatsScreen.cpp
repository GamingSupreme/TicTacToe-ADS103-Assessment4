#include "StatsScreen.h"

StatsScreen::StatsScreen(SDL_Renderer* renderer)
{
	this->renderer = renderer;

	BotGamesLost = IMG_LoadTexture(renderer, "assets/BotGamesLost.png");
	BotGamesWon = IMG_LoadTexture(renderer, "assets/BotGamesWon.png");
	BotGamesPlayed = IMG_LoadTexture(renderer, "assets/BotGamesPlayed.png");
	PvPGamesPlayed = IMG_LoadTexture(renderer, "assets/PvPGamesPlayed.png");
	exitGame = IMG_LoadTexture(renderer, "assets/Exit.png");
}

StatsScreen::~StatsScreen()
{
	SDL_DestroyTexture(BotGamesLost);
	SDL_DestroyTexture(BotGamesWon);
	SDL_DestroyTexture(BotGamesPlayed);
	SDL_DestroyTexture(PvPGamesPlayed);
}

void StatsScreen::update()
{
	clearScreen();
	draw();
}

void StatsScreen::draw()
{
	SDL_Rect drawRect;
	drawRect.x = BotGamesPlayedX;
	drawRect.y = BotGamesPlayedY;
	drawRect.w = 668;
	drawRect.h = 90;
	SDL_RenderCopy(renderer, BotGamesPlayed, NULL, &drawRect);

	drawRect.x = PvPGamesPlayedX;
	drawRect.y = PvPGamesPlayedY;
	drawRect.w = 685;
	drawRect.h = 90;
	SDL_RenderCopy(renderer, PvPGamesPlayed, NULL, &drawRect);

	drawRect.x = BotGamesWonX;
	drawRect.y = BotGamesWonY;
	drawRect.w = 573;
	drawRect.h = 74;
	SDL_RenderCopy(renderer, BotGamesWon, NULL, &drawRect);

	drawRect.x = BotGamesLostX;
	drawRect.y = BotGamesLostY;
	drawRect.w = 558;
	drawRect.h = 74;
	SDL_RenderCopy(renderer, BotGamesLost, NULL, &drawRect);

	drawRect.x = 0;
	drawRect.y = 700;
	drawRect.h = 77;
	drawRect.w = 294;
	SDL_RenderCopy(renderer, exitGame, NULL, &drawRect);
}

void StatsScreen::clearScreen()
{
	SDL_RenderClear(renderer);
}
