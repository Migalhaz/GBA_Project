#ifndef RENDER_H
#define RENDER_H

#include <stdint.h>

#define VRAM 0x06000000
#define REG_DISPCNT *((volatile uint16_t*)0x04000000)
#define REG_VCOUNT *((volatile uint16_t*)0x04000006)

#define MODE_3 0x0003
#define BG2_ENABLE 0x0400

#define SCREEN_W 240
#define SCREEN_H 160
#define SCREEN_SIZE (SCREEN_W * SCREEN_H)

void render_setup();
void draw_rect(volatile uint16_t* videoBuffer, uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint32_t color);
void wait_VBLANK();
#endif
