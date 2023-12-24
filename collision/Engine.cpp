#include "Engine.h"

Engine::Engine()
{
	_window.create(sf::VideoMode(1280, 768), "Collision");
    _window.setFramerateLimit(60);
    _rect = new Rects(1, Vector2f(256, 200), 0);
    _otherRect = new Rects(16, Vector2f(512, 200), -128);
    X = new CoordAxes(Vector2f(128, 512), Vector2f(512, 1));
    Y = new CoordAxes(Vector2f(128, 64), Vector2f(1, 512));
    //_window.setKeyRepeatEnabled(false);
}

Engine::~Engine()
{
    delete X;
    delete Y;
    delete _rect;
    delete _otherRect;
}

void Engine::update(sf::Time dt)
{
    int input = _pauseMenu.getInput();
    if (_state == State::Play)
    {
        _otherRect->update(dt, X->getShape(), Y->getShape(), _rect);
        _rect->update(dt, X->getShape(), Y->getShape(), _otherRect);
    }
    if (_state == State::Pause)
    {
        Vector2i mousePos = Mouse::getPosition(_window);
        _pauseMenu.update(mousePos, dt, input);
        if (_pauseMenu.getStart())
        {
            _otherRect->setWeight(_pauseMenu.getInput());
            _state = State::Play;
        }
    }
}

void Engine::draw()
{
    _window.clear();
    if (_state == State::Play)
    {
        _rect->draw(_window);
        _otherRect->draw(_window);
        X->draw(_window);
        Y->draw(_window);
    }
    if (_state == State::Pause)
    {
        _pauseMenu.draw(_window);
    }
    _window.display();
    
}

void Engine::run()
{
    sf::Clock clock;
    while (_window.isOpen())
    {
        sf::Time dt;
        dt = clock.restart();
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                _window.close();
            
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Escape)
                {
                    _state = State::Pause;
                    _pauseMenu.reset();
                    _rect->setToInit(1, Vector2f(256, 200), 0);
                    _otherRect->setToInit(4, Vector2f(512, 200), -64);
                }
            }

            if (_state == State::Pause)
            {
                _pauseMenu.textUpdate(event);
            }
        }
        update(dt);
        draw();
    }
}
