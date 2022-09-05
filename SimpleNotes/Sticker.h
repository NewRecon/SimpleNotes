#pragma once
#include "SFML/Graphics.hpp"
#include <fstream>
#include <iostream>
using namespace std;

class Sticker
{
private:
	sf::Rect<float>* rect;
	sf::String textStr;
	sf::Text text;
	sf::Font font;
	int positionX;
	int positionY;
	//std::string path;
	sf::RectangleShape sticker;
	sf::Color color;
	sf::Color outLineColor;
	sf::Texture textureStick;
	int strSize[14] = {};
	int str = 0; //номер строчки
	std::string intToStr(int num);
public:
	Sticker(){}
	Sticker(int positionX, int positionY, int id);
	Sticker& operator = (const Sticker& other);
	void create();
	void edit();
	sf::RectangleShape getSticker();
	bool contain(sf::Vector2i coord);
	sf::Rect<float> getRect();
	void setPosition(int x, int y);
	void setPosition(sf::Vector2i);
	sf::Vector2i getPosition();
	sf::Text getText();
	sf::String getStr();
};