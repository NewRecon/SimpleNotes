#include "SimpleNotes.h"

void SimpleNotes::evenState()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (plus.contain(sf::Mouse::getPosition(window)))
			{
				std::cout << "+" << std::endl;
				//addSticker();
			}
			if (trash.contain(sf::Mouse::getPosition(window)))
			{
				std::cout << "-" << std::endl;
			}
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left)){}
		}
	}
}

void SimpleNotes::update()
{
	
}

void SimpleNotes::render()
{
	window.clear(sf::Color::Transparent);
	window.draw(background);
	window.draw(plus.getButton());
	window.draw(trash.getButton());
	window.display();
}

bool SimpleNotes::setTransparency(HWND hWnd, unsigned char alpha)
{
	SetWindowLong(hWnd, GWL_EXSTYLE, GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	SetLayeredWindowAttributes(hWnd, 0, alpha, LWA_ALPHA);
	return true;
}

SimpleNotes::SimpleNotes() : window(sf::VideoMode(400, 600), "Simpe notes", sf::Style::Close)
{
	const unsigned char opacity = 150;
	setTransparency(window.getSystemHandle(), opacity);
	this->background.setSize(sf::Vector2f(400, 600));
	this->backgroundTexture.loadFromFile("..\\textures\\589cc9be29be415a24740edb.png");
	background.setTexture(&backgroundTexture);
	window.setFramerateLimit(60);
}

void SimpleNotes::run()
{
	while (window.isOpen())
	{
		evenState();
		update();
		render();
	}
}

void SimpleNotes::addSticker()
{
	
}
