#include "TextMessage.h"

TextMessage::TextMessage(std::string str, int fontSize, Vector2f pos) : _str(str), _fontSize(fontSize), _pos(pos)
{
	_font.loadFromFile("fonts/Roboto-Italic.ttf");
	_text.setFont(_font);
	_text.setFillColor(Color::White);
	_text.setCharacterSize(_fontSize);
	_text.setString(_str);
	_text.setPosition(_pos);
}

Vector2f TextMessage::getPosition()
{
	return _text.getPosition();
}

void TextMessage::setOrigionToCenter()
{
	_text.setOrigin(Vector2f(_text.getGlobalBounds().width / 2, _text.getGlobalBounds().height / 2));
}

void TextMessage::setPosition(Vector2f pos)
{
	_text.setPosition(pos);
}

void TextMessage::setSize(float size, Vector2f pos)
{
	float newSize = size * _fontSize;
	_text.setCharacterSize(newSize);
	_pos = pos;
	_text.setPosition(_pos);
}

void TextMessage::draw(RenderTarget& window)
{
	window.draw(_text);
}
