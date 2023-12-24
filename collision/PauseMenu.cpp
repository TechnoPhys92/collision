#include "PauseMenu.h"

PauseMenu::PauseMenu()
{
	_shape.setSize(Vector2f{ 256, 128 });
	_shape.setPosition(Vector2f{ 640 - 128, 384 - 64 });
	_shape.setOutlineThickness(1);
	_shape.setFillColor(Color::Black);
	_text = new TextMessage("start", 32, Vector2f{ 640, 480 });
	_text->setOrigionToCenter();
	_input = new TextMessage("enter the mass of the second object:", 32, Vector2f{ 640, 200 });
	_input->setOrigionToCenter();
	_playerInput = new TextMessage("", 32, Vector2f{ 640, 232 });
}

PauseMenu::~PauseMenu()
{
	delete _text;
	delete _input;
	delete _playerInput;
}

bool PauseMenu::getStart()
{
	return _start;
}

void PauseMenu::reset()
{
	_start = false;
	_timer = false;
	_timer = 0.0;
	_playerInput->setText("");
}

void PauseMenu::draw(RenderTarget& window)
{
	window.draw(_shape);
	_text->draw(window);
	_input->draw(window);
	_playerInput->draw(window);
}

void PauseMenu::update(Vector2i mousePos, Time dt, int input)
{
	if (_timer)
	{
		_elapsedTime += dt.asSeconds();
		if (_elapsedTime >= 0.5)
		{
			_timer = false;
			_start = true;
			return;
		}
	}
	if (Mouse::isButtonPressed(Mouse::Left) && _shape.getGlobalBounds().contains(Vector2f(mousePos)))
	{
		_shape.setSize(Vector2f{ 256 * 0.9, 128 * 0.9 });
		_shape.setPosition(Vector2f{ 640 - 256 * 0.45, 384 - 128 * 0.45 });
		_text->setSize(0.9, Vector2f{ 640, 385 });
		if(!_timer && input != 0)
			_timer = true;
	}
	else
	{
		_shape.setSize(Vector2f{ 256, 128 });
		_shape.setPosition(Vector2f{ 640 - 128, 384 - 64 });
		_text->setSize(1, Vector2f{ 640, 384 });
	}
}

void PauseMenu::textUpdate(Event event)
{
	if (Keyboard::isKeyPressed(Keyboard::BackSpace) && _playerInput->getText().size() != 0)
	{
		_playerInput->deleteChar();
		return;
	}
	if (event.type == Event::TextEntered)
	{
		_playerInput->inputMessage(event);
	}
}

int PauseMenu::getInput()
{
	return _playerInput->getInput();
}

RectangleShape PauseMenu::getShape()
{
	return _shape;
}
