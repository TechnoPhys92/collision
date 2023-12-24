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
	TextMessage* _input;
	TextMessage* _playerInput;
	bool _start = false;
	bool _timer = false;
	float _elapsedTime = 0.0;

public:
	PauseMenu();
	~PauseMenu();
	bool getStart();
	void reset();
	void draw(RenderTarget& window);
	void update(Vector2i mousePos, Time dt, int input);
	void textUpdate(Event event);
	int getInput();
	RectangleShape getShape();
};

