#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class TextMessage
{
private:
	Font _font;
	Text _text;
	String _string;
	std::string _str;
	float _fontSize;
	Vector2f _pos;
	int _input = 0;

	bool isNumber(const std::string& s);

public:
	TextMessage(std::string str, int fontSize, Vector2f pos);
	Vector2f getPosition();
	void setOrigionToCenter();
	void setPosition(Vector2f pos);
	void setSize(float size, Vector2f pos);
	void inputMessage(Event event);
	void deleteChar();
	void setText(std::string str);
	std::string getText();
	int getInput();
	void draw(RenderTarget& window);
};

