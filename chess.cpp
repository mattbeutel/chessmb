//
// Created by xsens on 2/26/2025.
//

#include "chess.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>

int main() {
    std::cout << "Hello World!\n";
    sf::RenderWindow board(sf::VideoMode({800, 800}), "ChessMB");
    while (board.isOpen()) {
        sf::Event event;
        while (board.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                board.close();
            }
        }
    }
    return 0;
}