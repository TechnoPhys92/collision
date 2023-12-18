#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
	_shape.setSize(Vector2f{ 256, 128 });
	_shape.setPosition(Vector2f{ 640 - 128, 384 - 64 });
	_shape.setOutlineThickness(1);
	_shape.setFillColor(Color::Black);
	_text = new TextMessage("start", 32, Vector2f{ 640, 480 });
	_text->setOrigionToCenter();
}

PauseMenu::~PauseMenu()
{
	delete _text;
}

bool PauseMenu::getStart()
{
	return _start;
}

void PauseMenu::setStartFalse()
{
	_start = false;
}

void PauseMenu::draw(RenderTarget& window)
{
	window.draw(_shape);
	_text->draw(window);
}

void PauseMenu::update(Vector2i mousePos)
{
	if (Mouse::isButtonPressed(Mouse::Left) && _shape.getGlobalBounds().contains(Vector2f(mousePos)))
	{
		_shape.setSize(Vector2f{ 256 * 0.9, 128 * 0.9 });
		_shape.setPosition(Vector2f{ 640 - 256 * 0.45, 384 - 128 * 0.45 });
		_text->setSize(0.9, Vector2f{ 640, 385 });
		std::this_thread::sleep_for(0.5s);
		_start = true;
	}
	else
	{
		_shape.setSize(Vector2f{ 256, 128 });
		_shape.setPosition(Vector2f{ 640 - 128, 384 - 64 });
		_text->setSize(1, Vector2f{ 640, 384 });
	}
}

RectangleShape PauseMenu::getShape()
{
	return _shape;
}
