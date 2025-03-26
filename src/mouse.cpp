//
// Created by niall on 24/03/25.
//

#include "mouse.h"

#include <iostream>
#include <random>


mouse::mouse()
    : shape(DEFAULT_CELL_SIZE / 2.f) {
      shape.setFillColor(sf::Color::Yellow);
}

void mouse::spawn(const std::vector<sf::Vector2i>& snakeGridPosition) {
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1,WINDOW_SIZE-1);

    bool intersection = true;
    while (intersection) {
      intersection = false;
      this->gridPosition = sf::Vector2i(dis(gen), dis(gen)) ;
      this ->shape.setPosition(sf::Vector2f(this->gridPosition*DEFAULT_CELL_SIZE));

        for (const auto & i : snakeGridPosition) {
            if( this->gridPosition == i ) {
                intersection = true;
                break;
            }
        }
    }
}


void mouse::draw(sf::RenderWindow &window) const {
    window.draw(this->shape);
}


