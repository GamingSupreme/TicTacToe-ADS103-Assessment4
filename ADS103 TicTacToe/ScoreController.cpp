#include "ScoreController.h"

int ScoreController::TotalAiGamesPlayed(ifstream readfile, ofstream writefile)
{
	readfile.open("GameScores.txt");
	string StringNumber = "";

	int line_num = 0;
	while (line_num != 1 && getline(readfile, StringNumber))
	{
		++line_num;
	}

	int TheNumber;
	TheNumber = stoi(StringNumber);

	if (line_num == 1)
	{
		return TheNumber;
		readfile.close();
	}
}

int ScoreController::TotalPvPGamesPlayed(ifstream readfile, ofstream writefile)
{
	readfile.open("GameScores.txt");
	string StringNumber = "";

	int line_num = 0;
	while (line_num != 2 && getline(readfile, StringNumber))
	{
		++line_num;
	}

	int TheNumber;
	TheNumber = stoi(StringNumber);

	if (line_num == 2)
	{
		return TheNumber;
		readfile.close();
	}
}

int ScoreController::TotalAiGamesLost(ifstream readfile, ofstream writefile)
{
	readfile.open("GameScores.txt");
	string StringNumber = "";

	int line_num = 0;
	while (line_num != 3 && getline(readfile, StringNumber))
	{
		++line_num;
	}

	int TheNumber;
	TheNumber = stoi(StringNumber);

	if (line_num == 3)
	{
		return TheNumber;
		readfile.close();
	}
}

int ScoreController::TotalPvPGamesLost(ifstream readfile, ofstream writefile)
{
	readfile.open("GameScores.txt");
	string StringNumber = "";

	int line_num = 0;
	while (line_num != 4 && getline(readfile, StringNumber))
	{
		++line_num;
	}

	int TheNumber;
	TheNumber = stoi(StringNumber);

	if (line_num == 4)
	{
		return TheNumber;
		readfile.close();
	}
}

int ScoreController::TotalAiGamesWon(ifstream readfile, ofstream writefile)
{
	readfile.open("GameScores.txt");
	string StringNumber = "";

	int line_num = 0;
	while (line_num != 5 && getline(readfile, StringNumber))
	{
		++line_num;
	}

	int TheNumber;
	TheNumber = stoi(StringNumber);

	if (line_num == 5)
	{
		return TheNumber;
		readfile.close();
	}
}

int ScoreController::TotalPvPGamesWon(ifstream readfile, ofstream writefile)
{
	readfile.open("GameScores.txt");
	string StringNumber = "";

	int line_num = 0;
	while (line_num != 6 && getline(readfile, StringNumber))
	{
		++line_num;
	}

	int TheNumber;
	TheNumber = stoi(StringNumber);

	if (line_num == 6)
	{
		return TheNumber;
		readfile.close();
	}
}

void ScoreController::PlusOneAiGamePlayed(ifstream readfile, ofstream writefile)
{
}

void ScoreController::PlusOnePvPGamePlayed(ifstream readfile, ofstream writefile)
{
}

void ScoreController::PlusOneAiGameLost(ifstream readfile, ofstream writefile)
{
}

void ScoreController::PlusOnePvPGameLost(ifstream readfile, ofstream writefile)
{
}

void ScoreController::PlusOneAiGameWon(ifstream readfile, ofstream writefile)
{
}

void ScoreController::PlusOnePvPGameWon(ifstream readfile, ofstream writefile)
{
}
