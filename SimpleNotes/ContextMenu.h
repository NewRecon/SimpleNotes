#pragma once
#include "SFML/Graphics.hpp"
#include "Line.h"
class ContextMenu
{
	int id;
	sf::RectangleShape menu;

	int posX;
	int posY;

	int width;
	int height;

	Line* lines = nullptr;
	int lineCounter = 3;

public:
	ContextMenu(sf::Vector2i vector, int id);
	~ContextMenu();
	sf::RectangleShape getMenu();
	void setPos(sf::Vector2i vector, int id);
	int contain(sf::Vector2i coord);
	int getId();
	sf::Text* getText();
	sf::RectangleShape* getShape();
	int getCounter();
	void setColor(int id, bool flag);
};