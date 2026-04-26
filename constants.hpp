#pragma once

// SCREEN AND BOARD
  // MAIN BOARD
const int screenWidth         = 720;
const int screenHeight        = 720;
const int rectWidth           = 360;
const int rectHeight          = 600;
const int midRectWidth        = (screenWidth - rectWidth) / 2;
const int midRectHeight       = (screenWidth - rectHeight) / 2;
const int boardCenter         = midRectWidth + 160;
const int endOfBoard          = midRectHeight+15*40;

  // NEXT TILE RECT
const int nextTileXPos        = midRectWidth + 370;
const int nexTileYPos         = midRectHeight;
const int nextTileHeight      = 130;
const int nextTileWidth       = 250;


  // DICE SPACE RECT
const int diceXPos            = 70;
const int diceYPos            = 560;
const int diceHeight          = 100;
const int diceWidth           = 100;

//TILE SIZE AND MOVE
const int tileSize            = 40;

inline int piecePositionX      = boardCenter;
inline int piecePositionY      = midRectHeight;

// GRAVITY
inline int frameCounter = 0;
