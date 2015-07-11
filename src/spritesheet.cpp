#include "spritesheet.hpp"

Spritesheet::Spritesheet(string spritesheet_json) {
    init(spritesheet_json);
}

Spritesheet::~Spritesheet() {
    delete sprite_;
    delete spritesheet_;
}

void Spritesheet::init(string spritesheet_json) {
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

sf::RectangleShape* Spritesheet::get_sprite(int spritenum) {
    if(spritenum == -1) {
        return NULL;
    }
    sprite_->setTextureRect(clip_rects_[spritenum]);
    return sprite_;
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

