#include "raylib.h"
#include "constants.hpp"
#include "tiles.h"
#include "board.h"
#include "game.h"
#include "pieces.hpp"


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
        RealTiles(pieceList[1], 9, 3);

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
