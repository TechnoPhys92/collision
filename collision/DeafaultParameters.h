#pragma once
#include <SFML/Graphics.hpp>

class DeafaultParameters
{
private:

public:
	DeafaultParameters(int weight, sf::Vector2f pos);
	bool _falling = true;
	bool _moving = false;
	int _weight;
	sf::Vector2f _pos;
};

