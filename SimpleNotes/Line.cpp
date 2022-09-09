#include "Line.h"

void Line::create(std::wstring str, int pos, int counter, sf::FloatRect rect)
{
	this->pos = pos;
	this->counter = counter;

	posX = rect.left;
	width = rect.width;
	height = rect.height / counter;
	posY = rect.top + height * pos;

	if (posX + width > 400)
	{
		posX = posX - width;
	}
	if (posY + height * counter - height * pos > 600)
	{
		posY = posY - height * counter;
	}

	lineShape.setPosition(posX, posY);
	lineShape.setSize(sf::Vector2f(width, height));
	lineShape.setFillColor(sf::Color::White);

	font.loadFromFile("C:/Windows/Fonts/CascadiaMono.ttf");

	text.setFont(font);
	text.setString(str);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(height-2);
	text.setPosition(posX + 2, posY);

	line = new sf::Rect<float>(posX, posY, width, height);
}

void Line::setPos(sf::Vector2i vector)
{
	posX = vector.x;
	posY = vector.y + height * pos;


	if (posX + width > 400)
	{
		posX = posX - width;
	}

	if (posY + height * counter - height * pos > 600)
	{
		posY = posY - height * counter;
	}

	line->left = posX;
	line->top = posY;

	text.setPosition(posX + 2, posY);
	lineShape.setPosition(posX, posY);
}

sf::Rect<float> Line::getLine()
{
	return *line;
}

sf::Text Line::getText()
{
	return text;
}

void Line::setColor(bool flag)
{
	if (flag)
	{
		text.setFillColor(sf::Color::White);
		lineShape.setFillColor(sf::Color::Blue);
	}
	else
	{
		text.setFillColor(sf::Color::Black);
		lineShape.setFillColor(sf::Color::White);
	}
}

sf::RectangleShape Line::getShape()
{
	return lineShape;
}
