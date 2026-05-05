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
      DrawRectangle(x, y, tileSize, tileSize, BLUE);                     
    }                                                                       
    if ((i + 1) % cols == 0) {                                                
      x = piecePositionX;                                                      
      y += tileSize;                                                          
    } else {
      x += tileSize;                                                          
    }                                                                       
  }
}

// DAS: primeiro toque move imediato; segurando, espera DAS frames
// e depois repete a cada ARR frames. A 40 FPS: ~200ms espera, ~50ms repeat.
static const int DAS = 8;
static const int ARR = 2;

static bool autoRepeat(int &holdFrames, bool keyDown) {
  bool fire = false;
  if (keyDown) {
    if (holdFrames == 0) fire = true;
    else if (holdFrames >= DAS && (holdFrames - DAS) % ARR == 0) fire = true;
    holdFrames++;
  } else {
    holdFrames = 0;
  }
  return fire;
}

void MoveTile() {
  static int leftHold = 0, rightHold = 0, downHold = 0;

  if (autoRepeat(rightHold, IsKeyDown(KEY_RIGHT))) {
      if (!isWall(piecePositionX + tileSize, piecePositionY, pieceList[r][rot], 3) &&
          !isFloor(piecePositionX + tileSize, piecePositionY, pieceList[r][rot], 3)) {
          piecePositionX += tileSize;
      }
  }
  if (autoRepeat(leftHold, IsKeyDown(KEY_LEFT))) {
      if (!isWall(piecePositionX - tileSize, piecePositionY, pieceList[r][rot], 3) &&
          !isFloor(piecePositionX - tileSize, piecePositionY, pieceList[r][rot], 3)){
          piecePositionX -= tileSize;
      }
  }

  if (IsKeyPressed(KEY_UP)) {
      int oldRot = rot;
      rot = (rot + 1) % 4;
      if (isWall(piecePositionX, piecePositionY, pieceList[r][rot], 3) ||
          isFloor(piecePositionX, piecePositionY, pieceList[r][rot], 3)) {
          rot = oldRot;
      }
  }

  if (autoRepeat(downHold, IsKeyDown(KEY_DOWN))) {
      if (!isWall(piecePositionX, piecePositionY + tileSize, pieceList[r][rot], 3) &&
          !isFloor(piecePositionX, piecePositionY + tileSize, pieceList[r][rot], 3)){
          piecePositionY += tileSize;
      }
  }

  if (IsKeyPressed(KEY_SPACE)){
      while (!isWall(piecePositionX, piecePositionY + tileSize, pieceList[r][rot], 3) &&
             !isFloor(piecePositionX, piecePositionY + tileSize, pieceList[r][rot], 3)){
          piecePositionY += tileSize;
      }
  }
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

