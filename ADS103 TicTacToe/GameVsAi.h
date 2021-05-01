#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "res_path.h"

using namespace std;

class GameVsAi
{
public:
	int gameState = 2;

	void update();
	void draw();
};