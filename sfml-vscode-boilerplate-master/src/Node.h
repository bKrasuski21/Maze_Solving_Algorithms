//Bernard Krasuski
//COP3530 Project 3
//Last Edited - 8/5/2023

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