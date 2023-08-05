#include "Platform/Platform.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Maze.h"
#include "Node.h"
using namespace std;

int main()
{
	cout << "please give me the size of your graph" << endl;

	int size;
	cin >> size;
	//cout << size;
	Maze newMaze(size);
	newMaze.renderMaze();




	return 0;
}
