#ifndef GAME_H
#define GAME_H

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "entitylist.cpp"
#include "graphics.cpp"
#include "entity.cpp"
#include "player.cpp"
#include "input.cpp"
#include "map.cpp"
#include "camera.cpp"
#include <boost/scoped_ptr.hpp>

using sf::Time;
using sf::Event;
using boost::scoped_ptr;

const Time MS_PER_UPDATE = sf::milliseconds(17);

class Game
{
    public:
        Game();
        ~Game() {};
        void Loop();
    private:
        shared_ptr<Window> window_;
        shared_ptr<Graphics> graphics_;
        scoped_ptr<Input> input_;
        shared_ptr<Map> map_;
        scoped_ptr<Camera> camera_;
};

#endif
