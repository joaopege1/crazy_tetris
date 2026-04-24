#include "raylib.h"
#include "tiles.h"
#include "constants.hpp"
#include "board.h"
#include "game.h"

void Gravity(){                                                  
  frameCounter++;                                                               
                                                                                
  if (frameCounter >= 20) {             
      if (!isWall(tilePositionX, tilePositionY + tileSize)) {                   
          tilePositionY += tileSize;                                           
      }                                                                         
      frameCounter = 0;                                                         
  }
}

