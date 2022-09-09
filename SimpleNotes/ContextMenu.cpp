#include "ContextMenu.h"

ContextMenu::ContextMenu(sf::Vector2i vector, int id)
{
	posX = vector.x;
	posY = vector.y;

	width = 100;
	height = lineCounter * 16;

	if (posX + width > 400)
	{
		posX = posX - width;
	}
	if (posY + height > 600)
	{
		posY = posY - height;
	}

	menu.setFillColor(sf::Color::White);
	menu.setPosition(posX, posY);
	menu.setSize(sf::Vector2f(width, height));

	lines = new Line[lineCounter];
	lines[0].create(L"Удалить", 0, lineCounter, menu.getGlobalBounds());
	lines[1].create(L"Изменить", 1, lineCounter, menu.getGlobalBounds());
	lines[2].create(L"Сменить цвет", 2, lineCounter, menu.getGlobalBounds());

	this->id = id;
}

ContextMenu::~ContextMenu()
{
	delete[]lines;
}

sf::RectangleShape ContextMenu::getMenu()
{
	return menu;
}

int ContextMenu::contain(sf::Vector2i coord)
{
	float x = coord.x, y = coord.y;
	for (int i = 0; i < lineCounter; i++)
	{
		if (lines[i].getLine().contains(x, y)) return i;
	}
	return -1;
}

int ContextMenu::getId()
{
	return id;
}

sf::RectangleShape* ContextMenu::getShape()
{
	sf::RectangleShape* shapes = new sf::RectangleShape[lineCounter];
	for (int i = 0; i < lineCounter; i++)
	{
		shapes[i] = lines[i].getShape();
	}
	return shapes;
}

void ContextMenu::setColor(int id, bool flag)
{
	lines[id].setColor(flag);
}

sf::Text* ContextMenu::getText()
{
	sf::Text* texts = new sf::Text[lineCounter];
	for (int i = 0; i < lineCounter; i++)
	{
		texts[i] = lines[i].getText();
	}
	return texts;
}

int ContextMenu::getCounter()
{
	return lineCounter;
}

void ContextMenu::setPos(sf::Vector2i vector, int id)
{
	posX = vector.x;
	posY = vector.y;

	if (posX + width > 400)
	{
		posX = posX - width;
	}
	if (posY + height > 600)
	{
		posY = posY - height;
	}

	menu.setPosition(posX, posY);

	for (int i = 0; i < lineCounter; i++)
	{
		lines[i].setPos(vector);
	}

	this->id = id;
}
