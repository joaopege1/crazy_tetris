#include "raylib.h"
#include "tiles.h"
#include "constants.hpp"
#include "board.h"
#include "pieces.hpp"
#include <cstdio>

void CreateTile() {
  DrawRectangle(piecePositionX, piecePositionY, tileSize,tileSize, LIGHTGRAY);
}

void DrawPieces(int array[], int size, int cols) {                             
  int x = piecePositionX;                                                      
  int y = piecePositionY;                                                      
                                                                              
  for (int i = 0; i < size; i++) {                                            
    if (array[i] == 1) {
      DrawRectangle(x, y, tileSize, tileSize, LIGHTGRAY);                     
    }                                                                       
    if ((i + 1) % cols == 0) {                                                
      x = piecePositionX;                                                      
      y += tileSize;                                                          
    } else {
      x += tileSize;                                                          
    }                                                                       
  }
}

void MoveTile() {

  if (IsKeyDown(KEY_RIGHT)) {                                                 
      if (!isWall(piecePositionX + tileSize, piecePositionY, pieceList[r], 3)) {                   
          piecePositionX += tileSize;
      }                                                                         
  }                                                                            
  if (IsKeyDown(KEY_LEFT)){
      if (!isWall(piecePositionX - tileSize, piecePositionY, pieceList[r], 3)){
          piecePositionX -= tileSize;
      }
    }

  if (IsKeyDown(KEY_UP))      piecePositionY -= tileSize; // This will be used to rotate the piece in the future.
  
  if (IsKeyDown(KEY_DOWN)){
      if (!isWall(piecePositionX, piecePositionY + tileSize, pieceList[r], 3)){
      piecePositionY += tileSize;
    }
  }

  if (IsKeyDown(KEY_SPACE))   piecePositionY =  endOfBoard - tileSize;
}

void ShowPos() {                                                              
  static int lastX = piecePositionX;
  static int lastY = piecePositionY;                                           
  if (lastX != piecePositionX || lastY != piecePositionY) {                   
    printf("%d %d\n", piecePositionX, piecePositionY);                          
    lastX = piecePositionX;
    lastY = piecePositionY;                                                    
  }                                                                           
}

