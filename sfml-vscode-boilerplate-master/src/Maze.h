//Bernard Krasuski
//COP3530 Project 3
//Last Edited - 8/5/2023

#pragma once
#include <vector>
#include <string>
#include "Node.h"
using namespace std;

class Maze{
	private:
	int tempSize;
	vector<vector<int>> column;
	public:

	Maze();
	//~Maze();
	Maze(int size);
	void renderMaze();
};
