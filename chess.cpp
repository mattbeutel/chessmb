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
        createChessBoard(board);
        sf::Event event;
        while (board.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                board.close();
            }
        }
    }
    return 0;
}

void createChessBoard(sf::RenderWindow &board) {
    for (int file = 0; file < 8; file++) {
        for (int rank = 0; rank < 8; rank++) {
            bool isLightSquare = (file + rank) % 2 != 0;
            sf::Color color = (isLightSquare) ? sf::Color::White : sf::Color::Cyan;
            sf::Vector2f position(-3.5f + file, -3.5f + rank);
            sf::RectangleShape tile(position);
            tile.setFillColor(color);
            board.draw(tile);
        }
    }
}
