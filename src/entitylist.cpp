#include "entitylist.hpp"

void EntityList::push(Entity* entity) {
    entity_list_.push_back(entity);
    size_++;
}

void EntityList::remove(int pos) {
    entity_list_.erase(entity_list_.begin()+pos);
    size_--;
}

Entity* EntityList::at(int pos) {
    return entity_list_.at(pos);
}

int EntityList::size() {
    return size_;
}
