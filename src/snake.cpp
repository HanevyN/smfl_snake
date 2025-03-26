//
// Created by niall on 20/03/25.
//
#include "snake.h"
#include <SFML/Graphics.hpp>
#include "config.h"

snake::snake(){
    sf::Vector2i middle = {WINDOW_SIZE/2, WINDOW_SIZE/2};

    this->Direction = sf::Vector2i(1, 0);
    // Grid positions
    gridPosition = {
        middle,
        middle - sf::Vector2i(1, 0),
        middle - sf::Vector2i(2, 0)
    };
}

void snake::move() {
    if (grow) {
        gridPosition.push_back(gridPosition.back());  // duplicate tail
        grow = false;
    }
    for (int i = static_cast<int>(gridPosition.size()) - 1; i > 0; --i) {
    gridPosition[i] = gridPosition[i - 1];
   }
    gridPosition[0] += Direction;
}


void snake::checkCollision(const int window_size, const sf::Vector2i mouseGridPosition) {
  if ( (this->gridPosition[0].x  >= window_size) || (this->gridPosition[0].y  >= window_size)
  || ( (this->gridPosition[0].x  < 0) ||           (this->gridPosition[0].y  < 0)) ) {
    this->dead = true;
  }
  // check for self intersection
  for (int i = 1; i < gridPosition.size(); i++) {
    if (gridPosition[0] == gridPosition[i]) {
      this->dead = true;
    }
  }
// check for mouse eating
    if (this->gridPosition[0] == mouseGridPosition) {
        this->score += 1;
        this->grow = true;
    }
}

void snake::updateDirection(const sf::Keyboard::Scancode scan)  {
  sf::Vector2i newDirection = {0, 0};
  switch (scan) {
    case sf::Keyboard::Scancode::Left:  newDirection = {-1, 0}; break;
    case sf::Keyboard::Scancode::Right: newDirection = { 1, 0}; break;
    case sf::Keyboard::Scancode::Up:    newDirection = { 0,-1}; break;
    case sf::Keyboard::Scancode::Down:  newDirection = { 0, 1}; break;
    default: return; // ignore unrecognised keys
  }

    if (newDirection + this->Direction != sf::Vector2i(0, 0)) {
        this->Direction = newDirection;
    }
}

void snake::draw(sf::RenderWindow &window) const {
  for (size_t i = 0; i < gridPosition.size(); ++i) {
    auto shape = createSegment(gridPosition[i], i == 0);
    window.draw(shape);
  }
}

sf::RectangleShape snake::createSegment(const sf::Vector2i gridPos, const bool isHead) {
    sf::RectangleShape part(sf::Vector2f(DEFAULT_CELL_SIZE, DEFAULT_CELL_SIZE));
    part.setFillColor(isHead ? SNAKE_HEAD_COLOR: SNAKE_BODY_COLOR);
    part.setPosition(sf::Vector2f(gridPos * DEFAULT_CELL_SIZE));
    return part;
  }




