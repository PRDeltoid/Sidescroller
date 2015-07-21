#ifndef ANIMATED_SPRITESHEET_H
#define ANIMATED_SPRITESHEET_H

#include "spritesheet.cpp"

class AnimatedSpritesheet : public Spritesheet {
    public:
        AnimatedSpritesheet(string);
        void init(string);
        shared_ptr<sf::RectangleShape> get_sprite() { return sprite_; }
        void parse_json(string);
        void update_sprite(int);
        void next_sprite();
        void set_animation(string);
    private:
        int ms_per_sprite_;
        int ms_since_last_sprite_;
        pair <int, int> current_animation_;
        map <string, pair <int, int> > animations_;
};


#endif
