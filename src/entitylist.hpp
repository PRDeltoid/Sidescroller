#ifndef ENTITYLIST_H
#define ENTITYLIST_H

#include "entity.hpp"

class EntityList {
    public:
        EntityList() :
            size_(0)
        {}
        void push(Entity*);
        void remove(int);
        Entity* at(int);
        int size();
    private:
        vector<Entity*> entity_list_;
        int size_;
};

#endif
