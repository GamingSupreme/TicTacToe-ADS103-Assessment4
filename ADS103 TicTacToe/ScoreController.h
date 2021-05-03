#pragma once
#include <fstream>
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
	int TotalAiGamesPlayed(ifstream readfile, ofstream writefile);
	int TotalPvPGamesPlayed(ifstream readfile, ofstream writefile);
	int TotalAiGamesLost(ifstream readfile, ofstream writefile);
	int TotalPvPGamesLost(ifstream readfile, ofstream writefile);
	int TotalAiGamesWon(ifstream readfile, ofstream writefile);
	int TotalPvPGamesWon(ifstream readfile, ofstream writefile);
	
	void PlusOneAiGamePlayed(ifstream readfile, ofstream writefile);
	void PlusOnePvPGamePlayed(ifstream readfile, ofstream writefile);
	void PlusOneAiGameLost(ifstream readfile, ofstream writefile);
	void PlusOnePvPGameLost(ifstream readfile, ofstream writefile);
	void PlusOneAiGameWon(ifstream readfile, ofstream writefile);
	void PlusOnePvPGameWon(ifstream readfile, ofstream writefile);

};

