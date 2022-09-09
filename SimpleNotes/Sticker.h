#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>

#include <nlohmann/json.hpp>
#include <fstream>
using namespace nlohmann;

class Sticker
{
private:
	sf::Rect<float>* rect;
	std::wstring textStr;
	sf::Text text;
	sf::Font font;
	int positionX;
	int positionY;
	sf::RectangleShape sticker;
	sf::Color color;
	sf::Texture textureStick;
	int strSize[14] = {};
	int str = 0; //номер строчки, где коретка

	std::string path = "file.json";

public:
	Sticker(){}
	Sticker(int positionX, int positionY, int id);
	Sticker(std::wstring textStr, int positionX, int positionY,
		int strSize[14], int str, int r, int g, int b);
	Sticker& operator = (const Sticker& other);
	void edit();
	sf::RectangleShape getSticker();
	bool contain(sf::Vector2i coord);
	sf::Rect<float> getRect();
	void setPosition(int x, int y);
	void setPosition(sf::Vector2i);
	sf::Vector2i getPosition();
	sf::Text getText();
	std::wstring getStr();
	void save();
	void changeColor();
};