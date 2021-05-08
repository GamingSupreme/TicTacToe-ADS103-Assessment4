#pragma once
#include "TitleScreen.h"
#include "GamemodeScores.h"
class StatsScreen
{
public:
	int gameState = 4;
	int BotGamesPlayedY = 100, BotGamesPlayedX = 100;
	int PvPGamesPlayedY = 250, PvPGamesPlayedX = 100;
	int BotGamesLostY = 400, BotGamesLostX = 100;
	int BotGamesWonY = 550, BotGamesWonX = 100;

	GamemodeScores PlayerVsAiPlayed;
	GamemodeScores PlayerVsAiLost;
	GamemodeScores PlayerVsAiWon;
	GamemodeScores PlayerVsPlayerPlayed;


	SDL_Renderer* renderer;
	SDL_Texture* BotGamesPlayed, * PvPGamesPlayed, * BotGamesLost, * BotGamesWon, * exitGame;

	StatsScreen(SDL_Renderer* renderer);
	~StatsScreen();

	void update();
	void draw();

	void clearScreen();
};

