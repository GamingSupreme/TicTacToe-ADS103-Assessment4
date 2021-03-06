#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "res_path.h"

using namespace std;

class Buttons
{
public:

	int playerAiY = 250, playerAiX = 300;
	int playerVsPY = 350, playerVsPX = 300;
	int statsScreenY = 450, statsScreenX = 300;

	SDL_Renderer* renderer;

	bool playerVsPlayerButton(SDL_Event& event);
	bool playerVsAiButton(SDL_Event& event);
	bool StatsScreenButton(SDL_Event& event);
	Buttons(SDL_Renderer* renderer);
	~Buttons();

};

