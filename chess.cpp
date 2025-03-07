//
// Created by xsens on 2/26/2025.
//

#include "chess.h"
#include "definitions.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <optional>

int main() {
    allInit();
    /*
    for(int index = 0; index < BRD_SQ_NUM; index++) {
        if (index % 10 == 0) {
            std::cout << std::endl;
        }
        printf("%5d", Sq120ToBoardSquare[index]);
    }
    std::cout << std::endl << std::endl;
    for(int index = 0; index < 64; index++) {
        if (index % 8 == 0) {
            std::cout << std::endl;
        }
        printf("%5d", boardSquareToSq120[index]);
    }
    */
    U64 playBitboard = 0ULL;
    std::cout << "Start:\n\n";
    printBitboard(playBitboard);
    playBitboard |= (1ULL << SQ64(D2));
    std::cout << "D2 added:\n\n";
    printBitboard(playBitboard);
    return 0;
}

