#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SFML\Graphics.hpp>
#include "window.hpp"

class Graphics {
    public:
        Graphics(Window* window);
        ~Graphics() {};
        void initialize();
        void render();

    private:
        Window* window_;
        void draw();
        void clear();
        void display();
};

#endif
