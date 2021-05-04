#pragma once
#include <vector>
#include <fstream>
#include <sstream>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include "res_path.h"

using namespace std;

class ScoreController
{
public:
	vector<int> NumbersV;

	SDL_Renderer* renderer;

	ScoreController();
	
	void PlusOneAiGamePlayed(); //VECTOR 0
	void PlusOnePvPGamePlayed(); //VECTOR 1
	void PlusOneAiGameLost(); //VECTOR 2
	void PlusOnePvPGameLost(); //VECTOR 3
	void PlusOneAiGameWon(); // VECTOR 4
	void PlusOnePvPGameWon(); //VECTOR 5

	void onStartUpdateArr();
	void updateOnClose();
};

