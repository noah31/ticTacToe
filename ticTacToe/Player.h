#pragma once
#include <string>
#include <stdlib.h>

using namespace std;

class Player{
private:
	string name;
	int score;
public:
	void setName(string value);
	void addScore();
	void resetScore();
	string getName();
	int getScore();
};