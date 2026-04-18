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
