#include "Trash.h"

Trash::Trash()
{
	this->radius = 40.f;
	this->positionX = 20;
	this->positionY = 500;
	this->color = sf::Color(0, 190, 255);
	this->button.setRadius(radius);
	this->button.setPosition(sf::Vector2f(positionX, positionY));
	this->button.setFillColor(color);
	this->button.setOutlineThickness(2);
	this->button.setOutlineColor(sf::Color(0, 140, 255));
	rect = new sf::Rect<float>(button.getGlobalBounds());
}

void Trash::push()
{

}