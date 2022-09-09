#include "Trash.h"

Trash::Trash()
{
	this->height = 60;
	this->width = 60;
	this->positionX = 20;
	this->positionY = 560;

	this->color = sf::Color::Red;

	this->button.setSize(sf::Vector2f(height, width));
	this->button.setPosition(sf::Vector2f(positionX, positionY));
	this->button.setFillColor(color);

	rect = new sf::Rect<float>(button.getGlobalBounds());

	texture.loadFromFile("..\\textures\\Childish-Cross_24996.png");
	button.setTexture(&texture);
}