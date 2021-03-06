#ifndef CAMERA_H
#define CAMERA_H

#include "player.hpp"
#include "window.hpp"
#include "map.hpp"
#include <boost/shared_ptr.hpp>

using boost::shared_ptr;

class Camera {
public:
    Camera(int, int, shared_ptr<Player>, shared_ptr<Window>, shared_ptr<Map>);
    Camera(int, int, shared_ptr<Window>, shared_ptr<Map>);
    void set_player(shared_ptr<Player>);
    void check_player();
    void move_map(int, int);
private:
    int w_;
    int h_;
    int right_bound_;
    int left_bound_;
    int top_bound_;
    int bottom_bound_;
    shared_ptr<Player> player_;
    shared_ptr<Window> window_;
    shared_ptr<Map> map_;
};

#endif
