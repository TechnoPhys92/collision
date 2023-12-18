#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class TextMessage
{
private:
	Font _font;
	Text _text;
	std::string _str;
	float _fontSize;
	Vector2f _pos;
public:
	TextMessage(std::string str, int fontSize, Vector2f pos);
	Vector2f getPosition();
	void setOrigionToCenter();
	void setPosition(Vector2f pos);
	void setSize(float size, Vector2f pos);
	void draw(RenderTarget& window);
};

