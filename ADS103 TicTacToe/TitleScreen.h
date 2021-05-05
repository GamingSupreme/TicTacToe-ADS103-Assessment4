#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "res_path.h"

using namespace std;

class TitleScreen
{
public:
	int gameState = 1;
	int titleY = 100, titleX = 300;
	int playerAiY = 250, playerAiX = 300;
	int playerVsPY = 350, playerVsPX = 300;
	int statsScreenY = 450, statsScreenX = 300;

	SDL_Renderer* renderer;
	SDL_Texture* title, * playervsai, * playerVSplayer, * statsScreen;

	TitleScreen(SDL_Renderer* renderer);
	~TitleScreen();

	void update();
	void draw();

	void clearScreen();
};

