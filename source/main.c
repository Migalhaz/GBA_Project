#include <stdint.h>
#include "render.h"
#include "input.h"

int main()
{
  render_setup();

  volatile uint16_t* videoBuffer = (volatile uint16_t*)VRAM;

  uint32_t xPos = 50;
  uint32_t yPos = 50;  

  while (1)
  {
    uint16_t inputSnapshot = REG_KEYINPUT;

    draw_rect(videoBuffer, xPos, yPos, 10, 10, 0);

    if (DPAD_RIGHT_PRESSED(inputSnapshot)) // DPAD RIGHT ADDRESS
    {
      ++xPos;
    }
    if (DPAD_LEFT_PRESSED(inputSnapshot)) // DPAD LEFT ADDRESS
    {
      --xPos;
    }
    if (DPAD_UP_PRESSED(inputSnapshot)) // DPAD UP ADDRESS
    {
      --yPos;
    }
    if (DPAD_DOWN_PRESSED(inputSnapshot)) // DPAD DOWN ADDRESS
    {
      ++yPos;
    }

    draw_rect(videoBuffer, xPos, yPos, 10, 10, 0x001F << 3);

    wait_VBLANK();
  }

  return 0;
}
