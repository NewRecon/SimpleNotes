#pragma once
#include "Sticker.h"
#include "Plus.h"
#include "Trash.h"
#include <iostream>
#include <memory>
class SimpleNotes
{
private:
	sf::RenderWindow window;
	sf::Texture backgroundTexture;
	sf::RectangleShape background;
	Plus plus;
	Trash trash;
	Sticker* stickers = nullptr;
	void evenState();
	void update();
	void render();
	bool setTransparency(HWND hWnd, unsigned char alpha);
public:
	SimpleNotes();
	void run();
	void addSticker();
};