#pragma once
#include <iostream>

using namespace std;

class Node{

	private:
	int x;
	int y;
	bool path;
	sf::RectangleShape shape();

	public:
	Node(int xCord, int yCord, bool nodePath, sf::Texture &text);

};