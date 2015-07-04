#ifndef PLAYER_H_
#define PLAYER_H_

#include "entity.hpp"
#include "playerJump.cpp"

class Player : public Entity {
public:
    Player(int, int, string);
    void update(int);
    void start_move_left();
    void start_move_right();
    void stop_move();
    void move(int);

    void jump(int);
    void start_jump();
    void stop_jump();

    bool on_ground();

protected:
    float max_velocity_x_;
    float max_velocity_y_;
    float velocity_x_;
    float velocity_y_;
    float acceleration_;
    float walk_acceleration_;
    PlayerJump jump_;
    bool on_ground_;
};


#endif
