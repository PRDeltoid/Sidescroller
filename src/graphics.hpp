#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SFML\Graphics.hpp>
#include "window.hpp"

class Graphics {
    public:
        Graphics(shared_ptr<Window>);
        ~Graphics() {};
        void draw(sf::RectangleShape*);
        void clear();
        void display();

    private:
        shared_ptr<Window> window_;
};

#endif
