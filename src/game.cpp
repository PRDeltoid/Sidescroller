#include "game.hpp"

Game::Game() :
    window_(new Window()),
    graphics_(new Graphics(window_)),
    input_(new Input())
{}

//Main Game loop. 
void Game::Loop() {
    sf::Clock clock;

    shared_ptr<Entity> player_entity(new Entity(0,0,"player.json"));
    EntityList* entity_list = new EntityList();
    entity_list->push(player_entity);
    graphics_->set_entity_list(entity_list);

    Event event;

    Time previous = clock.getElapsedTime();
    Time lag = sf::milliseconds(0);
    while (window_->is_open()) {
        Time current = clock.getElapsedTime(); 
        Time elapsed = current - previous; //Get the time elapsed since last loop
        previous = current; 
        lag += elapsed; //Increase lag by elapsed time since last loop
        //Poll for an event.
        while (window_->poll_event(event)) {
            if (event.type == Event::Closed) {
                window_->close();
                break;
            } else if(event.KeyPressed) {
                input_->key_down_event(event);
            } else if(event.KeyReleased) {
                input_->key_up_event(event);
            }
        }
        //Update the game until caught up
        while(lag >= MS_PER_UPDATE) {
            //Update every entity
            entity_list->update_all();
            //Remove lag equal to one frame
            lag -= MS_PER_UPDATE;
        }
        //Render the current frame
        graphics_->render();
    }

    delete entity_list;
}

