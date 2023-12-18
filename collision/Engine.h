#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Rects.h"
#include "CoordAxes.h"
#include "State.h"
#include "PauseMenu.h"

class Engine
{
private:
	State _state = State::Pause;
	sf::RenderWindow _window;
	PauseMenu _pauseMenu;
	Rects* _rect;
	Rects* _otherRect;
	
	CoordAxes* X;
	CoordAxes* Y;

	void update(sf::Time dt);
	void draw();

public:
	Engine();
	~Engine();
	void run();
};

