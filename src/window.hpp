#ifndef WINDOW_H
#define WINDOW_H

#include <SFML\Graphics.hpp>
#include <boost\shared_ptr.hpp>

const int WIDTH = 800;
const int HEIGHT = 640;

class Window {
    boost::shared_ptr<sf::RenderWindow> window_;
public:
    Window() { window_.reset(new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Sidescroller", sf::Style::Close)); }
    boost::shared_ptr<sf::RenderWindow> get_window() { return window_; }
    bool is_open() { return window_->isOpen(); }
    void display() { window_->display(); }
    void close() { window_->close(); }
    void clear() { window_->clear(); }
    void draw(sf::RectangleShape* rect) { window_->draw(*rect); }
    bool poll_event(sf::Event& event) { return window_->pollEvent(event); }
    int get_width() { return window_->getSize().x; }
    int get_height() { return window_->getSize().y; }
};

#endif
