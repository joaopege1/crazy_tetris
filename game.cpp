#include "raylib.h"
#include "tiles.h"
#include "constants.hpp"
#include "board.h"
#include "game.h"
#include "pieces.hpp"
#include <cstdlib>

bool gameOver = false;

void Gravity(){
  if (gameOver) return;
  frameCounter++;

  if (frameCounter >= 20) {
      if (!isWall(piecePositionX, piecePositionY + tileSize, pieceList[r][rot], 3) &&
          !isFloor(piecePositionX, piecePositionY + tileSize, pieceList[r][rot], 3)) {
          piecePositionY += tileSize;
      }
      frameCounter = 0;
  }
}

void SwitchPieces(){
  if (gameOver) return;

  bool hitWall  = isWall(piecePositionX, piecePositionY + tileSize, pieceList[r][rot], 3);
  bool hitFloor = isFloor(piecePositionX, piecePositionY + tileSize, pieceList[r][rot], 3);

  if (hitWall || hitFloor) {
    LockPiece(piecePositionX, piecePositionY, pieceList[r][rot], 3);
    ClearLines();

    int lastR = r;
    while (r == lastR) {
      r = rand() % 5;
    }
    rot = 0;
    piecePositionX = boardCenter;
    piecePositionY = midRectHeight - tileSize;

    if (isGameOver(piecePositionX, piecePositionY, pieceList[r][rot])) {
      gameOver = true;
    }
  }
}

// Game over
bool isGameOver(int piecePositionX, int piecePositionY, int piece[]) {
  return isFloor(piecePositionX, piecePositionY, piece, 3);
}
