//
//  background.cpp
//  Brickbreaker
//
//  Created by Theeban Kumaresan on 2023-09-19.
//

#include "background.hpp"

sf::Texture background::texture;

background::background(float x, float y) : entity() {
  texture.loadFromFile("/Users/theebankumaresan/Documents/Programming/Brickbreaker/Brickbreaker/Brickbreaker/background.jpg");
  sprite.setTexture(texture);
  sprite.setPosition(x, y);
}


void background::update() {
  
}

void background::draw(sf::RenderWindow& window) {
  window.draw(sprite);
}

