#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>
#include <string>
#include "JSONDoc.hpp"

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::map;
using std::pair;

class Spritesheet {
public:
    Spritesheet(string);
    ~Spritesheet() {}
    sf::RectangleShape* get_sprite() { return sprite_; }
    void update_sprite();
    void next_sprite();
    void set_spritesheet(string);
    void parse_json(string json_file);
    void get_clip_rects(Json::Value frame_json);
    void set_animation(string);
private:
    int sprite_width_;
    int sprite_height_;
    sf::RectangleShape* sprite_;
    int current_sprite_;
    int total_sprites_;
    sf::Texture* spritesheet_;
    sf::Image spritesheet_image_;
    vector< sf::Rect<int> > clip_rects_;
    pair <int, int> current_animation_;
    map <string, pair <int, int> > animations_;
};

#endif
