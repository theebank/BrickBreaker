//
//  interactions.hpp
//  Brickbreaker
//
//  Created by Theeban Kumaresan on 2023-09-19.
//

#ifndef interactions_hpp
#define interactions_hpp

#include <stdio.h>
#include "ball.hpp"
#include "paddle.hpp"
#include "brick.hpp"

bool is_interacting(const entity& e1, const entity& e2);

void handle_collision(ball& b, const paddle& p);

void handle_collision(ball& b, brick& p);

#endif /* interactions_hpp */
