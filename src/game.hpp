#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "window.hpp"
#include "graphics.cpp"
#include "entity.cpp"
#include "../include/boost/scoped_ptr.hpp"

using sf::Time;
using sf::Event;
using boost::scoped_ptr;

const Time MS_PER_UPDATE = sf::milliseconds(60);

class Game
{
    public:
        Game();
        ~Game() {};
        void Loop();
    private:
        shared_ptr<Window> window_;
        scoped_ptr<Graphics> graphics_;
};

#endif
