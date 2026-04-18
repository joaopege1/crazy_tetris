#include "raylib.h"
#include "constants.hpp"
#include "board.h"

int main() {
    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "This is a Window");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);
        DrawBoard();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
