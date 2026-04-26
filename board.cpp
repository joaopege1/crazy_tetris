#include "board.h"
#include "constants.hpp"
#include "raylib.h"


void DrawBoard() {
    DrawText("DICE TETRIS!", midRectWidth, midRectHeight-15, 15, WHITE);
    DrawRectangleLines(midRectWidth, midRectHeight, rectWidth, rectHeight, WHITE);
    for (int i = midRectWidth; i < midRectWidth + rectWidth; i += tileSize) {
        for (int z = midRectHeight; z < midRectHeight + rectHeight; z += tileSize) {
            DrawRectangleLines(i, z, tileSize, tileSize, WHITE);
        }
    }
}

// For the next piece
void DrawNextPiecesSpace() {
    DrawText("PLAYER TURN!", nextTileXPos, midRectHeight-15, 15, WHITE);
    DrawRectangleLines(nextTileXPos, midRectHeight, nextTileHeight, nextTileWidth, WHITE);
    DrawRectangleLines(nextTileXPos + 10, midRectHeight + 10, 110, 100, WHITE);
    DrawRectangleLines(nextTileXPos + 10, midRectHeight + 140, 110, 100, WHITE);

}

void DrawDiceSpace() {
    DrawText("DICE!", diceXPos, diceYPos-20, 20, WHITE);
    DrawRectangleLines(diceXPos, diceYPos, diceHeight, diceWidth, WHITE);
}

bool isWall(int pos_x, int pos_y, int piece[], int cols) {
  for (int i = 0; i < 9; i++) {
    if (piece[i] == 1) {
      int col = i % cols;
      int row = i / cols;
      int tileX = pos_x + col * tileSize;
      int tileY = pos_y + row * tileSize;

      if (tileX < midRectWidth) return true;
      if (tileX + tileSize > midRectWidth + rectWidth) return true;
      if (tileY + tileSize > endOfBoard) return true;
    }
  }
  return false;
}   
