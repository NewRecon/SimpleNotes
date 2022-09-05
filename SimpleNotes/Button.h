#pragma once
#include "SFML/Graphics.hpp"
#include <string>
class Button
{
protected:
	sf::Rect<float>* rect;
	//std::string text;
	//sf::Font font;
	float height;
	float width;
	int positionX;
	int positionY;
	bool status;
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