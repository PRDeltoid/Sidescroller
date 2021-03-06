#include "input.hpp"

void Input::clear() {
    pressed_keys_.clear();
    released_keys_.clear();
}

void Input::key_down_event(const sf::Keyboard::Key key) {
    pressed_keys_[key] = true;
    held_keys_[key] = true;
}

void Input::key_up_event(const sf::Keyboard::Key key) {
    released_keys_[key] = true;
    held_keys_[key] = false;
}

bool Input::was_key_pressed(const sf::Keyboard::Key key) {
    return pressed_keys_[key];
}

bool Input::was_key_released(const sf::Keyboard::Key key) {
    return released_keys_[key];
}

bool Input::is_key_held(const sf::Keyboard::Key key) {
    return held_keys_[key];
}
