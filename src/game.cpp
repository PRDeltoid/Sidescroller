#include "game.hpp"

void Game::Init() {
    window_ = new Window();
    graphics_ = new Graphics(window_);
}

//Main Game loop. 
void Game::Loop() {
    sf::Clock clock;

    Entity* entity = new Entity(0,0,"player.json");
    EntityList* entity_list = new EntityList();
    entity_list->push(entity);
    graphics_->set_entity_list(entity_list);

    sf::Event event;

    sf::Time previous = clock.getElapsedTime();
    sf::Time lag = sf::milliseconds(0);
    while (window_->is_open()) {
        sf::Time current = clock.getElapsedTime();
        sf::Time elapsed = current - previous;
        previous = current;
        lag += elapsed;
        while (window_->poll_event(event)) {
            if (event.type == sf::Event::Closed) {
                window_->close();
                break;
            }
        }
        while(lag >= MS_PER_UPDATE) {
            entity->update();
            lag -= MS_PER_UPDATE;
        }
        /*window_->clear();
        window_->draw(entity.get_sprite());
        window_->display();*/
        graphics_->render();
    }
}

