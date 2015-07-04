#include <map>
#include <SFML/Window.hpp>

class Input {
public:
    void clear_maps();
    void key_down_event(const sf::Event);
    void key_up_event(const sf::Event);
    bool was_key_pressed(const sf::Keyboard::Key);
    bool was_key_released(const sf::Keyboard::Key);
    bool is_key_held(const sf::Keyboard::Key);

private:
    std::map<sf::Keyboard::Key, bool> pressed_keys_;
    std::map<sf::Keyboard::Key, bool> released_keys_;
    std::map<sf::Keyboard::Key, bool> held_keys_;
};
