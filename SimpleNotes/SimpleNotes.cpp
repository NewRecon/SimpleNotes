#include "SimpleNotes.h"

void SimpleNotes::evenState()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		//LMB
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (plus.contain(sf::Mouse::getPosition(window)))
			{
				if (stickerCounter < 9)
				{
					std::cout << "+" << std::endl;
					addSticker();
				}
			}

			// Удаление при нажатии на корзину и стикер
			//if (trash.contain(sf::Mouse::getPosition(window)))
			//{
			//	std::cout << "-" << std::endl;
			//	bool del = true;
			//	while (del)
			//	{
			//		std::cout << "del";
			//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) del = false;
			//	}
			//}
			for (int i = 0; i < stickerCounter; i++)
			{
				if (stickers[i].contain(sf::Mouse::getPosition(window)))
				{
					int deltaX = sf::Mouse::getPosition().x - stickers[i].getPosition().x;
					int deltaY = sf::Mouse::getPosition().y - stickers[i].getPosition().y;

					while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						stickers[i].setPosition(
							sf::Mouse::getPosition().x - deltaX,
							sf::Mouse::getPosition().y - deltaY);
						render();
					}
					break;
				}
			}
			while (sf::Mouse::isButtonPressed(sf::Mouse::Left)){}
		}

		//RMB
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			for (int i = 0; i < stickerCounter; i++)
			{
				if (stickers[i].contain(sf::Mouse::getPosition(window)))
				{
					std::cout << "del" << std::endl;
				}
			}

			while (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {}
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
	for (int i = 0; i < stickerCounter; i++)
	{
		window.draw(stickers[i].getSticker());
	}
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

void SimpleNotes::addSticker()
{
	int posX=10, posY=10;
	Sticker sticker(posX, posY);

	//texture.loadFromFile("..\\textures\\png-clipart-yellow-sticky-note-post-it-note-paper-drawing-pin-post-rectangle-pin.png");
	//sticker.getSticker().setTexture(&texture);

	
	if (stickerCounter > 0)
	{
		for (int i = 0; i < stickerCounter; i++)
		{
			while (sticker.getRect().intersects(stickers[i].getRect()))
			{
				if (sticker.getPosition().x + 120 + 130 < 400)
				{
					posX += 130;
				}
				else
				{
					posX = 10;
					posY += 130;
				}
				for (int y = 0; y < stickerCounter; y++)
				{
					sticker.getRect().intersects(stickers[y].getRect());
				}
				sticker.setPosition(posX, posY);
			}
		}
	}

	if (stickers == nullptr) stickers = new Sticker[stickerCounter];
	stickerCounter++;
	Sticker* buf = new Sticker[stickerCounter];
	for (int i = 0; i < stickerCounter - 1; i++)
	{
		buf[i] = stickers[i];
	}
	buf[stickerCounter - 1] = sticker;
	delete[]stickers;
	stickers = buf;
}

void SimpleNotes::deleteSticker()
{

}

SimpleNotes::SimpleNotes() : window(sf::VideoMode(400, 600), "Simpe notes", sf::Style::Close)
{
	const unsigned char opacity = 150;
	//setTransparency(window.getSystemHandle(), opacity);
	this->background.setSize(sf::Vector2f(400, 600));
	this->backgroundTexture.loadFromFile("..\\textures\\589cc9be29be415a24740edb.png");
	background.setTexture(&backgroundTexture);
	window.setFramerateLimit(60);
}

SimpleNotes::~SimpleNotes()
{
	delete[]stickers;
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