#include "TextMessage.h"

bool TextMessage::isNumber(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

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

void TextMessage::inputMessage(Event event)
{
	_string += event.text.unicode;
	std::string str = _string;

	if(isNumber(str))
		_input = std::stoi(str);

	_text.setString(_string);
	setOrigionToCenter();
}

void TextMessage::deleteChar()
{
	_string.erase(_string.getSize() - 1, 1);
	_text.setString(_string);
}

void TextMessage::setText(std::string str)
{
	_string = str;
	_text.setString(_string);
}

std::string TextMessage::getText()
{
	return _string;
}

int TextMessage::getInput()
{
	return _input;
}

void TextMessage::draw(RenderTarget& window)
{
	window.draw(_text);
}
