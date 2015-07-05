#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SFML\Graphics.hpp>
#include "window.hpp"
#include "entitylist.cpp"

class Graphics {
    public:
        Graphics(shared_ptr<Window> window);
        ~Graphics() {};
        void render();
        void set_entity_list(shared_ptr<EntityList>);

    private:
        shared_ptr<Window> window_;
        shared_ptr<EntityList> entity_list_;
        void draw();
        void clear();
        void display();
};

#endif
