//Bernard Krasuski
//COP3530 Project 3
//Last Edited - 8/5/2023

#include "Maze.h"
#include <iostream>
#include <vector>
#include <time.h>
#include <stack>
#include "Platform/Platform.hpp"
#include <queue>

using namespace std;

Maze::Maze(int size)
{

	 					// initilaize column vector
	int temp = size + 1;
	int mazeSize = temp + size; // we need the vector to house a certain amount of NODES, but since we need to also have walls in our vector, this changes the size to account for walls based on the amount of nodes asked for
	int prev = 1;
	int prevRow = 1;
	tempSize = mazeSize;
	for(int i=0; i < mazeSize; i++){ // iterate through size of maze

		vector<int> row; // initilize row vector

		column.push_back(row); // pushback row vector to column vector to create 2D array

		for(int k = 0; k < mazeSize; k++){ // iterate through size of maze

			if(prevRow == 1){ // add all 1's in the vector to create walls

				column.at(i).push_back(1);

			} else {

			column.at(i).push_back(prev); // set all current "nodes" in maze to 0 or 1 depending on adjacent nodes

			if(prev == 1) // if previous node = 1 change next node to 0

				{prev = 0;}

			else if(prev == 0) // if previous node = 0 change next node to 1

				{prev = 1;}
			}
		}
		if(prevRow == 1)

			{prevRow = 0;} // changes next row from walls to nodes

		else if(prevRow == 0)

			{prevRow = 1;} // changes next row from nodes to walls

		prev = 1; // resets alternating order of nodes

	}

	//for(int i = 0; i < mazeSize; i++){

	//	for(int k=0; k < mazeSize; k++) {  // prints maze before maze is created

	//		cout << column[i][k] << " ";
	//	}

	//	cout << endl;
	//}

	int yMove[] = {2, 0, -2, 0}; // creates array for adjacent/neighboring nodes
	int xMove[] = {0, 2, 0, -2};

	int fun = mazeSize/2;    // allows maze to be created from center
		if(fun % 2 == 0){
			 fun++;
		}


		vector<vector<bool>> vusuted(mazeSize, vector<bool>(mazeSize, false)); // visited vector
		stack<pair<int, int>> mStack; // path stack
		mStack.push(make_pair(fun,fun)); // pushes back start node to stack
		vusuted[fun][fun] = true; // marks start node as visited

		while(!mStack.empty()){
			int x = mStack.top().first;

			int y = mStack.top().second;

			vusuted[x][y] = true; // sets current node to visited

			if(column[x][y] != 2) {column[x][y] = 3;} // changes value from wall to path

			vector<pair<int, int>> neighbors;

			for(int i =0; i < 4; i++){ // finds all 4 neighbors if theyre valid

				int newX = x + xMove[i];

				int newY = y + yMove[i];

					if(newX > 0 && newX < mazeSize && newY > 0 && newY < mazeSize){

						if(!vusuted[newX][newY]){

						neighbors.push_back(make_pair(newX, newY));} // adds neighbors to vector
					}
			}


			if(neighbors.empty()){ // once no more neighbors pops off stack
					mStack.pop();

			}else {
				int temp = neighbors.size();

				int dir = rand() % temp;

				mStack.push(make_pair(neighbors.at(dir).first, neighbors.at(dir).second)); // chooses random neighbor to push to stack

				int nextX = neighbors.at(dir).first;

				int nextY = neighbors.at(dir).second;

				if(nextX == x){
					if(nextY != y){
						int temp = nextY + y;

						temp = temp/2; // makes path between previous node and current node

						column[x][temp] = 4;
					}
				}else if(nextY == y){
					if(nextX != x){
						int temp = nextX + x;

						temp = temp/2; // makes path between previous node and current node

						column[temp][y] = 4;
					}
				}
			}
			neighbors.clear();
		}

	srand(time(NULL)); // set seed for random number

	int yStart[] = {1, 0, -1, 0}; // creates array for adjacent/neighboring nodes
	int xStart[] = {0, 1, 0, -1};
	bool start = false;
	while(!start){ // while no start has been chosen repeat
		int startNum = rand() % (mazeSize-2) + 1; // get a random number between 1 - size -1 for location of start
		int startSide = rand() % 4; // get a random number between 0- 3 to choose which side start will be on

	if(startSide == 0) // condition if start side = 0
		{
			int x = 0;

			int y = startNum;


				for(int i =0; i < 4; i++){ // finds all 4 neighbors if theyre valid

					int newX = x + xStart[i];

					int newY = y + yStart[i];

					if(newX > 0 && newX < mazeSize && newY > 0 && newY < mazeSize){
						if(column[newX][newY] == 3 || column[newX][newY] == 4){start = true;} // if there is a path neighbor set bool to true
					}
				}
			if(start) { // if there is a valid path neighbor change current node to start
				column[0][startNum] = 2;
				startX = 0;
				startY = startNum;
				}
		}

	else if(startSide == 1)
		{
			int x = mazeSize-1;

			int y = startNum;


				for(int i =0; i < 4; i++){ // finds all 4 neighbors if theyre valid

					int newX = x + xStart[i];

					int newY = y + yStart[i];

					if(newX > 0 && newX < mazeSize && newY > 0 && newY < mazeSize){
						if(column[newX][newY] == 3 || column[newX][newY] == 4){start = true;} // if there is a path neighbor set bool to true
					}
				}
			if(start) {
				column[mazeSize-1][startNum] = 2;
				startX = mazeSize-1;
				startY = startNum;
				}  // if there is a valid path neighbor change current node to start
		}

	else if(startSide == 2)
		{
			int x = startNum;

			int y = mazeSize-1;


				for(int i =0; i < 4; i++){ // finds all 4 neighbors if theyre valid

					int newX = x + xStart[i];

					int newY = y + yStart[i];

					if(newX > 0 && newX < mazeSize && newY > 0 && newY < mazeSize){
						if(column[newX][newY] == 3 || column[newX][newY] == 4){start = true;}
					}
				}
			if(start) {
				column[startNum][mazeSize-1] = 2;
				startY = mazeSize-1;
				startX = startNum;}  // if there is a valid path neighbor change current node to start
		}

	else if(startSide == 3)
		{
			int x = startNum;

			int y = 0;

				for(int i =0; i < 4; i++){ // finds all 4 neighbors if theyre valid

					int newX = x + xStart[i];

					int newY = y + yStart[i];

					if(newX > 0 && newX < mazeSize && newY > 0 && newY < mazeSize){
						if(column[newX][newY] == 3 || column[newX][newY] == 4){start = true;}// if valid neighbor for start sets bool to true
					}
				}
			if(start) {
				column[startNum][0] = 2;
				startY = 0;
				startX = startNum;
				}  // if there is a valid path neighbor change current node to start
		}
	}

	bool finish = false;
	while(!finish){ // while no finish has been chosen repeat
		int finishNum = rand() % (mazeSize-2) + 1; // get a random number between 1 - size -1 for location of start
		int finishSide = rand() % 4; // get a random number between 0- 3 to choose which side start will be on

	if(finishSide == 0)
		{
			int x = 0;

			int y = finishNum;

				for(int i =0; i < 4; i++){ // finds all 4 neighbors if theyre valid

					int newX = x + xStart[i];

					int newY = y + yStart[i];

					if(newX > 0 && newX < mazeSize && newY > 0 && newY < mazeSize){
						if(column[newX][newY] == 3 || column[newX][newY] == 4){finish = true;}// if valid neighbor for finish sets bool to true
					}
				}
			if(finish) {
				column[0][finishNum] = 5;
				finishX = 0;
				finishY = finishNum;}  // if there is a valid path neighbor change current node to start
		}
	else if(finishSide == 1)
		{
			int x = mazeSize-1;

			int y = finishNum;

				for(int i =0; i < 4; i++){ // finds all 4 neighbors if theyre valid

					int newX = x + xStart[i];

					int newY = y + yStart[i];

					if(newX > 0 && newX < mazeSize && newY > 0 && newY < mazeSize){
						if(column[newX][newY] == 3 || column[newX][newY] == 4){finish = true;}// if valid neighbor for finish sets bool to true
					}
				}
			if(finish) {
				column[mazeSize-1][finishNum] = 5;
				finishX = mazeSize-1;
				finishY = finishNum;
				}  // if there is a valid path neighbor change current node to start
		}
	else if(finishSide == 2)
		{
			int x = finishNum;

			int y = mazeSize-1;

				for(int i =0; i < 4; i++){ // finds all 4 neighbors if theyre valid

					int newX = x + xStart[i];

					int newY = y + yStart[i];

					if(newX > 0 && newX < mazeSize && newY > 0 && newY < mazeSize){
						if(column[newX][newY] == 3 || column[newX][newY] == 4){finish = true;} // if valid neighbor for finish sets bool to true
					}
				}
			if(finish) {
				column[finishNum][mazeSize-1] = 5;
				finishX = finishNum;
				finishY = mazeSize-1;}  // if there is a valid path neighbor change current node to start
		}
	else if(finishSide == 3)
		{
			int x = finishNum;

			int y = 0;

				for(int i =0; i < 4; i++){ // finds all 4 neighbors if theyre valid

					int newX = x + xStart[i];

					int newY = y + yStart[i];

					if(newX > 0 && newX < mazeSize && newY > 0 && newY < mazeSize){
						if(column[newX][newY] == 3 || column[newX][newY] == 4){finish = true;} // if valid neighbor for finish sets bool to true
					}
				}
			if(finish) {
				column[finishNum][0] = 5;
				finishY = 0;
				finishX = finishNum;
			}  // if there is a valid path neighbor change current node to start
		}
	}

	cout << "Everything ended properly??" << endl; // for printing numerical equivalent of maze
	for(int i = 0; i < mazeSize; i++){
			vector<int> mazeRow;
			solvedMazeBFS.push_back(mazeRow);
			solvedMazeDFS.push_back(mazeRow);
		for(int k=0; k < mazeSize; k++) {
			//cout << column[i][k] << " ";
			solvedMazeDFS.at(i).push_back(column[i][k]);
			solvedMazeBFS.at(i).push_back(column[i][k]);
		}
		//cout << endl;
	}

}

void Maze::renderMaze(){

	util::Platform platform;

	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(1600.0f * screenScalingFactor, 1200.0f * screenScalingFactor), "Maze Ronner (pls no copyright)");
	platform.setIcon(window.getSystemHandle());

	sf::Texture pathTexture;
	sf::Texture algoText;
	sf::Texture noPathTexture;
	sf::Texture finish;
	sf::Texture BFSText;
	sf::Texture DFSText;
	sf::Texture solved;
	sf::Texture resetText;
	sf::Texture solvedDfs;
	bool BFSButton = false;
	bool DFSButton = false;
	bool resetButton = true;

	noPathTexture.loadFromFile("content/yellow.png");
	pathTexture.loadFromFile("content/path.png");
	algoText.loadFromFile("content/magenta.png");
	finish.loadFromFile("content/niceGreen.png");
	DFSText.loadFromFile("content/dfs.png");
	BFSText.loadFromFile("content/bfs.png");
	solved.loadFromFile("content/redd.png");
	solvedDfs.loadFromFile("content/Orange.png");
	resetText.loadFromFile("content/reset.png");


	/*vector<vector<Node>> nodeVector;

	for(int i =0; i < (int)column.size(); i++){
		vector<Node> nodeRow;
		nodeVector.push_back(nodeRow);
		for(int k = 0; k < (int)column[0].size(); k++){
			if(column[i][k] == 1){
				bool path = false;
				Node mNode( i,  k, path, noPathTexture);
				nodeVector.at(i).push_back(mNode);
			}else {
				bool path = true;
				Node mNode( i,  k, path, pathTexture);
				nodeVector.at(i).push_back(mNode);
			}
		}
	}
	*/

	float sizeOfNode = 1200.0/(float)tempSize;
	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		sf::RectangleShape bfs(sf::Vector2f(200.f, 200.f));
		sf::RectangleShape dfs(sf::Vector2f(200.f, 200.f));
		sf::RectangleShape reset(sf::Vector2f(200.f, 200.f));
		bfs.setPosition(1300, 100);
		dfs.setPosition(1300, 400);
		reset.setPosition(1300, 700);
		bfs.setTexture(&BFSText);
		dfs.setTexture(&DFSText);
		reset.setTexture(&resetText);

		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			//sf::Vector2i localPos = sf::Mouse::getPosition(window);
			int x = sf::Mouse::getPosition(window).x;
			int y = sf::Mouse::getPosition(window).y;
			if(x >1299 && x < 1501){
				if(y >= 100 && y <= 300){
					bfs.setSize(sf::Vector2f(150.f, 150.f));
					BFSButton = true;
					DFSButton = false;
					resetButton = false;
				}
				else if(y >=400 && y <= 600){
					dfs.setSize(sf::Vector2f(150.f, 150.f));
					DFSButton = true;
					BFSButton = false;
					resetButton = false;
				}else if(y >= 700 && y <= 900){
					reset.setSize(sf::Vector2f(150.f, 150.f));
					DFSButton = false;
					BFSButton = false;
					resetButton = true;
				}
			}
		}
		if(resetButton){
			for(int i =0; i < tempSize; i++){
				for(int k = 0; k < tempSize; k++){
					//nodeVector[i][k].setPosition(20.f * i, 20.f * k);
					sf::RectangleShape shape(sf::Vector2f(sizeOfNode , sizeOfNode));
					shape.setPosition(sizeOfNode * i, sizeOfNode * k);
					if(column[i][k] == 1){
						shape.setTexture(&noPathTexture);
					}else if(column[i][k] == 6){
						shape.setTexture(&solved);
					}else if(column[i][k] == 5){
						shape.setTexture(&finish);
					}else if(column[i][k] == 2){
						shape.setTexture(&algoText);
					}else {
						shape.setTexture(&pathTexture);
					}
					window.draw(shape);
				}
			}
		}
		if(BFSButton){
			for(int i =0; i < tempSize; i++){
				for(int k = 0; k < tempSize; k++){
					//nodeVector[i][k].setPosition(20.f * i, 20.f * k);
					sf::RectangleShape shape(sf::Vector2f(sizeOfNode , sizeOfNode));
					shape.setPosition(sizeOfNode * i, sizeOfNode * k);
					if(solvedMazeBFS[i][k] == 1){
						shape.setTexture(&noPathTexture);
					}else if(solvedMazeBFS[i][k] == 6){
						shape.setTexture(&solved);
					}else if(solvedMazeBFS[i][k] == 5){
						shape.setTexture(&finish);
					}else if(solvedMazeBFS[i][k] == 2){
						shape.setTexture(&algoText);
					}else {
						shape.setTexture(&pathTexture);
					}
					window.draw(shape);
				}
			}
		}
		if(DFSButton){
			for(int i =0; i < tempSize; i++){
				for(int k = 0; k < tempSize; k++){
					//nodeVector[i][k].setPosition(20.f * i, 20.f * k);
					sf::RectangleShape shape(sf::Vector2f(sizeOfNode , sizeOfNode));
					shape.setPosition(sizeOfNode * i, sizeOfNode * k);
					if(solvedMazeDFS[i][k] == 1){
						shape.setTexture(&noPathTexture);
					}else if(solvedMazeDFS[i][k] == 6){
						shape.setTexture(&solvedDfs);
					}else if(solvedMazeDFS[i][k] == 5){
						shape.setTexture(&finish);
					}else if(solvedMazeDFS[i][k] == 2){
						shape.setTexture(&algoText);
					}else {
						shape.setTexture(&pathTexture);
					}
					window.draw(shape);
				}
			}
		}


		window.draw(bfs);
		window.draw(dfs);
		window.draw(reset);
		window.display();
	}
}

bool Maze::DFSsearch(){
	int yMove[] = {1, 0, -1, 0}; // creates array for adjacent/neighboring nodes
	int xMove[] = {0, 1, 0, -1};

	vector<vector<bool>> visitedVert(tempSize, vector<bool>(tempSize, false));
	stack<pair<int, int>> mStack;

	visitedVert[startX][startY] = true;
	mStack.push(make_pair(startX,startY));
	nodesVisitedDFS = 0;
	while(!mStack.empty()){

				int x = mStack.top().first;
				int y = mStack.top().second;
				if(solvedMazeDFS[x][y] != 2 && solvedMazeDFS[x][y] != 5){
					solvedMazeDFS[x][y] = 6;
				}

				mStack.pop();
					if(x == finishX && y == finishY){
						cout << "Aooke" << endl;

						cout << nodesVisitedDFS << "DFs " << endl;
						return true;
					}

			for(int i =0; i < 4; i++){ // finds all 4 neighbors if theyre valid

				int newX = x + xMove[i];

				int newY = y + yMove[i];

					if(newX >= 0 && newX < tempSize && newY >= 0 && newY < tempSize && solvedMazeDFS[newX][newY] != 1 && !visitedVert[newX][newY])
					{
						mStack.push(make_pair(newX, newY));
						nodesVisitedDFS++;
						visitedVert[newX][newY] = true;
				}
			}
		}
		return false;
	}
bool Maze::BFSsearch(){
	int xMove[] = {-1, 0, 1, 0}; // creates array for adjacent/neighboring nodes
	int yMove[] = {0, -1, 0, 1};

	vector<vector<bool>> visitedVert(tempSize, vector<bool>(tempSize, false));
	queue<pair<int, int>> mQueue;

	visitedVert[startX][startY] = true;
	mQueue.push(make_pair(startX,startY));
	nodesVisitedBFS = 0;
	while(!mQueue.empty()){

				int x = mQueue.front().first;
				int y = mQueue.front().second;
				if(solvedMazeBFS[x][y] != 2 && solvedMazeBFS[x][y] != 5){
					solvedMazeBFS[x][y] = 6;
				}

				mQueue.pop();
					if(x == finishX && y == finishY){
						cout << "Aooke" << endl;

						cout << nodesVisitedBFS <<  " BFS " << endl;
						return true;
					}

			for(int i =0; i < 4; i++){ // finds all 4 neighbors if theyre valid

				int newX = x + xMove[i];

				int newY = y + yMove[i];

					if(newX >= 0 && newX < tempSize && newY >= 0 && newY < tempSize && solvedMazeBFS[newX][newY] != 1 && !visitedVert[newX][newY])
					{
						mQueue.push(make_pair(newX, newY));
						nodesVisitedBFS++;
						visitedVert[newX][newY] = true;
				}
			}
		}
		return false;
	}