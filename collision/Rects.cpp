#include "Rects.h"

Rects::Rects(float weight, Vector2f pos, float speedX)
{
	_weight = weight;
	_shape.setOutlineThickness(1.f);
	_shape.setOutlineColor(Color::White);
	_shape.setFillColor(Color::Black);
	_shape.setSize(Vector2f(64, 64));
	_shape.setPosition(pos);
	_speedX = speedX;
	_prevSpeed = speedX;
	_text = new TextMessage{ std::to_string((int)_weight) + "kg", 16,  Vector2f{_shape.getPosition().x + _shape.getSize().x / 8, _shape.getPosition().y + _shape.getSize().y / 8} };
}

Rects::~Rects()
{
	delete _text;
}

RectangleShape Rects::getShape()
{
	return _shape;
}

void Rects::update(Time dt, RectangleShape X, RectangleShape Y, Rects* other)
{
	if (_falling)
	{
		float y = _speedY * dt.asSeconds() + _shape.getPosition().y;
		float y1 = _speedY * dt.asSeconds() + _text->getPosition().y;
		Vector2f pos1{ _text->getPosition().x, y1 };
		Vector2f pos{ _shape.getPosition().x, y };
		_shape.setPosition(pos);
		_text->setPosition(pos1);
		if (_shape.getGlobalBounds().intersects(X.getGlobalBounds()))
		{
			_falling = false;
			_shape.setPosition(Vector2f(_shape.getPosition().x, (X.getPosition().y - _shape.getSize().y)));
		}
	}
	if(!_falling)
	{
		_prevSpeed = _speedX;
		float x = _speedX * dt.asSeconds() + _shape.getPosition().x;
		float x1 = _speedX * dt.asSeconds() + _text->getPosition().x;
		
		Vector2f pos{ x, _shape.getPosition().y };
		Vector2f textPos{ x1, _text->getPosition().y };

		_shape.setPosition(pos);
		_text->setPosition(textPos);

		if (_shape.getGlobalBounds().intersects(Y.getGlobalBounds()))
		{
			_speedX = -_speedX;
		}
		if (_shape.getGlobalBounds().intersects(other->getShape().getGlobalBounds()))
		{
			setSpeed(other);
			other->setSpeed(this);
		}
	}
}

void Rects::draw(RenderTarget& window)
{
	window.draw(_shape);
	_text->draw(window);
}

int Rects::getWeight()
{
	return _weight;
}

float Rects::getSpeed()
{
	return _prevSpeed;
}

void Rects::setSpeed(Rects* other)
{
	float k1 = (_weight - other->getWeight()) / (other->getWeight() + _weight);
	float k2 = 2 * (other->getWeight() / (_weight + other->getWeight()));
	float new_speed;
	new_speed = k1 * _prevSpeed + k2 * other->getSpeed();
	_speedX = new_speed;
}

void Rects::setToInit(int weight, Vector2f pos, float speed)
{
	_prevSpeed = speed;
	_speedX = speed;
	_weight = weight;
	_shape.setPosition(pos);
	_falling = true;
	_text->setPosition(Vector2f{ _shape.getPosition().x + _shape.getSize().x / 8, _shape.getPosition().y + _shape.getSize().y / 8 });
}