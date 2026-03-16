#include "render.h"
void render_setup()
{
  REG_DISPCNT = (MODE_3 | BG2_ENABLE);
}

void draw_rect(volatile uint16_t* videoBuffer, uint32_t startX, uint32_t startY, uint32_t width, uint32_t height, uint32_t color)
{
  uint32_t finalY = startY + height;
  uint32_t finalX = startX + width;

  for (uint32_t y = startY; y < finalY; ++y)
  {
    volatile uint16_t* rectPointer = videoBuffer + (y * SCREEN_W + startX);
    for (uint32_t x = startX; x < finalX; ++x)
    {
      *rectPointer = (uint16_t) color;
      ++rectPointer;
    }
  }
}

void wait_VBLANK()
{
  while (REG_VCOUNT >= 160) { }
  while (REG_VCOUNT < 160) { }
}
