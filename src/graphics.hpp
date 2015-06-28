#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <SFML\Graphics.hpp>
#include "window.hpp"
#include "entitylist.cpp"

class Graphics {
    public:
        Graphics(Window* window);
        ~Graphics() {};
        void initialize();
        void render();
        void set_entity_list(EntityList*);

    private:
        Window* window_;
        EntityList* entity_list_;
        void draw();
        void clear();
        void display();
};

#endif
