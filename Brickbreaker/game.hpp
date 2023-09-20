//
//  game.hpp
//  Brickbreaker
//
//  Created by Theeban Kumaresan on 2023-09-19.
//

#ifndef game_hpp
#define game_hpp

#include <stdio.h>
#include "background.hpp"
#include "ball.hpp"
#include "brick.hpp"
#include "paddle.hpp"
#include "constants.h"
#include "interactions.hpp"
#include <vector>

using entityvector = std::vector<std::unique_ptr<entity>>;
using entity_alias_vector = std::vector<entity *>;

class entityManager {
    entityvector all_entities;
    
    std::map<size_t, entity_alias_vector> grouped_entities;
public:
    template<typename T, typename ...Args>
    T& create(Args&&... args){
        static_assert(std::is_base_of<entity, T>:: value, R"("T" type parameter in create must be derived from entity)");
        auto ptr{std::make_unique<T>(std::forward<Args>(args)...)};
        
        auto ptr_alias = ptr.get();
        
        auto hash = typeid(T).hash_code();
        
        grouped_entities[hash].emplace_back(ptr_alias);
        
        all_entities.emplace_back(std::move(ptr));
        
        return *ptr_alias;
    }
    void refresh();
    void clear();
    
    template<typename T>
    auto& get_all() {
        return grouped_entities[typeid(T).hash_code()];
    }
    
    template<typename T, typename Func>
    void apply_all(const Func& func){
        auto& entity_group{get_all<T>()};
        
        for(auto ptr: entity_group){
            func(*dynamic_cast<T*>(ptr));
        }
    }
    void update();
    void draw(sf::RenderWindow& window);
};

class game {
    
    sf::RenderWindow window{{constants::window_width, constants::window_height},"Breakout"};
    
    enum class state {paused, running, over, winner};
    
    entityManager manager;
    
    state state{state::running};
    
    sf::Text text_state, text_lives;
    sf::Font Arial;
    int lives{constants::lives};
public:
    game();
    
    void reset();
    void run();
    
    
};

#endif /* game_hpp */
