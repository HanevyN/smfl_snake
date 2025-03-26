//
// Created by niall on 20/03/25.
//

#ifndef SNAKE_H
#define SNAKE_H
#include <vector>
#include "SFML/Graphics.hpp"

class snake {
    sf::Vector2i Direction;
    std::vector<sf::Vector2i> gridPosition;

public:
    bool dead = false;
    bool grow = false;
    int score = 0;

    explicit snake();
    // Getter for body (optional, if you need access outside the class)
    [[nodiscard]] std::vector<sf::Vector2i> getLocation() const { return gridPosition; }

    void move();

    void checkCollision(int window_size, sf::Vector2i mouseGridPosition);
    void updateDirection(sf::Keyboard::Scancode scan) ;

    void draw(sf::RenderWindow& window) const;

    static sf::RectangleShape createSegment(sf::Vector2i gridPos, bool isHead);
};

#endif //SNAKE_H
