#include "ScoreController.h"

ScoreController::ScoreController()
{

}

void ScoreController::PlusOneAiGamePlayed()
{
	NumbersV[0]++;
}

void ScoreController::PlusOnePvPGamePlayed()
{
	NumbersV[1]++;
}

void ScoreController::PlusOneAiGameLost()
{
	int temp = NumbersV[2];
	NumbersV[2] = (temp + 1);
	//NumbersV[2]++;
}

void ScoreController::PlusOnePvPGameLost()
{
	NumbersV[3]++;
}

void ScoreController::PlusOneAiGameWon()
{
	NumbersV[4]++;
}

void ScoreController::PlusOnePvPGameWon()
{
	NumbersV[5]++;
}

void ScoreController::onStartUpdateArr()
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
			NumbersV.push_back(TheNumber);
		}
	}
}

void ScoreController::updateOnClose()
{
	ofstream writefile;
	writefile.open("GameScores.txt");
	for (int i = 0; i < NumbersV.size(); i++)
	{
		writefile << NumbersV[i] << endl;
	}
}
