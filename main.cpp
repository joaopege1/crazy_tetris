#include "raylib.h"
#include "constants.hpp"
#include "tiles.h"
#include "board.h"
#include "game.h"
#include "pieces.hpp"
#include <cstdlib>
#include <ctime>


int main() {
    srand(time(0));
    SetTargetFPS(40);
    InitWindow(screenWidth, screenHeight, "Tetris Dice");

    while (!WindowShouldClose()) {

        DrawFPS(0,0);

        //----------------------------------------------------------------------------------
        //                                      Update
        //----------------------------------------------------------------------------------
        Gravity();
        MoveTile();
        //ShowPos();

        //----------------------------------------------------------------------------------
        //                                       Draw
        //----------------------------------------------------------------------------------

        BeginDrawing();
        ClearBackground(BLACK);
        DrawBoard();
        DrawNextPiecesSpace();
        DrawDiceSpace();
        DrawPieces(pieceList[r], 9, 3);
        SwitchPieces();
        //CreateTile();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
