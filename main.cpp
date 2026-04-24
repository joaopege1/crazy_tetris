#include "raylib.h"
#include "constants.hpp"
#include "tiles.h"
#include "board.h"
#include "game.h"

int test[9] = {
    0,1,0,
    1,1,1,
    0,0,0
};

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
        RealTiles(test, 9, 3);

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
