#include "player.hpp"
//#include <algorithm>
#include <cmath>

const float slowdown = 0.8f; //Decell Speed
const float gravity = 0.0012f;

Player::Player(int x, int y, string json) :
    Entity(x, y, json),
    on_ground_(false)
{
    max_velocity_x_ = entity_json_->get("max_velocity_x").asFloat();
    max_velocity_y_ = entity_json_->get("max_velocity_y").asFloat();
    walk_acceleration_ = entity_json_->get("acceleration").asFloat();
    velocity_x_ = 0.0f;
    velocity_y_ = 0.0f;
}

void Player::update(int elapsed_time) {
    move(elapsed_time);
    jump(elapsed_time);
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

//Update the player's walk movement and position 
void Player::move(int elapsed_time) {
    //Create a new X position based on velocity of character
    int new_x = x_ + round(velocity_x_*elapsed_time);
    //Increase the velocity
    velocity_x_ += acceleration_*elapsed_time;
    //Make sure velocity is within max boundaries
    //(negative accel is left, positive accel is right
    if(acceleration_ < 0) {
        velocity_x_ = std::max(velocity_x_, -max_velocity_x_);
    } else if(acceleration_ > 0) {
        velocity_x_ = std::min(velocity_x_, max_velocity_x_);
    //If accel is 0, and player is on ground, slow them down until stopped
    } else if(on_ground()){
        velocity_x_ *= slowdown;
    }
    //Move the character to the new space
    set_pos(new_x, y_);
}

//Jump update method. Only does something is the player is jumping
void Player::jump(int elapsed_time) {
    //Update the jump to see if it's still active
    jump_.update(elapsed_time);
    //Move the character up by the velocity multiplied by the time since last update
    y_ += round(velocity_y_*elapsed_time);
    //If the jump is no longer active (timed out or button was let go), invert velocity and start falling
    if(!jump_.active()) {
        velocity_y_ = std::min(velocity_y_ + gravity * elapsed_time, max_velocity_y_);
    }
    //If the player hits the ground, stop falling
    if(y_ >= 320) {
        velocity_y_ = 0.0f;
        y_ = 320;
    }
    //then set on_ground_ to true if player is on ground
    on_ground_ = y_ == 320;
}

void Player::start_jump() {
    spritesheet_->set_animation("stand");
    //Only start the jump if the player is on the ground
    if(on_ground()) {
        jump_.reset();
        velocity_y_ = -0.325f;
    }
}

//Stop the jump. Used if the player releases the jump button before the natural end of the jump
void Player::stop_jump() {
    jump_.stop();
}

//Quick hack to determine if player is on the ground.
bool Player::on_ground() {
    if(y_ >= 320) {
        return true;
    } else {
        return false;
    }
}
