#include "Plus.h"

Plus::Plus()
{
	this->radius = 40.f;
	this->positionX = 300;
	this->positionY = 500;
	this->color = sf::Color(255, 100, 71);
	this->button.setRadius(radius);
	this->button.setPosition(sf::Vector2f(positionX, positionY));
	this->button.setFillColor(color);
	this->button.setOutlineThickness(2);
	this->button.setOutlineColor(sf::Color(255, 50, 71));
	rect = new sf::Rect<float>(button.getGlobalBounds());
}

void Plus::push()
{
	
}