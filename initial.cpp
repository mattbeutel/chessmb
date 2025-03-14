//
// Created by xsens on 3/6/2025.
//

#include "definitions.h"

int Sq120ToBoardSquare[BRD_SQ_NUM];
int boardSquareToSq120[64];

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
}