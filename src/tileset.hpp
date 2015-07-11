#ifndef Tileset_H
#define Tileset_H

#include "spritesheet.hpp"

class Tileset: public Spritesheet {
    public:
        Tileset(string, int, int);
        void init(int, int);
};

#endif
