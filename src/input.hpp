#include <map>
#include <SFML/Window.hpp>

class Input {
public:
    void clear_maps();
    void key_down_event(const sf::Event);
    void key_up_event(const sf::Event);
    bool is_key_pressed(const sf::Event);
    bool is_key_released(const sf::Event);

private:
    std::map<sf::Event, bool> pressed_keys_;
    std::map<sf::Event, bool> released_keys_;
    std::map<sf::Event, bool> held_keys_;
};
