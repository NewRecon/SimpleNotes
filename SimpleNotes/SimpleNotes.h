#pragma once
#include "Sticker.h"
#include "Plus.h"
#include "Trash.h"
#include <iostream>

#include <nlohmann/json.hpp>
#include <fstream>

#include "ContextMenu.h"
using namespace nlohmann;

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
	sf::Font font;

	std::string path = "file.json";
	int strSize[14] = {}; //для чтения из файла

	ContextMenu* contMenu = nullptr;
	int stickerCounter = 0;
	bool menu = false; // Если есть меню, то отрисовать его

	void evenState();
	void render();
	bool addSticker();
	Sticker loadSticker(json& j);
	void deleteSticker(int id);
	void edit(int id);
	void addText(int id);
	sf::Text loadText(int id);
	void delText(int id);
public:
	SimpleNotes();
	~SimpleNotes();
	void run();
};