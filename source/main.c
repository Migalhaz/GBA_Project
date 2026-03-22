#include <stdint.h>
#include "render.h"
#include "input.h"


int main()
{
  render_setup();

  volatile uint16_t* videoBuffer = (volatile uint16_t*)VRAM;

  uint32_t xPos = 50;
  uint32_t yPos = 50;  
  uint32_t width = 10;
  uint32_t height = 10;
  uint32_t color = 0x0001F;

  while (1)
  {
    uint16_t inputSnapshot = REG_KEYINPUT;

    draw_rect(videoBuffer, xPos, yPos, width, height, 0);
    draw_rect(videoBuffer, 1, 3, width, 1, 0);
    draw_rect(videoBuffer, 1, 8, height, 1, 0);
    
    if (DPAD_RIGHT_PRESSED(inputSnapshot))
    {
      if ((xPos + width) < SCREEN_W) 
      {
        ++xPos;
      }
    }
    if (DPAD_LEFT_PRESSED(inputSnapshot))
    {
      if (xPos > 0)
      {
        --xPos;
      }
    }
    if (DPAD_UP_PRESSED(inputSnapshot))
    {
      if (yPos > 0)
      {
        --yPos;
      }
    }
    if (DPAD_DOWN_PRESSED(inputSnapshot))
    {
      if ((yPos + height) < SCREEN_H)
      {
        ++yPos;
      }
    }

    if (KEY_A_PRESSED(inputSnapshot))
    {
      #define MAX_HEIGHT 30
      if (height < MAX_HEIGHT) 
      {
        ++height;
      }
      #undef MAX_HEIGHT
    }

    if (KEY_B_PRESSED(inputSnapshot))
    {
      #define MIN_HEIGHT 5
      if (height > MIN_HEIGHT)
      {
        --height;
      }
      #undef MIN_HEIGHT
    }

    if (KEY_R_PRESSED(inputSnapshot))
    {
      #define MAX_WIDTH 30
      if (width < MAX_WIDTH)
      {
        ++width;
      }

      #undef MAX_WIDTH
    }

    if (KEY_L_PRESSED(inputSnapshot))
    {
      #define MIN_WIDTH 5
      if (width > MIN_WIDTH)
      {
        --width;
      }
      #undef MIN_WIDTH
    }

    if (KEY_SELECT_PRESSED(inputSnapshot))
    {
      #define RED 0x001F
      color = RED;
    }

    if (KEY_START_PRESSED(inputSnapshot))
    {
      #define GREEN 0x02E0
      color = GREEN;
    }


    draw_rect(videoBuffer, xPos, yPos, width, height, color);
    draw_rect(videoBuffer, 1, 3, width, 1, RED);
    draw_rect(videoBuffer, 1, 8, height, 1, GREEN);

    wait_VBLANK();
  }

  return 0;
}
