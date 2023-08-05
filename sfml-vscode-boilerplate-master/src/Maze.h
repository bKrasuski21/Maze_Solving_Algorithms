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
	vector<vector<int>> solvedMazeDFS;
	vector<vector<int>> solvedMazeBFS;
	int startX;
	int startY;
	int finishX;
	int finishY;
	int nodesVisitedDFS;
	int nodesVisitedBFS;
	public:

	Maze();
	//~Maze();
	Maze(int size);
	void renderMaze();
	bool DFSsearch();
	bool BFSsearch();
};
