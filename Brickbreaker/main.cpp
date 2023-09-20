#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include <string>
#include "constants.h"
#include "background.hpp"
#include "ball.hpp"
#include "interactions.hpp"
#include "paddle.hpp"
#include "brick.hpp"

#include "game.hpp"



int main() {
    game game;
    game.reset();
    game.run();
}
