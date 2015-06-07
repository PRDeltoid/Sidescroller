#include "graphics.hpp"

//Ctor
Graphics::Graphics(Window* window) :
    window_(window)
{
    initialize();
}

void Graphics::initialize() {
}

void Graphics::draw() {
}

//Interface to clear the window.
void Graphics::clear() {
    window_->clear();
}

//Interface to display the window's shapes
void Graphics::display() {
    window_->display();
}

//Encasulating function for clear/draw/display
void Graphics::render() {
    clear();
    draw();
    display();
}

