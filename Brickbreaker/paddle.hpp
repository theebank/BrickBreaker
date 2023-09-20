//
//  paddle.hpp
//  Brickbreaker
//
//  Created by Theeban Kumaresan on 2023-09-19.
//

#ifndef paddle_hpp
#define paddle_hpp

#include <stdio.h>
#include "entity.h"

class paddle: public moving_entity{
    static sf::Texture texture;
    void process_player_input();
public:
    paddle(float x, float y);
    
    void move_up() noexcept override;
    void move_left() noexcept override;
    void move_right() noexcept override;
    void move_down() noexcept override;
    
    void update() override;
    void draw(sf::RenderWindow& window) override;

};

#endif /* paddle_hpp */
