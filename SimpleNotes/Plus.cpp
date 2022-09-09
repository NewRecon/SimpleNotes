#include "Plus.h"

Plus::Plus()
{
	this->height = 60;
	this->width = 60;
	this->positionX = 400;
	this->positionY = 560;

	this->color = sf::Color::Green;

	this->button.setSize(sf::Vector2f(height, width));
	this->button.setPosition(sf::Vector2f(positionX, positionY));
	this->button.setFillColor(color);

	rect = new sf::Rect<float>(button.getGlobalBounds());

	texture.loadFromFile("..\\textures\\Childish-Plus_24969.png");
	button.setTexture(&texture);
}