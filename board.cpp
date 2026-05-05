#include "board.h"
#include "constants.hpp"
#include "raylib.h"

int boardGrid[boardRows][boardCols] = {};


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

void DrawStackedPieces() {
    for (int row = 0; row < boardRows; row++) {
        for (int col = 0; col < boardCols; col++) {
            if (boardGrid[row][col] == 1) {
                int x = midRectWidth + col * tileSize;
                int y = midRectHeight + row * tileSize;
                DrawRectangle(x, y, tileSize, tileSize, GRAY);
            }
        }
    }
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

bool isFloor(int pos_x, int pos_y, int piece[], int cols) {
  for (int i = 0; i < 9; i++) {
    if (piece[i] == 1) {
      int col = i % cols;
      int row = i / cols;
      int tileX = pos_x + col * tileSize;
      int tileY = pos_y + row * tileSize;

      int gridCol = (tileX - midRectWidth) / tileSize;
      int gridRow = (tileY - midRectHeight) / tileSize;

      if (gridRow < 0) continue;
      if (gridRow >= boardRows) return true;
      if (gridCol < 0 || gridCol >= boardCols) continue;
      if (boardGrid[gridRow][gridCol] == 1) return true;
    }
  }
  return false;
}

void LockPiece(int pos_x, int pos_y, int piece[], int cols) {
  for (int i = 0; i < 9; i++) {
    if (piece[i] == 1) {
      int col = i % cols;
      int row = i / cols;
      int tileX = pos_x + col * tileSize;
      int tileY = pos_y + row * tileSize;

      int gridCol = (tileX - midRectWidth) / tileSize;
      int gridRow = (tileY - midRectHeight) / tileSize;

      if (gridRow >= 0 && gridRow < boardRows &&
          gridCol >= 0 && gridCol < boardCols) {
        boardGrid[gridRow][gridCol] = 1;
      }
    }
  }
}

int ClearLines() {
  int linesCleared = 0;
  for (int row = boardRows - 1; row >= 0; row--) {
    bool full = true;
    for (int col = 0; col < boardCols; col++) {
      if (boardGrid[row][col] == 0) { full = false; break; }
    }
    if (full) {
      for (int r = row; r > 0; r--) {
        for (int col = 0; col < boardCols; col++) {
          boardGrid[r][col] = boardGrid[r - 1][col];
        }
      }
      for (int col = 0; col < boardCols; col++) boardGrid[0][col] = 0;
      linesCleared++;
      row++;
    }
  }
  return linesCleared;
}
