#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class CoordAxes
{
private:
	RectangleShape _shape;
public:
	CoordAxes(Vector2f pos, Vector2f size);
	RectangleShape getShape();
	void draw(RenderTarget& window);
};

