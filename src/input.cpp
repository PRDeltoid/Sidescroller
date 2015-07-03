#include "input.hpp"

void Input::clear_maps() {
    pressed_keys_.clear();
    released_keys_.clear();
}

void Input::key_down_event(const sf::Event event) {
    pressed_keys_[event] = true;
}

void Input::key_up_event(const sf::Event event) {
    released_keys_[event] = true;
}

bool Input::is_key_pressed(const sf::Event event) {
    return pressed_keys_[event];
}

bool Input::is_key_released(const sf::Event event) {
    return released_keys_[event];
}
