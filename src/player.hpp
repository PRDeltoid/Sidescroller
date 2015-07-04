#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.hpp"

class Player : public Entity {
public:
    Player(int, int, string);
    void update(int);
    void start_move_left();
    void start_move_right();
    void stop_move();

    void move(int);

protected:
    float max_velocity_;
    float velocity_;
    float acceleration_;
    float walk_acceleration_;
};


#endif
