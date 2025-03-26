//
// Created by niall on 24/03/25.
//
#ifndef MOUSE_H
#define MOUSE_H
#include "SFML/Graphics.hpp"
#include "vector"
#include "config.h"

class mouse {
public:

    explicit mouse();

    void spawn(const std::vector<sf::Vector2i>& snakeGridPosition); // spawn away from the snake
    void draw(sf::RenderWindow& window) const;

    [[nodiscard]] sf::Vector2i getLocation() const { return gridPosition; }

private:
    sf::CircleShape shape;
    sf::Vector2i gridPosition;
};

#endif //MOUSE_H
