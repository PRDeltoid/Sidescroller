#ifndef ENTITY_H
#define ENTITY_H

#include "animated_spritesheet.cpp"
#include "JSONDoc.hpp"

struct Pos {
    int x_;
    int y_;
};

enum Facing {
    LEFT = 5,
    RIGHT = 10
};

class Entity {
public:
    Entity(int, int, string);
    ~Entity();
    virtual void update(int);
    Pos get_pos();
    void set_pos(int, int);
    void set_pos(Pos);
    sf::RectangleShape* get_sprite();
    void set_facing(Facing);
    virtual void load_json(string);
protected:
    AnimatedSpritesheet* spritesheet_;
    int x_;
    int y_;
    Facing facing_;
    JSONDoc* entity_json_;
};

#endif
