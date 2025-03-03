//
// Created by xsens on 3/3/2025.
//

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

typedef unsigned long long U64;
#define NAMEW "ChessMB"
#define BRD_SQ_NUM 120

enum { EMPTY, whitePAWN, whiteKNIGHT, whiteBISHOP, whiteROOK, whiteQUEEN, whiteKING, blackPAWN, blackKNIGHT, blackBISHOP, blackROOK, blackQUEEN, blackKING };
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };

enum { WHITE, BLACK, BOTH };

enum {
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8,
    NO_SQ
};

enum { FALSE, TRUE };

typedef struct {
    int pieces[BRD_SQ_NUM];
    U64 pawns[3]; //bitboards for white, black, and all pawns

    int KingSquare[2]; //keeps track of which squares the kings are on

    /*
        Basic game structure trackers
    */
    int sideToMove;
    int enPassant;
    int fiftyMoves;

    int play;
    int playHistory;

    U64 positionKey;

    int pieceNumber[13];
    int bigPieces[3]; //non-pawns
    int majorPieces[3]; //rooks, queens
    int minorPieces[3]; //bishops, knights
} BOARD_STRUCTURE;

#endif //DEFINITIONS_H
