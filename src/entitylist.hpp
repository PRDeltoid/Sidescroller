#ifndef ENTITYLIST_H
#define ENTITYLIST_H

#include <vector>
#include "../include/boost/shared_ptr.hpp"

using boost::shared_ptr;

class Entity;

class EntityList {
    public:
        EntityList() :
            size_(0)
        {}
        void push(shared_ptr<Entity>);
        void remove(int);
        shared_ptr<Entity> at(int);
        void update_all(int);
        int size();
    private:
        std::vector<shared_ptr<Entity> > entity_list_;
        int size_;
};

#endif
