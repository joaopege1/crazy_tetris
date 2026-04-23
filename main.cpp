#include "raylib.h"
#include "constants.hpp"
#include "tiles.h"
#include "board.h"

int main() {
    SetTargetFPS(40);
    InitWindow(screenWidth, screenHeight, "Tetris Dice");

    while (!WindowShouldClose()) {

        //----------------------------------------------------------------------------------
        //                                      Update
        //----------------------------------------------------------------------------------
        MoveTile();
        ShowPos();


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
