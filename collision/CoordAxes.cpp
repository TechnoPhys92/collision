#include "CoordAxes.h"

CoordAxes::CoordAxes(Vector2f pos, Vector2f size)
{
	_shape.setSize(size);
	_shape.setFillColor(Color::White);
	_shape.setPosition(pos);
}

RectangleShape CoordAxes::getShape()
{
	return _shape;
}

void CoordAxes::draw(RenderTarget& window)
{
	window.draw(_shape);
}
