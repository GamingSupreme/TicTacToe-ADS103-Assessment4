#include "ScoreController.h"

ScoreController::ScoreController(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

void ScoreController::PlusOneAiGamePlayed(vector<int> &NumbersVec)
{
	NumbersVec[0]++;
}

void ScoreController::PlusOnePvPGamePlayed(vector<int> &NumbersVec)
{
	NumbersVec[1]++;
}

void ScoreController::PlusOneAiGameLost(vector<int> &NumbersVec)
{
	NumbersVec[2]++;
}

void ScoreController::PlusOnePvPGameLost(vector<int> &NumbersVec)
{
	NumbersVec[3]++;
}

void ScoreController::PlusOneAiGameWon(vector<int> &NumbersVec)
{
	NumbersVec[4]++;
}

void ScoreController::PlusOnePvPGameWon(vector<int> &NumbersVec)
{
	NumbersVec[5]++;
}

void ScoreController::onStartUpdateArr(vector<int> &NumbersVec)
{
	ifstream readfile;
	readfile.open("GameScores.txt");
	string StringNumber = "";

	int line_num = -1;

	for (int i = 0; i < 6; i++)
	{
		while (line_num != i && getline(readfile, StringNumber))
		{
			++line_num;
		}

		int TheNumber;
		stringstream ss(StringNumber);
		ss >> TheNumber;

		if (line_num == i)
		{
			NumbersVec.push_back(TheNumber);
		}
	}
}

void ScoreController::updateOnClose(vector<int>& NumbersVec)
{
	ofstream writefile;
	writefile.open("GameScores.txt");
	for (int i = 0; i < NumbersVec.size(); i++)
	{
		writefile << NumbersVec[i] << endl;
	}
}
