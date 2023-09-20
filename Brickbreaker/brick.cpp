//
//  brick.cpp
//  Brickbreaker
//
//  Created by Theeban Kumaresan on 2023-09-19.
//

#include "brick.hpp"


sf::Texture brick::texture;

const sf::Color one_hit{0,255,0,80};
const sf::Color two_hit{0,255,0,170};
const sf::Color three_hit{0,255,0,255};

brick::brick(float x, float y): entity(){
    texture.loadFromFile("/Users/theebankumaresan/Documents/Programming/Brickbreaker/Brickbreaker/Brickbreaker/brick01.png");
    sprite.setTexture(texture);
    
    sprite.setPosition(x,y);
    sprite.setOrigin(get_center());
};

void brick::update(){
    if(strength==1){sprite.setColor(one_hit);}
    else if(strength==2){sprite.setColor(two_hit);}
    else if(strength==3){sprite.setColor(three_hit);};
}
void brick::draw(sf::RenderWindow &window){
    window.draw(sprite);
}

void brick::set_strength(int s) noexcept{strength = s;};
void brick::weaken() noexcept {strength = strength-1;};
bool brick::is_weak() const noexcept{return strength <= 0;}
