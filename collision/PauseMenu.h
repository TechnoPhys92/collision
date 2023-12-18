#pragma once
#include <SFML/Graphics.hpp>
#include "TextMessage.h"
#include <thread>

using namespace sf;
using namespace std::literals;

class PauseMenu
{
private:
	RectangleShape _shape;
	Vector2f _pos;
	TextMessage* _text;
	bool _start = false;

public:
	PauseMenu();
	~PauseMenu();
	bool getStart();
	void draw(RenderTarget& window);
	void update(Vector2i mousePos);
	RectangleShape getShape();
};

