#include "entity.hpp"

Entity::Entity(int x, int y, string json) :
    x_(x),
    y_(y)
{
    load_json(json);

    string spritesheet = entity_json_->get("spritesheets")[0].asString();
    spritesheet_.reset(new AnimatedSpritesheet(spritesheet)); 
    string starting_animation = entity_json_->get("starting_animation").asString();
    spritesheet_->set_animation(starting_animation);
}

void Entity::update(int elapsed_time) {
    spritesheet_->update_sprite(elapsed_time);
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

shared_ptr<sf::RectangleShape> Entity::get_sprite() {
    shared_ptr<sf::RectangleShape> sprite = spritesheet_->get_sprite();
    sprite->setPosition(sf::Vector2f(x_, y_));
    if(facing_==RIGHT) {
        sprite->setScale(sf::Vector2f(1.0, 1));
    } else {
        sprite->setScale(sf::Vector2f(-1, 1));
    }
    return sprite;
}

void Entity::set_facing(Facing facing) {
    facing_ = facing;
}

void Entity::load_json(string json) {
    entity_json_.reset(new JSONDoc(json));
    x_ = entity_json_->get("x").asInt();
    y_ = entity_json_->get("y").asInt();
    //facing_ = 
    if(entity_json_->get("facing").asString() == "left") {
        facing_ = LEFT;
    } else {
        facing_ = RIGHT;
    }

}
