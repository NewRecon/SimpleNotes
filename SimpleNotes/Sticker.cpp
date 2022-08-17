#include "Sticker.h"

Sticker::Sticker(int positionX, int positionY)
{
	this->positionX = positionX;
	this->positionY = positionY;
	sticker.setPosition(sf::Vector2f(positionX, positionY));
	sticker.setSize(sf::Vector2f(120, 120));
	rect = new sf::Rect<float>(sticker.getGlobalBounds());
	texture.loadFromFile("..\\textures\\png-clipart-yellow-sticky-note-post-it-note-paper-drawing-pin-post-rectangle-pin.png");
	sticker.setTexture(&texture);
	color = sf::Color::Yellow;
	sticker.setFillColor(color);
}

void Sticker::create()
{
}

void Sticker::edit()
{
}

sf::RectangleShape Sticker::getSticker()
{
	return sticker;
}

bool Sticker::contain(sf::Vector2i coord)
{
	float x = coord.x, y = coord.y;
	return rect->contains(x, y);
}

sf::Rect<float> Sticker::getRect()
{
	return *rect;
}

void Sticker::setPosition(int x, int y)
{
	positionX = x;
	positionY = y;
	sticker.setPosition(sf::Vector2f(positionX, positionY));
}
