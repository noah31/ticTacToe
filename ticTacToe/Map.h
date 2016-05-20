#pragma once
#include "Player.h"
#include <iostream>

class Map{
private:
	Player pOne;
	Player pTwo;
	int grid[3][3];
	bool pOneTurn;
public:
	Map();
	void setNameOne(string value);
	void setNameTwo(string value);
	void chooseTile(int x, int y);
	void printMap();
	void resetMap();
	string getName(int player);
	bool win(int player);
	bool isSame(int p1, int p2, int p3, int mark);
	void run();
	bool draw();
};