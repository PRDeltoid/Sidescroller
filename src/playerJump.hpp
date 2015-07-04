#ifndef PLAYERJUMP_H
#define PLAYERJUMP_H

const int max_ms_per_jump = 300;

class PlayerJump {
public:
    PlayerJump();
    void reset();
    void stop();
    void update(int);
    bool active() { return active_; }
protected:
    bool active_;
    int time_remaining_ms_;

};

#endif
