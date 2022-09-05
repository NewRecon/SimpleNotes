#include "Button.h"

sf::RectangleShape Button::getButton()
{
	return this->button;
}

bool Button::contain(sf::Vector2i coord)
{
	float x = coord.x, y = coord.y;
	return rect->contains(x, y);
}

void Button::setTexture(std::string path)
{
	this->texture.loadFromFile(path);
	this->button.setTexture(&texture);
}

void Button::setColor(sf::Color color)
{
	this->color = color;
	this->button.setFillColor(color);
}

sf::Rect<float> Button::getRect()
{
	return *rect;
}

