#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <streambuf>
#include <fstream>
#include <json/json.h>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Spritesheet {
public:
    Spritesheet();
    ~Spritesheet() {}
    sf::RectangleShape* get_sprite() { return sprite_; }
    void update_sprite();
    void next_sprite();
    void set_spritesheet(string);
    void parse_json(string json_file);
    void get_clip_rects(Json::Value frame_json);
private:
    sf::RectangleShape* sprite_;
    int current_sprite_;
    int total_sprites_;
    sf::Texture* spritesheet_;
    sf::Image spritesheet_image_;
    vector< sf::Rect<int> > clip_rects_;

};

#endif
