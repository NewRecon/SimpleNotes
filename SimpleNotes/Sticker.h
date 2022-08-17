#pragma once
#include "SFML/Graphics.hpp"
#include <string>
class Sticker
{
private:
	std::string text;
	sf::Font font;
	int positionX;
	int positionY;
	std::string path;
	sf::RectangleShape shape;
	sf::Color color;
public:
	Sticker(){}
	void create();
	void edit();
};

