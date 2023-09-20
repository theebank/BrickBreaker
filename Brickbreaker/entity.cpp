//
//  entity.cpp
//  Brickbreaker
//
//  Created by Theeban Kumaresan on 2023-09-19.
//

#include "entity.h"
#include "constants.h"

sf::FloatRect entity::get_bounding_box() const noexcept {
    return sprite.getGlobalBounds();
}
sf::Vector2f entity::get_center() const noexcept {
    auto box = get_bounding_box();
    return {box.width/2.0f,box.height/2.0f};
}
float entity::x() const noexcept {
    auto box = sprite.getPosition();
    return box.x;
}
float entity::y() const noexcept {
    auto box = sprite.getPosition();
    return box.y;
}
float entity::left() const noexcept {
    auto box = get_bounding_box();
    return x()-box.width/2.0f;
}
float entity::right() const noexcept {
    auto box = get_bounding_box();
    return x()+box.width/2.0f;
}
float entity::top() const noexcept {
    auto box = get_bounding_box();
    return y()-box.height/2.0f;
}
float entity::bottom() const noexcept {
    auto box = get_bounding_box();
    return y()+box.height/2.0f;
}
void entity::destroy() noexcept{destroyed =true;}
bool entity::is_destroyed() const noexcept{return destroyed;}
