#include "Sticker.h"

std::string Sticker::intToStr(int num)
{
	std::string str;



	return str;
}

Sticker::Sticker(int positionX, int positionY, int id)
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
	this->sticker.setOutlineThickness(2);
	outLineColor = color;
	outLineColor.g = outLineColor.g - 50;
	this->sticker.setOutlineColor(outLineColor);
	std::string str = "";
	font.loadFromFile("C:/Windows/Fonts/CascadiaMono.ttf");
	//path = "..\\data\\" + id + ".txt";
}

void Sticker::create()
{
}

void Sticker::edit()
{
	sf::RenderWindow sticker(sf::VideoMode(300, 300), "", sf::Style::Close);
	sticker.setFramerateLimit(60);
	text.setFont(font);
	text.setCharacterSize(18);
	text.setPosition(0, 0);
	text.setFillColor(sf::Color::Black);

	sf::Text carriage;
	carriage.setFont(font);
	carriage.setFillColor(sf::Color::Black);
	carriage.setCharacterSize(text.getCharacterSize());

	std::ofstream out{ path };

	int strSize = 0;
	int carriageStr = 0;
	// двумерный массив 14 на 27
	//int** strSize = new int*;
	//for (int i=0;i<)

	while (sticker.isOpen())
	{
		carriage.setString("");
		sf::Event event;
		while (sticker.pollEvent(event))
		{
			if (event.key.code == sf::Keyboard::Escape ||
				event.type == sf::Event::Closed)
				sticker.close();
			if (event.type == sf::Event::TextEntered)
			{
				if (strSize >= 27)
				{
					textStr += "\n";
					carriageStr += 18;
					strSize = 0;
				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) // Delete key
				{
					textStr = textStr.substr(0, textStr.size() - 1);
					strSize--;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
				{
					textStr += "\n";
					carriageStr += 18;
					strSize = 0;
				}
				else if (event.text.unicode < 128)
				{
					textStr += static_cast<char>(event.text.unicode);
					strSize++;
				}
				text.setString(textStr);
			}
		}
		carriage.setPosition(strSize*(text.getCharacterSize()/1.66), carriageStr);
		if (time(NULL) % 2 == 0) carriage.setString("|");
		sticker.clear(sf::Color::Yellow);
		sticker.draw(text);
		sticker.draw(carriage);
		sticker.display();
	}
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
	rect->left = x;
	rect->top = y;
}

void Sticker::setPosition(sf::Vector2i vector)
{
	positionX = vector.x;
	positionY = vector.y;
	sticker.setPosition(sf::Vector2f(positionX, positionY));
	rect->left = vector.x;
	rect->top = vector.y;
}

sf::Vector2i Sticker::getPosition()
{
	return sf::Vector2i(positionX, positionY);
}
