#include "playerJump.hpp"

PlayerJump::PlayerJump() :
    active_(false),
    time_remaining_ms_(0)
{}

void PlayerJump::reset() {
    time_remaining_ms_ = 275; //max_ms_per_jump;
    active_ = true;
}

void PlayerJump::stop() {
    active_ = false;
}

void PlayerJump::update(int elapsed_time) {
    if(active_) {
        time_remaining_ms_ -= elapsed_time;
        if(time_remaining_ms_ <=0) {
            active_ = false;
        }
    }

}
