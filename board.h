#pragma once

#include "constants.hpp"

extern int boardGrid[boardRows][boardCols];

void DrawBoard();
void DrawNextPiecesSpace();
void DrawDiceSpace();
void DrawStackedPieces();
bool isWall(int pos_x, int pos_y, int piece[], int cols);
bool isFloor(int pos_x, int pos_y, int piece[], int cols);
void LockPiece(int pos_x, int pos_y, int piece[], int cols);
int ClearLines();
