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
	SDL_Renderer* renderer;

	ScoreController(SDL_Renderer* renderer);
	
	void PlusOneAiGamePlayed(vector<int> &NumbersVec); //VECTOR 0
	void PlusOnePvPGamePlayed(vector<int> &NumbersVec); //VECTOR 1
	void PlusOneAiGameLost(vector<int> &NumbersVec); //VECTOR 2
	void PlusOnePvPGameLost(vector<int> &NumbersVec); //VECTOR 3
	void PlusOneAiGameWon(vector<int> &NumbersVec); // VECTOR 4
	void PlusOnePvPGameWon(vector<int> &NumbersVec); //VECTOR 5

	void onStartUpdateArr(vector<int> &NumbersVec);
	void updateOnClose(vector<int> &NumbersVec);
};

