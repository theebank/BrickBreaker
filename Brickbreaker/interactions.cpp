//
//  interactions.cpp
//  Brickbreaker
//
//  Created by Theeban Kumaresan on 2023-09-19.
//

#include "interactions.hpp"
#include <iostream>

bool is_interacting(const entity& e1, const entity& e2) {
    auto box1 = e1.get_bounding_box();
    auto box2 = e2.get_bounding_box();
    return box1.intersects(box2);
}

void handle_collision(ball &b, const paddle& p) {
    if (is_interacting(p,b)) {
        b.move_up();

        if (b.x() < p.x()){
                        b.move_left();
        }
        else{
                        b.move_right();
        }
    }
}
void handle_collision(ball &b,brick& brick) {
    if(is_interacting(brick, b)){
        
        
        brick.weaken();
        if(brick.is_weak()){
            brick.destroy();
        }
        
        float left_ov = b.right() - brick.left();
        float right_ov = brick.right()-b.left();
        float top_ov = b.bottom() - brick.top();
        float bottom_ov = brick.top()-b.top();
        
        bool xcol = std::abs(left_ov)<std::abs(right_ov);
        bool ycol = std::abs(top_ov)<std::abs(bottom_ov);
        
        float min_x_ov = xcol ? left_ov: right_ov;
        float min_y_ov = ycol ? top_ov : bottom_ov;
        
        if(std::abs(min_x_ov)< std::abs(min_y_ov)){
            if(xcol){
                b.move_left();
            }else{
                b.move_right();
            }
        }else{
            if(ycol){
                b.move_up();
            }else{
                b.move_down();
            }
        }
    }
}
