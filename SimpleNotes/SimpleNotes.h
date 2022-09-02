#pragma once
#include "Sticker.h"
#include "Plus.h"
#include "Trash.h"
#include <iostream>
class SimpleNotes
{
private:
	sf::RenderWindow window;
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	Plus plus;
	Trash trash;
	Sticker* stickers = nullptr;
	sf::Text* stickersText = nullptr;

	sf::Font font; // для мини текста

	int stickerCounter = 0;
	void evenState();
	void update();
	void render();
	bool setTransparency(HWND hWnd, unsigned char alpha);
	void addSticker();
	void deleteSticker(int id);
	void edit(int id);
	void addText(int id);
	void delText(int id);
public:
	SimpleNotes();
	~SimpleNotes();
	void run();
};