#pragma once
#include "SFML/Graphics.hpp"
#include <string>
class Button
{
protected:
	sf::Rect<float>* rect;
	std::string text;
	sf::Font font;
	float radius;
	int positionX;
	int positionY;
	bool status;
	sf::CircleShape button;
	sf::Color color;
	sf::Texture texture;
public:
	Button();
	virtual void push() = 0;
	sf::CircleShape getButton();
	bool contain(sf::Vector2i coord);
};