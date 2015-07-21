#include "game.hpp"

Game::Game() :
    window_(new Window()),
    graphics_(new Graphics(window_)),
    input_(new Input()),
    map_(new Map("data/tileset1.json", "data/map_config.json", "data/map.bmp")),
    camera_(new Camera(100, 600, window_, map_))
{}

//Main Game loop. 
void Game::Loop() {
    sf::Clock clock;

    shared_ptr<Player> player_entity(new Player(0,0,"data/player.json"));
    shared_ptr<EntityList> entity_list(new EntityList());
    entity_list->push(player_entity);
    camera_->set_player(player_entity);

    Event event;
    Time previous = clock.getElapsedTime();
    Time lag = sf::milliseconds(0);
    while (window_->is_open()) {
        Time current = clock.getElapsedTime(); 
        Time elapsed = current - previous; //Get the time elapsed since last loop
        previous = current; 
        lag += elapsed; //Increase lag by elapsed time since last loop
        //Poll for an event.
        input_->clear();
        while (window_->poll_event(event)) {
            if (event.type == Event::Closed) {
                window_->close();
                break;
            } else if(event.type == Event::KeyPressed) {
                input_->key_down_event(event.key.code);
            } else if(event.type == Event::KeyReleased) {
                input_->key_up_event(event.key.code);
            }
        }

        //Control player input
        if(input_->is_key_held(sf::Keyboard::Left) &&
           input_->is_key_held(sf::Keyboard::Right)) {
            player_entity->stop_move();
        } else if(input_->is_key_held(sf::Keyboard::Left)) {
            player_entity->start_move_left();
        } else if(input_->is_key_held(sf::Keyboard::Right)) {
            player_entity->start_move_right();
        } else {
            player_entity->stop_move();
        }

        //Control player jump
        if(input_->was_key_pressed(sf::Keyboard::Up)) {
            player_entity->start_jump();
        } else if(input_->was_key_released(sf::Keyboard::Up)) {
            player_entity->stop_jump();
        }

        //Update the game until caught up
        while(lag >= MS_PER_UPDATE) {
            //Update every entity
            entity_list->update_all(lag.asMilliseconds());
            camera_->check_player();
            //Remove lag equal to one frame of time
            lag -= MS_PER_UPDATE;
        }
        //Render the current frame
        graphics_->clear();
        map_->draw(graphics_);
        entity_list->draw(graphics_);
        graphics_->display();
    }
}

