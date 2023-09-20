//
//  game.cpp
//  Brickbreaker
//
//  Created by Theeban Kumaresan on 2023-09-19.
//

#include "game.hpp"
#include "interactions.hpp"

void entityManager::refresh(){
    for(auto& [type, alias_vector]: grouped_entities){
        alias_vector.erase(remove_if(begin(alias_vector),end(alias_vector),[](const auto& p){return p->is_destroyed();}
                                     ),end(alias_vector));
    }
    all_entities.erase(remove_if(begin(all_entities),end(all_entities),
                                 [](const auto& p){return p->is_destroyed();}),
                       end(all_entities));
}

void entityManager::clear(){
    grouped_entities.clear();
    all_entities.clear();
}

void entityManager::update(){
    for(auto& e : all_entities){
        e->update();
    }
}
void entityManager::draw(sf::RenderWindow &window){
    for(auto& e: all_entities){
        e->draw(window);
    }
}


game::game(){

    window.setFramerateLimit(60);
    
    Arial.loadFromFile("/Library/Fonts/Arial Unicode.ttf");
    
    text_state.setFont(Arial);
    text_state.setPosition(constants::window_width/2.0f-100.0f, constants::window_height/2.0f-100.0f);
    text_state.setCharacterSize(14);
    text_state.setFillColor(sf::Color::White);
    text_state.setString("Paused, Press P to Resume.");
    
    text_lives.setFont(Arial);
    text_lives.setPosition(constants::window_width/2.0f-90.0f, constants::window_height/2.0f-50.0f);
    text_lives.setCharacterSize(14);
    text_lives.setFillColor(sf::Color::White);
    text_lives.setString("Lives: "+ std::to_string(lives));
}
void game::run(){
    bool pause_key_active{false};
    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)){break;}
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)){
            if(!pause_key_active){
                if(state == state::paused){
                    state = state::running;
                }else{
                    state = state::paused;
                }
            }
            pause_key_active = true;
        }else{
            pause_key_active = false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)){
            reset();
        }
        
        if(state == state::paused){
            manager.draw(window);
        }
        if(state != state::running){
            switch (state) {
                case state::paused:
                    text_state.setString("Paused, Press P to resume.");
                    break;
                case state::over:
                    text_state.setString("Game Over! Press R to restart.");
                    break;
                case state::winner:
                    text_state.setString("YOU WIN! Press R to restart!");
                    break;
                default:
                    break;
            }
            window.draw(text_state);
            window.draw(text_lives);
        }else{
            if(manager.get_all<ball>().empty()){
                manager.create<ball>(constants::window_width/2.0f,constants::window_height/2.0f);
                lives = lives -1;
                
                state = state::paused;
            }
            if(manager.get_all<brick>().empty()){
                state = state::winner;
            }
            if(lives <= 0){
                state = state::over;
            }
            
            text_lives.setString("Lives: "+ std::to_string(lives));
            manager.update();
            
            manager.apply_all<ball>([this](auto& gball){
                manager.apply_all<brick>([&gball](auto& brick){
                    handle_collision(gball, brick);
                });
            });
            manager.apply_all<ball>([this](auto& b){
                manager.apply_all<paddle>([&b](auto& p){
                    handle_collision(b, p);
                });
            });
            manager.refresh();
            manager.draw(window);
        }
        
        window.display();
    }
}
void game::reset(){
    state = state::paused;
    lives= constants::lives;
    
    manager.clear();
    manager.create<background>(0.0f,0.0f);
    manager.create<ball>(constants::window_width/2.0f,constants::window_height/2.0f);
    manager.create<paddle>(constants::window_width/2.0f,constants::window_height-constants::paddle_height);
    
    for(int i = 0;i<constants::brick_columns;++i){
        for(int j = 0;j<constants::brick_rows;++j){
            float x = constants::brick_offset + (i+1)* constants::brick_width;
            float y = (j+1)* constants::brick_height;
            
            manager.create<brick>(x,y);
        }
    }
    window.setFramerateLimit(60);
}
