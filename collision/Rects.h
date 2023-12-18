#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextMessage.h"
#include <thread>

using namespace sf;
using namespace std::literals;

class Rects
{
private:
	RectangleShape _shape;
	bool _falling = true;
	float _weight;
	float _speedY = 256.f;
	float _speedX;
	float _prevSpeed;
	TextMessage* _text;

public:
	Rects(float weight, Vector2f pos, float speedX);
	~Rects();
	RectangleShape getShape();
	void setToInit(int weight, Vector2f pos, float speed);
	int getWeight();
	float getSpeed();
	void setSpeed(Rects* other);
	void update(Time dt, RectangleShape X, RectangleShape Y, Rects* other);
	void draw(RenderTarget& window);
};

