#include "raylib.h"
#include "tiles.h"
#include "constants.hpp"
#include "board.h"
#include "game.h"
#include "pieces.hpp"
#include <cstdlib>

void Gravity(){                                                  
  frameCounter++;                                                               
                                                                                
  if (frameCounter >= 20) {             
      if (!isWall(piecePositionX, piecePositionY + tileSize, pieceList[r], 3)) {                   
          piecePositionY += tileSize;                                           
      }                                                                         
      frameCounter = 0;                                                         
  }
}

void SwitchPieces(){
  if (isWall(piecePositionX, piecePositionY + tileSize, pieceList[r], 3)) {
    int lastR = r;
    while (r == lastR) {
      r = rand() % 5;
    }
    piecePositionX = boardCenter;
    piecePositionY = midRectHeight;
  }
}
