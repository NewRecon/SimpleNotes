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
			sf::Cursor cursor;
			if (plus.contain(sf::Mouse::getPosition(window)))
			{
				if (addSticker())
				{
					addText(stickerCounter-1);
					std::cout << stickerCounter << std::endl;
				}
			}

			// Удаление при нажатии на корзину и стикер
			if (trash.contain(sf::Mouse::getPosition(window)) && stickerCounter>0)
			{
				bool del = true; 
				cursor.loadFromSystem(sf::Cursor::Hand);
				window.setMouseCursor(cursor);
				while (del)
				{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ||
						sf::Mouse::isButtonPressed(sf::Mouse::Right))
						del = false;

					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
					{
						while (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
						{
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								for (int i = stickerCounter - 1; i >= 0; i--)
								{
									if (stickers[i].contain(sf::Mouse::getPosition(window)))
									{
										deleteSticker(i);
										delText(i);
										stickerCounter--;
										render();
										break;
									}
								}
							}
						}
						del = false;
					}

					else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						for (int i = stickerCounter-1; i >= 0; i--)
						{
							if (stickers[i].contain(sf::Mouse::getPosition(window)))
							{
								deleteSticker(i);
								delText(i);
								stickerCounter--;
								del = false;
								break;
							}
						}
						while (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {}
					}
				}
				cursor.loadFromSystem(sf::Cursor::Arrow);
				window.setMouseCursor(cursor);
			}
			else if (stickerCounter)
			{
				for (int i = stickerCounter-1; i >= 0; i--)
				{
					if (stickers[i].contain(sf::Mouse::getPosition(window)))
					{
						int deltaX = sf::Mouse::getPosition().x - stickers[i].getPosition().x;
						int deltaY = sf::Mouse::getPosition().y - stickers[i].getPosition().y;

						int x = sf::Mouse::getPosition().x;
						int y = sf::Mouse::getPosition().y;

						while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							cursor.loadFromSystem(sf::Cursor::Hand);
							window.setMouseCursor(cursor);
							stickers[i].setPosition(
								sf::Mouse::getPosition().x - deltaX,
								sf::Mouse::getPosition().y - deltaY);
							stickersText[i].setPosition(
								(sf::Mouse::getPosition().x - deltaX) + 8,
								(sf::Mouse::getPosition().y - deltaY) + 2);
							if (trash.contain(sf::Mouse::getPosition(window)))
							{
								trash.setTexture("..\\textures\\1-trash-cat_icon-icons.com_76677.png");
								trash.setColor(sf::Color(255, 255, 255, 255));
							}
							else
							{
								trash.setTexture("..\\textures\\Childish-Cross_24996.png");
								trash.setColor(sf::Color::Red);
							}
							render();
						}
						cursor.loadFromSystem(sf::Cursor::Arrow);
						window.setMouseCursor(cursor);
						trash.setTexture("..\\textures\\Childish-Cross_24996.png");
						trash.setColor(sf::Color::Red);
						if (trash.contain(sf::Mouse::getPosition(window)))
						{
							deleteSticker(i);
							delText(i);
							stickerCounter--;
						}
						else if (sf::Mouse::getPosition().x == x &&
							sf::Mouse::getPosition().y == y)
						{
							edit(i);
							// отображение мини текста
							stickersText[i].setString(stickers[i].getStr());
						}
						break;
					}
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
		window.draw(stickersText[i]);
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

bool SimpleNotes::addSticker()
{
	int posX=10, posY=10;
	Sticker sticker(posX, posY, stickerCounter);
	
	bool flag = false;
	
	if (stickerCounter > 0)
	{
		int count = 0;
		while (count != stickerCounter)
		{
			count = 0;
			for (int i = 0; i < stickerCounter; i++)
			{
				while (sticker.getRect().intersects(stickers[i].getRect()) ||
					sticker.getRect().intersects(plus.getRect()) ||
					sticker.getRect().intersects(trash.getRect()))
				{
					count--;
					if (sticker.getPosition().x + 120 + 130 < 400)
					{
						posX += 120;
					}
					else if (sticker.getPosition().y + 130 < 600)
					{
						posX = 10;
						posY += 120;
					}
					else
					{
						flag = true;
						break;
					}
					sticker.setPosition(posX, posY);
				}
				if (flag) break;
				count++;
			}
			if (flag) break;
		}
	}

	if (!flag)
	{
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
		return true;
	}
	else return false;
}

void SimpleNotes::deleteSticker(int id)
{
	Sticker* buf = new Sticker[stickerCounter-1];
	for (int i = 0; i < id; i++)
	{
		buf[i] = stickers[i];
	}
	for (int i = id+1, j=id; i < stickerCounter; i++)
	{
		buf[j++] = stickers[i];
	}
	delete[] stickers;
	stickers = buf;
}

void SimpleNotes::edit(int id)
{
	stickers[id].edit();
}

void SimpleNotes::addText(int id)
{
	sf::Text text;
	text.setPosition(stickers[id].getRect().left, stickers[id].getRect().top);
	text.setFont(font);
	text.setCharacterSize(7);
	text.setString("");
	text.setFillColor(sf::Color::Black);

	if (stickersText == nullptr)
		stickersText = new sf::Text[0];
	sf::Text* buf = new sf::Text[stickerCounter];
	for (int i = 0; i < stickerCounter - 1; i++)
	{
		buf[i] = stickersText[i];
	}
	buf[stickerCounter - 1] = text;
	delete[] stickersText;
	stickersText = buf;
}

SimpleNotes::SimpleNotes() : window(sf::VideoMode(400, 600), L"Simple notes ©NewRecon", sf::Style::Close)
{
	const unsigned char opacity = 200;
	//setTransparency(window.getSystemHandle(), opacity);
	this->background.setSize(sf::Vector2f(400, 600));
	this->backgroundTexture.loadFromFile("..\\textures\\kisspng-hardwood-wood-stain-varnish-wall-floor-wood-textures-5a811df69cb278.8835756915184112546418.png");
	background.setTexture(&backgroundTexture);
	window.setFramerateLimit(60);

	font.loadFromFile("C:/Windows/Fonts/CascadiaMono.ttf");
}

void SimpleNotes::delText(int id)
{
	sf::Text* buf = new sf::Text[stickerCounter-1];
	for (int i = 0; i < id; i++)
	{
		buf[i] = stickersText[i];
	}
	for (int i = id + 1, j = id; i < stickerCounter; i++)
	{
		buf[j++] = stickersText[i];
	}
	delete[] stickersText;
	stickersText = buf;
}

SimpleNotes::~SimpleNotes()
{
	delete[]stickers;
	delete[]stickersText;
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