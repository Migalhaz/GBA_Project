#ifndef RECT_H
#define RECT_H

#include <stdint.h>

typedef struct
{
  unsigned char x;
  unsigned char y;
  unsigned char width;
  unsigned char height;
} Transform;

typedef struct
{
  Transform transform;
  uint16_t color;
} Rect;

typedef struct
{
  signed char velocityX;
  signed char velocityY;
} RigidBody;

#endif
