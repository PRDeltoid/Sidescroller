#include "graphics.hpp"

//Ctor
Graphics::Graphics(shared_ptr<Window> window) :
    window_(window)
{}

void Graphics::draw() {
    for(int i=0; i < entity_list_->size(); i++) {
        window_->draw(entity_list_->at(i)->get_sprite());
    }
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

void Graphics::set_entity_list(EntityList* entity_list) {
    entity_list_ = entity_list;
}

