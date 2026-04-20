#include "raylib.h"
#include "constants.hpp"
#include "tiles.h"
#include "board.h"

int main() {
    SetTargetFPS(60);
    InitWindow(screenWidth, screenHeight, "This is a Window");

    while (!WindowShouldClose()) {

        //                                      Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT)) tilePositionX += 2.0f;
        if (IsKeyDown(KEY_LEFT)) tilePositionX -= 2.0f;
        if (IsKeyDown(KEY_UP)) tilePositionY -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) tilePositionY += 2.0f;

        //----------------------------------------------------------------------------------

        //                                       Draw
        //----------------------------------------------------------------------------------

        BeginDrawing();
        ClearBackground(BLACK);
        DrawBoard();
        CreateTile();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
