//
// Created by xsens on 3/6/2025.
//

#include "definitions.h"

//generating random 64 bit number
#define RAND_64 ( (U64) rand() + \
                  (U64) rand() << 15 + \
                  (U64) rand() << 30 + \
                  (U64) rand() << 45 + \
                  ((U64) rand() & 0xf) << 60)

int Sq120ToBoardSquare[BRD_SQ_NUM];
int boardSquareToSq120[64];

U64 setMask[64];
U64 clearMask[64];

U64 pieceKeys[13][120];
U64 sideKey;
U64 castleKeys[16];

void initializeHashKeys() {
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 120; j++) {
            pieceKeys[i][j] = RAND_64;
        }
    }
    sideKey = RAND_64;
    for (int i = 0; i < 16; i++) {
        castleKeys[i] = RAND_64;
    }
}

void initializeBitMasks() {
    for(int index = 0; index < 64; index++) {
        setMask[index] = 0ULL;
        clearMask[index] = 0ULL;
    }
    for(int index = 0; index < 64; index++) {
        setMask[index] |= (1ULL << index);
        clearMask[index] = ~setMask[index];
    }
}

void initialize120toBoardSquare() {
    for (int i = 0; i < BRD_SQ_NUM; i++) {
        Sq120ToBoardSquare[i] = 65;
    }
    for (int i = 0; i < 64; i++) {
        boardSquareToSq120[i] = 120;
    }
    int sq64 = 0;
    for(int rank = RANK_1; rank <= RANK_8; rank++) {
        for(int file = FILE_A; file <= FILE_H; file++) {
            int sq = FR2SQ(rank, file);
            boardSquareToSq120[sq64] = sq;
            Sq120ToBoardSquare[sq] = sq64++;
        }
    }
}
void allInit() {
    initialize120toBoardSquare();
    initializeBitMasks();
    initializeHashKeys();
}