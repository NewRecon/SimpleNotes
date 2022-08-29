#pragma once
#include "SFML/Graphics.hpp"
#include <string>
#include <fstream>
#include <iostream>
class Sticker
{
private:
	sf::Rect<float>* rect;
	std::string textStr;
	sf::Text text;
	sf::Font font;
	int positionX;
	int positionY;
	std::string path;
	sf::RectangleShape sticker;
	sf::Color color;
	sf::Color outLineColor;
	sf::Texture texture;
	std::string intToStr(int num);
public:
	Sticker(){}
	Sticker(int positionX, int positionY, int id);
	void create();
	void edit();
	sf::RectangleShape getSticker();
	bool contain(sf::Vector2i coord);
	sf::Rect<float> getRect();
	void setPosition(int x, int y);
	void setPosition(sf::Vector2i);
	sf::Vector2i getPosition();
};