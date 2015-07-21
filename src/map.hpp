#ifndef MAP_H
#define MAP_H

#include "graphics.hpp"
#include "tileset.cpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include "JSONDoc.hpp"
#include "..\include\bitmap_image.hpp"

#define TILE_SIZE 64

#define MAP_SIZE 50

class Map {
public:
    Map() {}
    Map(string, string, string);
    void load(string);
    void parse(string);
    void draw(boost::shared_ptr<Graphics>);
    void move_map(int x, int y);

    sf::Color get_tile_color(int, int);
    uint32_t num_from_color(sf::Color);
private:
    int map_tiles[MAP_SIZE][MAP_SIZE];
    std::map< uint32_t, int> tiletypes_; //by color
    boost::scoped_ptr<JSONDoc> map_config_;
    boost::scoped_ptr<bitmap_image> map_bmp_;
    boost::scoped_ptr<Tileset> tileset_;
    int origin_x_;
    int origin_y_;
};

#endif
