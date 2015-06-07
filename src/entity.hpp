#ifndef ENTITY_H
#define ENTITY_H

#include "spritesheet.cpp"

struct Pos {
    int x_;
    int y_;
};

class Entity {
public:
    Entity(int, int);
    ~Entity();
    void update();
    Pos get_pos();
    void set_pos(int, int);
    void set_pos(Pos);
    sf::RectangleShape* get_sprite();
private:
    Spritesheet* spritesheet_;
    int x_;
    int y_;
};

#endif