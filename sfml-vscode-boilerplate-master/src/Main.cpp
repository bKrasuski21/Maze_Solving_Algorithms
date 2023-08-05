#include "Platform/Platform.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "Maze.h"
using namespace std;

int main()
{
	util::Platform platform;

#if defined(_DEBUG)
	//std::cout << "Hello World!" << std::endl;
#endif


	sf::RenderWindow window;
	// in Windows at least, this must be called before creating the window
	float screenScalingFactor = platform.getScreenScalingFactor(window.getSystemHandle());
	// Use the screenScalingFactor
	window.create(sf::VideoMode(200.0f * screenScalingFactor, 200.0f * screenScalingFactor), "SFML works!");
	platform.setIcon(window.getSystemHandle());

	sf::CircleShape shape(window.getSize().x / 2);
	shape.setFillColor(sf::Color::White);

	sf::Texture shapeTexture;
	shapeTexture.loadFromFile("content/sfml.png");
	shape.setTexture(&shapeTexture);

	/*sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}*/
	cout << "please give me the size of your graph" << endl;

	int size;
	cin >> size;
	//cout << size;
	Maze newMaze(size);



	return 0;
}
