#include "raylib.h"
#include "tiles.h"
#include "constants.hpp"
#include "board.h"
#include <cstdio>

void CreateTile() {
  DrawRectangle(tilePositionX, tilePositionY, tileSize,tileSize, LIGHTGRAY);
}

void MoveTile() {

  if (IsKeyDown(KEY_RIGHT)) {                                                 
      if (!isWall(tilePositionX + tileSize, tilePositionY)) {                   
          tilePositionX += tileSize;
      }                                                                         
  }                                                                            
  if (IsKeyDown(KEY_LEFT)){
      if (!isWall(tilePositionX - tileSize, tilePositionY)){
          tilePositionX -= tileSize;
      }
    }

  if (IsKeyDown(KEY_UP))      tilePositionY -= tileSize; // This will be used to rotate the piece in the future.
  
  if (IsKeyDown(KEY_DOWN)){
      if (!isWall(tilePositionX, tilePositionY + tileSize)){
      tilePositionY += tileSize;
    }
  }

  if (IsKeyDown(KEY_SPACE))   tilePositionY =  endOfBoard;
}

void ShowPos() {                                                              
  static int lastX = tilePositionX;
  static int lastY = tilePositionY;                                           
  if (lastX != tilePositionX || lastY != tilePositionY) {                   
    printf("%d %d\n", tilePositionX, tilePositionY);                          
    lastX = tilePositionX;
    lastY = tilePositionY;                                                    
  }                                                                           
}
