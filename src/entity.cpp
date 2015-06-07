#include "entity.hpp"

Entity::Entity(int x, int y) :
    x_(x),
    y_(y)
{
    spritesheet_ = new Spritesheet(); 
}

Entity::~Entity() {
    delete spritesheet_;
}

void Entity::update() {
    spritesheet_->update_sprite();
}

Pos Entity::get_pos() {
    Pos pos;
    pos.x_ = x_;
    pos.y_ = y_;
    return pos;
}

void Entity::set_pos(int x, int y) {
    x_ = x;
    y_ = y;
}

void Entity::set_pos(Pos pos) {
    x_ = pos.x_;
    y_ = pos.y_;
}

sf::RectangleShape* Entity::get_sprite() {
    return spritesheet_->get_sprite();
}
