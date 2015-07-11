#include "tileset.hpp"

Tileset::Tileset(string tileset_json, int w, int h) : 
    Spritesheet(tileset_json) 
{
    init(w, h);
}

void Tileset::init(int w, int h) {
    sprite_width_ = w;
    sprite_height_ = h;
    sprite_->setSize(sf::Vector2f(sprite_width_, sprite_height_));
}

