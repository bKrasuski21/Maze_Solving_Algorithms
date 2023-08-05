//Bernard Krasuski
//COP3530 Project 3
//Last Edited - 8/5/2023


#include "Platform/Platform.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Maze.h"
#include "Node.h"
#include <chrono>
using namespace std;

int main()
{
	cout << "please give me the size of your graph: ";

	int size;
	cin >> size;
	//cout << size;
	Maze newMaze(size);
	auto dfsClockStart = chrono::steady_clock::now();
	newMaze.DFSsearch();
	auto dfsClockFinish = chrono::steady_clock::now();
	chrono::duration<double> elapstedTimeDFS = dfsClockFinish - dfsClockStart;
	cout << "Depth First Search elapsed time: " << elapstedTimeDFS.count() << "s" << endl;


	auto bfsClockStart = chrono::steady_clock::now();
	newMaze.BFSsearch();
	auto bfsClockFinish = chrono::steady_clock::now();
	chrono::duration<double> elapstedTimeBFS = bfsClockFinish - bfsClockStart;
	cout << "Breath First Search elapsed time: " << elapstedTimeBFS.count() << "s" << endl;


	newMaze.renderMaze();




	return 0;
}
