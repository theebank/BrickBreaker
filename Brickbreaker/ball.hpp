//
//  ball.hpp
//  Brickbreaker
//
//  Created by Theeban Kumaresan on 2023-09-19.
//

#ifndef ball_hpp
#define ball_hpp

#include <stdio.h>
#include "constants.h"
#include "entity.h"

class ball: public moving_entity{
    
    static sf::Texture texture;
public:
    ball(float x, float y);
    
    void move_up() noexcept override;
    void move_left() noexcept override;
    void move_right() noexcept override;
    void move_down() noexcept override;
    
    void update() override;
    void draw(sf::RenderWindow& window) override;
    
    
};

#endif /* ball_hpp */
