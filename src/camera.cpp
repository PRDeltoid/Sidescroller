#include "camera.hpp"

Camera::Camera(int width, int height, 
               shared_ptr<Player> player, shared_ptr<Window> window) :
    w_(width),
    h_(height),
    player_(player),
    window_(window)
{
    left_bound_ = 100;
    right_bound_ =  w_+left_bound_;
    top_bound_ = 100;
    bottom_bound_ = h_+top_bound_;
}

void Camera::set_player(shared_ptr<Player> player) {
    player_ = player;
}

void Camera::check_player() {
    Pos current_pos = player_->get_pos();

    if(current_pos.x_ > right_bound_) {
        player_->set_pos(right_bound_, current_pos.y_);
    }
    if(current_pos.x_ < left_bound_) {
        player_->set_pos(left_bound_, current_pos.y_);
    }
    if(current_pos.y_ < top_bound_) {
        player_->set_pos(current_pos.x_, top_bound_);
    }
    if(current_pos.y_ > bottom_bound_) {
        player_->set_pos(current_pos.x_, bottom_bound_);
    }
}
    

