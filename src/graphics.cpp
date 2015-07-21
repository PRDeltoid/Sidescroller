#include "graphics.hpp"

//Ctor
Graphics::Graphics(shared_ptr<Window> window) :
    window_(window)
{}

void Graphics::draw(shared_ptr<sf::RectangleShape> rect) {
    window_->draw(rect.get()); //Hacky smart pointer passed as a normal ptr
}

//Interface to clear the window.
void Graphics::clear() {
    window_->clear();
}

//Interface to display the window's shapes
void Graphics::display() {
    window_->display();
}
