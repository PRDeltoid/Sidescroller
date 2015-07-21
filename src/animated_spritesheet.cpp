#include "animated_spritesheet.hpp"

AnimatedSpritesheet::AnimatedSpritesheet(string spritesheet_json) :
    Spritesheet(spritesheet_json)
{
    init(spritesheet_json);
}

void AnimatedSpritesheet::init(string spritesheet_json) {
    parse_json(spritesheet_json);
    ms_since_last_sprite_ = ms_per_sprite_;
}

void AnimatedSpritesheet::parse_json(string json_file) {
    //Create the JSON object
    JSONDoc json_doc(json_file);

    //Get animations
    Json::Value animations = json_doc.get("animations");
    for(unsigned int i=0;i<animations.size();i++) {
        int start = animations[i]["start"].asInt();
        int stop = animations[i]["stop"].asInt();
        animations_[animations[i]["name"].asString()] = std::make_pair(start, stop);
    }

    ms_per_sprite_ = json_doc.get("ms_per_sprite").asInt();
}

void AnimatedSpritesheet::update_sprite(int elapsed_time) {
    ms_since_last_sprite_ -= elapsed_time;
    if(ms_since_last_sprite_ <= 0) {
        sprite_->setTextureRect(clip_rects_[current_sprite_]);
        next_sprite();
        ms_since_last_sprite_ = ms_per_sprite_;
    }
}

void AnimatedSpritesheet::next_sprite() {
    if(current_sprite_ >= current_animation_.second-1) {
        current_sprite_ = current_animation_.first;
    } else {
        current_sprite_++;
    }
}

void AnimatedSpritesheet::set_animation(string animation_name) {
    current_animation_ = animations_[animation_name];
}
