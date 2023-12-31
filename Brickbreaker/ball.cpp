//
//  ball.cpp
//  Brickbreaker
//
//  Created by Theeban Kumaresan on 2023-09-19.
//

#include "ball.hpp"
#include<iostream>
sf::Texture ball::texture;

ball::ball(float x, float y): moving_entity(){
    texture.loadFromFile("/Users/theebankumaresan/Documents/Programming/Brickbreaker/Brickbreaker/Brickbreaker/assets/ball.png");
    sprite.setTexture(texture);
    
    sprite.setPosition(x,y);
    velocity={constants::ball_velocity, constants::ball_velocity};
    sprite.setOrigin(get_center());
}

void ball::move_up() noexcept {
    velocity.y = -constants::ball_velocity;
}

void ball::move_left() noexcept {
    velocity.x = -constants::ball_velocity;
}

void ball::move_right() noexcept {
    velocity.x = constants::ball_velocity;
}
void ball::move_down() noexcept {
    velocity.y = constants::ball_velocity;
}


void ball::update(){
    sprite.move(velocity);
    if(x()<0){
        velocity.x = - velocity.x;
    }
    if(x()>constants::window_width){
        velocity.x = -velocity.x;
    }
    if(y()<0){
        velocity.y= -velocity.y;
    }
    if(y()>constants::window_height){
        destroy();
    }
    
}



void ball::draw(sf::RenderWindow &window){
    window.draw(sprite);
}


