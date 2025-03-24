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

    U64 playBitboard = 0ULL;

    playBitboard |= (1ULL << SQ64(D2));
    playBitboard |= (1ULL << SQ64(D3));
    playBitboard |= (1ULL << SQ64(D4));

    std::cout << std::endl;
    printBitboard(playBitboard);

    int count = CNT(playBitboard);

    std::cout << "Count: " << count << std::endl;

    int index = POP(&playBitboard);

    return 0;
}

