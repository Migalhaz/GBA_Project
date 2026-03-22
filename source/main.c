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

  while (1)
  {
    uint16_t inputSnapshot = REG_KEYINPUT;

    draw_rect(videoBuffer, xPos, yPos, width, height, 0);

    if (DPAD_RIGHT_PRESSED(inputSnapshot)) // DPAD RIGHT ADDRESS
    {
      if ((xPos + width) < SCREEN_W) 
      {
        ++xPos;
      }
    }
    if (DPAD_LEFT_PRESSED(inputSnapshot)) // DPAD LEFT ADDRESS
    {
      if (xPos > 0)
      {
        --xPos;
      }
    }
    if (DPAD_UP_PRESSED(inputSnapshot)) // DPAD UP ADDRESS
    {
      if (yPos > 0)
      {
        --yPos;
      }
    }
    if (DPAD_DOWN_PRESSED(inputSnapshot)) // DPAD DOWN ADDRESS
    {
      if ((yPos + height) < SCREEN_H)
      {
        ++yPos;
      }
    }

    draw_rect(videoBuffer, xPos, yPos, width, height, 0x001F);

    wait_VBLANK();
  }

  return 0;
}
