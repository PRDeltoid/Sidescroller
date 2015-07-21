#ifndef ENTITY_H
#define ENTITY_H

#include "animated_spritesheet.cpp"
#include "JSONDoc.hpp"
#include <boost/scoped_ptr.hpp>

using boost::scoped_ptr;

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
    virtual void update(int);
    Pos get_pos();
    void set_pos(int, int);
    void set_pos(Pos);
    shared_ptr<sf::RectangleShape> get_sprite();
    void set_facing(Facing);
    virtual void load_json(string);
protected:
    scoped_ptr<AnimatedSpritesheet> spritesheet_;
    int x_;
    int y_;
    Facing facing_;
    scoped_ptr<JSONDoc> entity_json_;
};

#endif
