#include <stdint.h>
#include "render.h"
#include "input.h"
#include "fpm.h"

int main()
{
  render_setup();

  volatile uint16_t* videoBuffer = (volatile uint16_t*)VRAM;

  uint32_t xPos = 50;
  uint32_t yPos = 50;
  
  while (1)
  {
    draw_rect(videoBuffer, xPos, yPos, 10, 20, 0);

    if (DPAD_RIGHT_PRESSED) // DPAD RIGHT ADDRESS
    {
      ++xPos;
    }
    if (DPAD_LEFT_PRESSED) // DPAD LEFT ADDRESS
    {
      --xPos;
    }
    if (DPAD_UP_PRESSED) // DPAD UP ADDRESS
    {
      --yPos;
    }
    if (DPAD_DOWN_PRESSED) // DPAD DOWN ADDRESS
    {
      ++yPos;
    }

    draw_rect(videoBuffer, xPos, yPos, 10, 20, 0x001F << 3);

    wait_VBLANK();
  }

  return 0;
}
