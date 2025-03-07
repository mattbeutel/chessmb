//
// Created by xsens on 3/7/2025.
//
#include "definitions.h"
#include <iostream>

void printBitboard(U64 bitboard) {
    std::cout << std::endl;
    for(int rank = RANK_8; rank >= RANK_1; rank--) {
        for(int file = FILE_A; file <= FILE_H; file++) {
            if(1ULL << SQ64(FR2SQ(file, rank)) & bitboard) { //Determining if a piece is at the position in the bitboard
                std::cout << "X";
            }
            else {
                std::cout << "-";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}