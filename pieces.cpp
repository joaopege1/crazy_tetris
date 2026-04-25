#include <cstdlib>
#include "pieces.hpp"

//RANDOM 
int r = rand() % 5;


//MAIN PIECE
int tpieceMain[9] = {
    0,1,0,
    1,1,1,
    0,0,0
};

//VARIANTS
int tpieceRight[9] = {
    0,1,0,
    0,1,1,
    0,1,0
};

int tpieceLeft[9] = {
    0,1,0,
    1,1,0,
    0,1,0
};

int tpieceDown[9] = {
    0,0,0,
    1,1,1,
    0,1,0
};

//MAIN PIECE
int snakeMain[9] = {
    0,0,0,
    1,1,1,
    0,0,0
};

//VARIANTS
int snakeSide[9] = {
    0,1,0,
    0,1,0,
    0,1,0
};

//MAIN PIECE
int spieceRight[9] = {
    0,1,1,
    1,1,0,
    0,0,0
};

//VARIANTS
int spieceRightVertical[9] = {
    1,0,0,
    1,1,0,
    0,1,0
};

//MAIN PIECE
int spieceLeft[9] = {
    1,1,0,
    0,1,1,
    0,0,0
};

//VARIANTS
int spieceLeftVertical[9] = {
    0,1,0,
    1,1,0,
    1,0,0
};

//MAIN PIECE
int lpieceRight[9] = {
    0,1,0,
    0,1,0,
    0,1,1
};

//VARIANTS
int lpieceRightDown[9] = {
    0,0,0,
    1,1,1,
    1,0,0
};

int lpieceRightLeft[9] = {
    1,1,0,
    0,1,0,
    0,1,0
};

int lpieceRightUp[9] = {
    0,0,1,
    1,1,1,
    0,0,0
};

//MAIN PIECE
int lpieceLeft[9] = {
    0,1,0,
    0,1,0,
    1,1,0
};

//VARIANTS
int lpieceLeftDown[9] = {
    1,0,0,
    1,1,1,
    0,0,0
};

int lpieceLeftRight[9] = {
    0,1,1,
    0,1,0,
    0,1,0
};

int lpieceLeftUp[9] = {
    0,0,0,
    1,1,1,
    0,0,1
};


// array 2D: cada linha é uma peça
int pieceList[5][9] = {                                                       
  {0,1,0, 1,1,1, 0,0,0},  // snakeMain                                    
  {1,1,0, 0,1,1, 0,0,0},  // spieceRight                                    
  {0,1,1, 1,1,0, 0,0,0},  // spieceLeft                                     
  {1,0,0, 1,1,1, 0,0,0},  // lpieceRight                                    
  {0,0,1, 1,1,1, 0,0,0},  // lpieceLeft                                     
};       
