#include "spritesheet.hpp"

Spritesheet::Spritesheet(string spritesheet_json) {
    sprite_ = new sf::RectangleShape;
    spritesheet_ = new sf::Texture;
    parse_json("data/"+spritesheet_json);
    sprite_->setSize(sf::Vector2f(sprite_width_, sprite_height_));
    //Set up the first frame to show
    current_sprite_ = 0;
    sprite_->setTextureRect(clip_rects_[current_sprite_]);
    //Set the origin to the center of the sprite
    sprite_->setOrigin(sprite_width_/2, sprite_height_/2);
}

Spritesheet::~Spritesheet() {
    delete sprite_;
    delete spritesheet_;
}

void Spritesheet::update_sprite() {
    sprite_->setTextureRect(clip_rects_[current_sprite_]);
    next_sprite();
}

void Spritesheet::next_sprite() {
    if(current_sprite_ >= current_animation_.second-1) {
        current_sprite_ = current_animation_.first;
    } else {
        current_sprite_++;
    }
}

void Spritesheet::set_spritesheet(string filename) {
    sf::Image texture_image_;
    texture_image_.loadFromFile(filename); 
    spritesheet_->loadFromImage(texture_image_);
    spritesheet_->setSmooth(true); //Smooth edges
    sprite_->setTexture(spritesheet_, false);
}

void Spritesheet::parse_json(string json_file) {
    //Create the JSON object
    JSONDoc json_doc(json_file);

    //Get/Load image path from JSON
    string path_string = json_doc.get("image").asString();
    set_spritesheet("assets/"+path_string);

    //Create the frame rects
    Json::Value frames = json_doc.get("frames");
    get_clip_rects(frames);

    sprite_width_ = json_doc.get("sprite_size")["w"].asInt();
    sprite_height_ = json_doc.get("sprite_size")["h"].asInt();

    Json::Value animations = json_doc.get("animations");
    for(unsigned int i=0;i<animations.size();i++) {
        int start = animations[i]["start"].asInt();
        int stop = animations[i]["stop"].asInt();
        animations_[animations[i]["name"].asString()] = std::make_pair(start, stop);
    }
}

void Spritesheet::get_clip_rects(Json::Value frame_json) {
    for(unsigned int i=0;i<frame_json.size();i++) {
        sf::Rect<int> frame_rect;
        frame_rect.height =  frame_json[i]["frame"]["h"].asInt();
        frame_rect.width =   frame_json[i]["frame"]["w"].asInt();
        frame_rect.top  =    frame_json[i]["frame"]["y"].asInt();
        frame_rect.left =    frame_json[i]["frame"]["x"].asInt();
        clip_rects_.push_back(frame_rect);
    }
    total_sprites_ = frame_json.size()-1;
}

void Spritesheet::set_animation(string animation_name) {
    current_animation_ = animations_[animation_name];
}
