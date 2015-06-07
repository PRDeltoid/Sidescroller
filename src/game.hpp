#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "window.hpp"
#include "graphics.cpp"
#include "entity.cpp"

const sf::Time MS_PER_UPDATE = sf::milliseconds(60);

class Game
{
    public:
        Game() {};
        ~Game() {};
        void Loop();
        void Init();
    private:
        Window* window_;
        Graphics* graphics_;
};

#endif
