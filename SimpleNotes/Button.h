#pragma once
#include "SFML/Graphics.hpp"
#include <string>
class Button
{
protected:
	sf::Rect<float>* rect;
	float height;
	float width;
	int positionX;
	int positionY;
	sf::RectangleShape button;
	sf::Color color;
	sf::Texture texture;
public:
	Button(){}
	sf::RectangleShape getButton();
	bool contain(sf::Vector2i coord);
	void setTexture(std::string path);
	void setColor(sf::Color color);
	sf::Rect<float> getRect();
};