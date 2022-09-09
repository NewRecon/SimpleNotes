#include "Sticker.h"

Sticker::Sticker(int positionX, int positionY, int id)
{
	this->positionX = positionX;
	this->positionY = positionY;

	sticker.setPosition(sf::Vector2f(positionX, positionY));
	sticker.setSize(sf::Vector2f(160, 160));

	rect = new sf::Rect<float>(sticker.getGlobalBounds());

	color = sf::Color::Yellow;
	sticker.setFillColor(color);

	font.loadFromFile("C:/Windows/Fonts/CascadiaMono.ttf");

	this->textureStick.loadFromFile("..\\textures\\Sticker.png");
	this->sticker.setTexture(&textureStick);
}

Sticker::Sticker(std::wstring textStr, int positionX, int positionY,
	int strSize[14], int str, int r, int g, int b)
{
	this->positionX = positionX;
	this->positionY = positionY;

	sticker.setPosition(sf::Vector2f(positionX, positionY));
	sticker.setSize(sf::Vector2f(160, 160));

	rect = new sf::Rect<float>(sticker.getGlobalBounds());

	color = sf::Color(r,g,b);
	sticker.setFillColor(color);

	font.loadFromFile("C:/Windows/Fonts/CascadiaMono.ttf");

	this->textureStick.loadFromFile("..\\textures\\Sticker.png");
	this->sticker.setTexture(&textureStick);

	this->textStr = textStr;
	text.setString(textStr);
	for (int i = 0; i < 14; i++)
	{
		this->strSize[i] = strSize[i];
	}
	this->str = str;

}

Sticker& Sticker::operator=(const Sticker& other)
{
	this->rect = other.rect;
	this->textStr = other.textStr;
	this->text = other.text;
	this->font = other.font;
	this->positionX = other.positionX;
	this->positionY = other.positionY;
	this->sticker = other.sticker;
	this->color = other.color;
	this->textureStick = other.textureStick;
	for (int i = 0; i < 14; i++)
	{
		this->strSize[i] = other.strSize[i];
	}
	this->str = other.str;

	sticker.setTexture(&textureStick);
	return *this;
}

void Sticker::edit()
{
	sf::RenderWindow sticker(sf::VideoMode(300, 300), "Sticker", sf::Style::Close);
	sticker.setFramerateLimit(60);
	text.setFont(font);
	text.setCharacterSize(18);
	text.setPosition(0, 0);
	text.setFillColor(sf::Color::Black);

	sf::Text carriage;
	carriage.setFont(font);
	carriage.setFillColor(sf::Color::Black);
	carriage.setCharacterSize(text.getCharacterSize());

	int carriageStr = str * 21;

	//номер буквы strSize[str]

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
				if (event.text.unicode == 8)
				{
					if (str > 0 || strSize[str] > 0)
					{
						textStr.erase(textStr.size() - 1);
						if (strSize[str] > 0) strSize[str]--;
						else str--;
					}
				}
				else if (event.text.unicode == 13)
				{
					if (str < 13)
					{
						textStr += '\n';
						str++;
					}
				}
				else
				{
					if (strSize[str] == 27 && str<13)
					{
						textStr += '\n';
						str++;
					}
					if (strSize[str] < 27)
					{
						textStr += static_cast<wchar_t>(event.text.unicode);
						strSize[str]++;
					}
				}

				text.setString(textStr);
				carriageStr = str * 21;
			}
		}
		carriage.setPosition(strSize[str]*(text.getCharacterSize()/1.66), carriageStr);
		if (time(NULL) % 2 == 0) carriage.setString("|");
		sticker.clear(color);
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

sf::Text Sticker::getText()
{
	return text;
}

std::wstring Sticker::getStr()
{
	return textStr;
}

void Sticker::save()
{
	json j;
	std::ofstream out { path,std::ofstream::app };

	j["textStr"] = textStr;
	j["positionX"] = positionX;
	j["positionY"] = positionY;
	j["strSize"] = strSize;
	j["str"] = str;
	j["colorR"] = color.r;
	j["colorG"] = color.g;
	j["colorB"] = color.b;

	out << j << '\n';

	out.close();
}

void Sticker::changeColor()
{
	if (color == sf::Color::Yellow) color = sf::Color(173, 255, 47);
	else if (color == sf::Color(173, 255, 47)) color = sf::Color(135, 206, 235);
	else if (color == sf::Color(135, 206, 235)) color = sf::Color(255, 192, 203);
	else if (color == sf::Color(255, 192, 203)) color = sf::Color::White;
	else if (color == sf::Color::White) color = sf::Color::Yellow;

	sticker.setFillColor(color);
}
