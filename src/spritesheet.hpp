#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <vector>
#include <utility>
#include <SFML/Graphics.hpp>
#include <string>
#include "JSONDoc.hpp"
#include <boost/shared_ptr.hpp>


using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using boost::shared_ptr;

class Spritesheet {
public:
    Spritesheet(string);
    virtual void init(string);
    virtual shared_ptr<sf::RectangleShape> get_sprite(int);
    void set_spritesheet(string);
    virtual void parse_json(string json_file);
    virtual void get_clip_rects(Json::Value frame_json);
protected:
    int sprite_width_;
    int sprite_height_;
    shared_ptr<sf::RectangleShape> sprite_;
    int current_sprite_;
    int total_sprites_;
    shared_ptr<sf::Texture> spritesheet_;
    sf::Image spritesheet_image_;
    vector< sf::Rect<int> > clip_rects_;
};

#endif
