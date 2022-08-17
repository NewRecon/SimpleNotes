#include "Button.h"

Button::Button()
{

}

sf::CircleShape Button::getButton()
{
	return this->button;
}

bool Button::contain(sf::Vector2i coord)
{
	float x = coord.x, y = coord.y;
	return rect->contains(x, y);
}

