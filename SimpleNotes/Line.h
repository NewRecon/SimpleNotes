#pragma once
#include "SFML/Graphics.hpp"
class Line
{
	sf::Rect<float>* line = nullptr;
	sf::RectangleShape lineShape;

	int pos;
	int counter;

	int posX;
	int posY;
	int width;
	int height;

	sf::Text text;
	sf::Font font;
public:
	Line(){}
	void create(std::wstring str, int pos, int counter, sf::FloatRect rect);
	void setPos(sf::Vector2i vector);
	sf::Rect<float> getLine();
	sf::Text getText();
	sf::RectangleShape getShape();
	void setColor(bool flag);
};

