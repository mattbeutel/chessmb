//
// Created by xsens on 3/7/2025.
//
#include "definitions.h"
#include <iostream>

const int bitTable[64] = {
    63, 30, 3, 32, 25, 41, 22, 33, 15, 50, 42, 13, 11, 53, 19, 34, 61, 29, 2, 51, 21, 43, 45, 10, 18, 47, 1, 54, 9, 57, 0, 35, 62, 31, 40, 4, 49, 5, 52, 26, 60, 6, 23, 44, 46, 27, 16, 7, 39, 48, 24, 59, 14, 12, 55, 38, 28, 58, 20, 37, 17, 36, 8};

int popBit(U64* bitboard) {
    U64 bit = *bitboard ^ (*bitboard - 1);
    unsigned int fold = (unsigned) ((bit & 0xffffffff) ^ (bit >> 32));
    *bitboard &= (*bitboard - 1);
    return bitTable[(fold*0x783a9b23) >> 26];
}

int countBits(U64 bitboard) {
    int r;
    for(r = 0; bitboard; r++, bitboard &= bitboard - 1);
    return r;
}

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

