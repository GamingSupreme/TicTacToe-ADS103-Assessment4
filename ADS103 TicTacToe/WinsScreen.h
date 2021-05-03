#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "res_path.h"

using namespace std;

class WinsScreen
{
public:
	int gameState = 4;

	SDL_Renderer* renderer;
	SDL_Texture* title, * playervsai, * playerVSplayer;

	WinsScreen(SDL_Renderer* renderer);
	~WinsScreen();

	void update();
	void draw();

	void clearScreen();
};

