//
// Created by niall on 23/03/25.
//

#include "update_loop.h"
#include <SFML/Graphics.hpp>
#include "config.h"
#include "mouse.h"
#include "snake.h"

void update(sf::RenderWindow& window, snake &s, mouse &m) {
        window.clear();
        s.draw(window);
        m.draw(window);
    window.display();

    const std::string score = "score:  " + std::to_string(s.score);
    window.setTitle(score);

    s.move();
    s.checkCollision(WINDOW_SIZE, m.getLocation());
    if (s.grow) {
        m.spawn(s.getLocation());
    }

    if (s.dead) {
        window.close();
    }
}

