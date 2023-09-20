//
//  brick.hpp
//  Brickbreaker
//
//  Created by Theeban Kumaresan on 2023-09-19.
//

#ifndef brick_hpp
#define brick_hpp

#include <stdio.h>
#include "entity.h"
#include "constants.h"

class brick: public entity {
    static sf::Texture texture;
    
    int strength{constants::brick_strength};

public:
    
    brick(float x, float y);
    
    void update() override;
    void draw(sf::RenderWindow& window) override;
    
    void set_strength(int) noexcept;
    void weaken() noexcept;
    bool is_weak() const noexcept;
};

#endif /* brick_hpp */
