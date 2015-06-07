#include "spritesheet.hpp"

Spritesheet::Spritesheet() {
    sprite_ = new sf::RectangleShape;
    spritesheet_ = new sf::Texture;
    parse_json("data/p1_walk.json");
    current_sprite_ = 0;
}

void Spritesheet::update_sprite() {
    sprite_->setTextureRect(clip_rects_[current_sprite_]);
    next_sprite();
}
void Spritesheet::next_sprite() {
    if(current_sprite_ >= total_sprites_) {
        current_sprite_ = 0;
    } else {
        current_sprite_++;
    }
}

void Spritesheet::set_spritesheet(string filename) {
    sf::Image texture_image_;
    texture_image_.loadFromFile(filename); 
    spritesheet_->loadFromImage(texture_image_);
    spritesheet_->setSmooth(true); //Smooth edges
}

void Spritesheet::parse_json(string json_file) {
    Json::Value root;
    Json::Reader reader;
    std::ifstream file(json_file.c_str()); //"data/p1_walk.json");
    std::string json((std::istreambuf_iterator<char>(file)),
                      std::istreambuf_iterator<char>());    
    reader.parse(json, root);

    //Get image path from JSON
    string path_string = root["image"].asString();

    Json::Value frames = root["frames"];
    get_clip_rects(frames);

    set_spritesheet("assets/"+path_string);
    /*Load the file as an image.
    spritesheet_image_.loadFromFile("assets/"+path_string);
    //Load image as a texture for the spritesheet
    spritesheet_->loadFromImage(spritesheet_image_);
    spritesheet_->setSmooth(true);
    */


    //create a clip rect for testing
    sprite_->setSize(sf::Vector2f(73,97));
    sprite_->setTexture(spritesheet_, false);
    sprite_->setTextureRect(clip_rects_[0]);
}

void Spritesheet::get_clip_rects(Json::Value frame_json) {
    for(unsigned int i=0;i<frame_json.size()-1;i++) {
        sf::Rect<int> frame_rect;
        frame_rect.height = frame_json[i]["frame"]["h"].asInt();
        frame_rect.width = frame_json[i]["frame"]["w"].asInt();
        frame_rect.top  = frame_json[i]["frame"]["y"].asInt();
        frame_rect.left = frame_json[i]["frame"]["x"].asInt();
        clip_rects_.push_back(frame_rect);
    }
    total_sprites_ = frame_json.size()-1;
}
