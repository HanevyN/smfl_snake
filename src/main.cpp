#include <iostream>
#include <SFML/Graphics.hpp>
#include "snake.h"
#include "mouse.h"
#include "update_loop.h"


int main() {
  // Setting up the window
    sf::RenderWindow window(sf::VideoMode({WINDOW_FRAME, WINDOW_FRAME}), "Snake Game");
    window.setFramerateLimit(5);
    // #Initialising the Snake
    snake s;
    mouse m;

    m.spawn( s.getLocation() );

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()){
            if (event->is<sf::Event::Closed>())
                window.close();
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                s.updateDirection( keyPressed->scancode);
            }
        }
        update(window, s,m);
    }
    return 0;
    }
