#include "entitylist.hpp"

#include "entity.hpp"
#include "graphics.hpp"

void EntityList::push(shared_ptr<Entity> entity) {
    entity_list_.push_back(entity);
    size_++;
}

void EntityList::remove(int pos) {
    entity_list_.erase(entity_list_.begin()+pos);
    size_--;
}

shared_ptr<Entity> EntityList::at(int pos) {
    return entity_list_.at(pos);
}

void EntityList::update_all(int elapsed_time) {
    for(int i=0; i<size_; i++)
        entity_list_.at(i)->update(elapsed_time);
}

void EntityList::draw(shared_ptr<Graphics> graphics) {
    for(int i=0; i < size_; i++) {
        graphics->draw(entity_list_.at(i)->get_sprite());
    }
}

int EntityList::size() {
    return size_;
}
