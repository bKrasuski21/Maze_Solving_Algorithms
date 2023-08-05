//Bernard Krasuski
//COP3530 Project 3
//Last Edited - 8/5/2023

#include <iostream>
#include "Node.h"

Node::Node(int xCord, int yCord, bool nodePath, sf::Texture &text){
	x = xCord;
	y = yCord;
	path = nodePath;
	sf::RectangleShape shape(sf::Vector2f(20.f , 20.f));
	shape.setTexture(&text);

}
