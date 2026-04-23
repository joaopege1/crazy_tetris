#include "board.h"
#include "constants.hpp"
#include "raylib.h"


void DrawBoard() {
    DrawRectangleLines(midRectWidth, midRectHeight, rectWidth, rectHeight, WHITE);
    for (int i = midRectWidth; i < midRectWidth + rectWidth; i += tileSize) {
        for (int z = midRectHeight; z < midRectHeight + rectHeight; z += tileSize) {
            DrawRectangleLines(i, z, tileSize, tileSize, WHITE);
        }
    }
}


//o x Nao pode ser menor que 180
//o x Nao pode ser maior que 500
//o y Nao pode ser maior que 620

bool isWall(int pos_x, int pos_y) {                                         
  if (pos_x > 500 || pos_x < 180) return true;                              
  if (pos_y >= endOfBoard) return true;
  return false;                                                             
}   
