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
	cout << "Please give me the size of your maze: ";

	int size;
	cin >> size; // gets size of maze from user
	Maze newMaze(size);

	auto dfsClockStart = chrono::steady_clock::now(); // start timer
	newMaze.DFSsearch();
	auto dfsClockFinish = chrono::steady_clock::now(); // stops timer
	chrono::duration<double> elapstedTimeDFS = dfsClockFinish - dfsClockStart; // calculates time of DFS
	cout << "Depth First Search elapsed time: " << elapstedTimeDFS.count()  << "s" << endl; // prints out time for DFS


	auto bfsClockStart = chrono::steady_clock::now(); // starts timer for BFS
	newMaze.BFSsearch();
	auto bfsClockFinish = chrono::steady_clock::now(); // starts timer for BFS
	chrono::duration<double> elapstedTimeBFS = bfsClockFinish - bfsClockStart; // calculates time for BFS
	cout << "Breath First Search elapsed time: " << elapstedTimeBFS.count() << "s" << endl; // prints out time for BFS


	newMaze.renderMaze(); // renders maze and UI

	return 0;
}
