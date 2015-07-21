#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SFML\Graphics.hpp>
#include "window.hpp"
#include <boost\shared_ptr.hpp>

using boost::shared_ptr;

class Graphics {
    public:
        Graphics(shared_ptr<Window>);
        ~Graphics() {};
        void draw(shared_ptr<sf::RectangleShape>);
        void clear();
        void display();

    private:
        shared_ptr<Window> window_;
};

#endif
