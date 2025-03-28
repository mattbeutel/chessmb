//
// Created by xsens on 3/24/2025.
//
#include <cstdio>

#include "definitions.h"

U64 generatePositionKey(const BOARD_STRUCTURE *pos) {

    U64 finalKey  = 0;
    int piece = EMPTY;

    for (int sq = 0; sq < BRD_SQ_NUM; sq++) {
        piece = pos->pieces[sq];
        if (piece != NO_SQ && piece != EMPTY) {
            ASSERT(piece >= whitePAWN && piece <= blackKING);
            finalKey ^= pieceKeys[piece][sq];
        }
    }

    if (pos->sideToMove == WHITE ) {
        finalKey ^= sideKey;
    }

    if (pos->enPassant != NO_SQ) {
        ASSERT(pos->enPassant >= 0 && pos->enPassant < BRD_SQ_NUM);
        finalKey ^= pieceKeys[EMPTY][pos->enPassant];
    }

    ASSERT(pos->castlePermission >= 0 && pos->castlePermission <= 15);

    finalKey ^= castleKeys[pos->castlePermission];

    return finalKey;
}