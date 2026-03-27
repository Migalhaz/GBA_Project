#include <stdint.h>
#include "render.h"
#include "input.h"
#include "rect.h"

int main()
{
  render_setup();

  volatile uint16_t* videoBuffer = (volatile uint16_t*)VRAM;

  Rect obj;
  obj.transform.x = 10;
  obj.transform.y = 10;
  obj.transform.width = 10;
  obj.transform.height = 10;
  obj.color = 0x001F;
  RigidBody objRig;
  objRig.velocityX = 0;
  objRig.velocityY = 0;
  #define OBJ_VELOCITY 1

  while (1)
  {
    uint16_t inputSnapshot = REG_KEYINPUT;

    draw_rect(videoBuffer, obj.transform.x, obj.transform.y, obj.transform.width, obj.transform.height, 0);
    
    if (DPAD_RIGHT_PRESSED(inputSnapshot))
    {
      if (obj.transform.x+obj.transform.width < SCREEN_W) 
      {
        objRig.velocityX = OBJ_VELOCITY;
      }
    }
    if (DPAD_LEFT_PRESSED(inputSnapshot))
    {
      if (obj.transform.x > 0)
      {
        objRig.velocityX = -OBJ_VELOCITY;
      }
    }
    if (DPAD_UP_PRESSED(inputSnapshot))
    {
      if (obj.transform.y > 0)
      {
        objRig.velocityY = -OBJ_VELOCITY;
      }
    }
    if (DPAD_DOWN_PRESSED(inputSnapshot))
    {
      if (obj.transform.y+obj.transform.height < SCREEN_H)
      {
        objRig.velocityY = OBJ_VELOCITY;
      }
    }

    obj.transform.x += objRig.velocityX;
    obj.transform.y += objRig.velocityY;

    objRig.velocityX = 0;
    objRig.velocityY = 0;
    draw_rect(videoBuffer, obj.transform.x, obj.transform.y, obj.transform.width, obj.transform.height, obj.color);

    wait_VBLANK();
  }

  return 0;
}
