#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "window.hpp"
#include "graphics.cpp"
#include "entity.cpp"

using sf::Time;
using sf::Event;

const Time MS_PER_UPDATE = sf::milliseconds(60);

class Game
{
    public:
        Game();
        ~Game();
        void Loop();
        void Init();
    private:
        Window* window_;
        Graphics* graphics_;
        boost::scoped_ptr<Graphics> graphics_;
};

#endif
