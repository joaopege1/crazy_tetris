#include "raylib.h"
#include "constants.hpp"
#include "tiles.h"
#include "board.h"
#include "game.h"
#include "pieces.h"

int main() {
    SetTargetFPS(40);
    InitWindow(screenWidth, screenHeight, "Tetris Dice");

    while (!WindowShouldClose()) {

        //----------------------------------------------------------------------------------
        //                                      Update
        //----------------------------------------------------------------------------------
        Gravity();
        MoveTile();
        ShowPos();
        RealTiles(lpieceLeft, 9, 3);

        //----------------------------------------------------------------------------------
        //                                       Draw
        //----------------------------------------------------------------------------------

        BeginDrawing();
        ClearBackground(BLACK);
        DrawBoard();
        DrawNextTilesSpace();
        //CreateTile();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
