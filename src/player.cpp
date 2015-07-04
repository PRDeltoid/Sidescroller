#include "player.hpp"
//#include <algorithm>
#include <cmath>

const float slowdown = 0.8f;

Player::Player(int x, int y, string json) :
    Entity(x, y, json)
{
    max_velocity_ = entity_json_->get("max_velocity").asFloat();
    walk_acceleration_ = entity_json_->get("acceleration").asFloat();
    velocity_ = 0.0f;
}

void Player::update(int elapsed_time) {
    move(elapsed_time);
    spritesheet_->update_sprite();
}

void Player::start_move_left() {
    spritesheet_->set_animation("walk");
    set_facing(LEFT);
    acceleration_ = -walk_acceleration_;
}

void Player::start_move_right() {
    spritesheet_->set_animation("walk");
    set_facing(RIGHT);
    acceleration_ = walk_acceleration_;
}

void Player::stop_move() {
    spritesheet_->set_animation("stand");
    acceleration_ = 0;
}

void Player::move(int elapsed_time) {
    int new_x = x_ + round(velocity_*elapsed_time);
    velocity_ += acceleration_*elapsed_time;
    if(acceleration_ < 0) {
        velocity_ = std::max(velocity_, -max_velocity_);
    } else if(acceleration_ > 0) {
        velocity_ = std::min(velocity_, max_velocity_);
    } else {
        velocity_ *= slowdown;
    }
    set_pos(new_x, y_);
}
