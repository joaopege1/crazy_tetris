#pragma once

// SCREEN AND BOARD
const int screenWidth         = 720;
const int screenHeight        = 720;
const int rectWidth           = 360;
const int rectHeight          = 600;
const int midRectWidth        = (screenWidth - rectWidth) / 2;
const int midRectHeight       = (screenWidth - rectHeight) / 2;

//TILE SIZE AND MOVE
const int tileSize            = 40;
const int boardCenter         = midRectWidth + 160;
const int endOfBoard          = midRectHeight+15*40;

inline int tilePositionX      = boardCenter;
inline int tilePositionY      = midRectHeight;
