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
        if (!gameOver) {
            Gravity();
            MoveTile();
        }
        //ShowPos();

        //----------------------------------------------------------------------------------
        //                                       Draw
        //----------------------------------------------------------------------------------

        BeginDrawing();
        ClearBackground(BLACK);
        DrawBoard();
        DrawStackedPieces();
        if (!gameOver) {
            DrawPieces(pieceList[r][rot], 9, 3);
            SwitchPieces();
        }
        DrawNextPiecesSpace();
        DrawDiceSpace();

        if (gameOver) {
            DrawRectangle(midRectWidth, midRectHeight + rectHeight/2 - 50,
                          rectWidth, 100, Fade(BLACK, 0.85f));
            const char* msg = "GAME OVER";
            int fontSize = 40;
            int textW = MeasureText(msg, fontSize);
            DrawText(msg,
                     midRectWidth + (rectWidth - textW) / 2,
                     midRectHeight + rectHeight/2 - fontSize/2,
                     fontSize, RED);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
