//
// Created by xsens on 3/3/2025.
//

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "stdlib.h"

#define DEBUG
//For debugging purposes
#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n) \
if (!(n)) { \
printf("%s - Failed", #n); \
printf("On %s ", __DATE__); \
printf("At %s ", __TIME__); \
printf("In File %s ", __FILE__); \
printf("At Line %d\n", __LINE__); \
exit(1);}
#endif

typedef unsigned long long U64; //64-bit integers (mainly used for bitboards)
#define NAMEW "ChessMB"
#define BRD_SQ_NUM 120
#define FR2SQ(f,r) ( ( 21 + (f) ) + ( (r) * 10) ) //f: file; r: rank; macro for converting from file/rank to 120-base
#define SQ64(sq120) Sq120ToBoardSquare[sq120] //macro to shorten typing out the conversion method
#define POP(b) popBit(b)
#define CNT(b) countBits(b)
#define CLRBIT(bb,sq) ( (bb) &= clearMask[(sq)])
#define SETBIT(bb,sq) ( (bb) |= setMask[(sq)])
#define MAXGAMEMOVES 2048 //Safe estimate for longest possible game

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

enum { WHITEKINGCASTLING = 1, WHITEQUEENCASTLING = 2, BLACKKINGCASTLING = 4, BLACKQUEENCASTLING = 8 }; //Bitwise representation for castling permission

typedef struct {
    int move;
    int castlePermission;
    int enPassant;
    int fiftyMoves;
    U64 positionKey;
} UNDO;

typedef struct {
    int pieces[BRD_SQ_NUM];
    U64 pawns[3]; //black, white, and all pawns on the board

    int KingSquare[2]; //keeps track of which squares the kings are on

    /*
        Basic game structure trackers. Draw conditions, special moves, etc.
    */
    int sideToMove;
    int enPassant;
    int fiftyMoves;

    int play;
    int playHistory;

    int castlePermission;

    U64 positionKey;

    int pieceNumber[13];
    int bigPieces[3]; //non-pawns
    int majorPieces[3]; //rooks, queens
    int minorPieces[3]; //bishops, knights

    UNDO history[MAXGAMEMOVES];

    //piece list, up to 10 of each piece for extreme case handling (i.e., converting all 8 pawns to rooks)
    int pieceList[13][10];
} BOARD_STRUCTURE;



//Converting back and forth between 120 base layout to 64 squares on an actual chessboard.
extern int Sq120ToBoardSquare[BRD_SQ_NUM];
extern int boardSquareToSq120[64];
extern U64 setMask[64];
extern U64 clearMask[64];
extern U64 pieceKeys[13][120];
extern U64 sideKey;
extern U64 castleKeys[16];


extern void allInit();

extern void printBitboard(U64 bitboard);
extern int popBit(U64 *bitboard);
extern int countBits(U64 bitboard);

extern U64 generatePositionKey(const BOARD_STRUCTURE *pos);
#endif //DEFINITIONS_H
