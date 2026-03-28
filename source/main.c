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
    #define GRAVITY 2

    unsigned char jumped = 0;

    while (1)
    {
      uint16_t inputSnapshot = REG_KEYINPUT;
    
      draw_rect(videoBuffer, obj.transform.x, obj.transform.y, obj.transform.width, obj.transform.height, 0);
      
      if (DPAD_RIGHT_PRESSED(inputSnapshot))
      {
        objRig.velocityX = OBJ_VELOCITY;
      }

      if (DPAD_LEFT_PRESSED(inputSnapshot))
      {
        objRig.velocityX = -OBJ_VELOCITY;
        jumped = 1;
      }

      if (jumped == 0)
      {
        if (DPAD_UP_PRESSED(inputSnapshot))
        {
          objRig.velocityY = -40;
          jumped = 1;
        }

      }
      else if (jumped == 1)
      {
        if (!DPAD_UP_PRESSED(inputSnapshot) && obj.transform.y >= SCREEN_H - obj.transform.height)
        {
          jumped = 0;
        }
      }

   

    objRig.velocityY += GRAVITY;

    obj.transform.x += objRig.velocityX;
    
    if (obj.transform.x > SCREEN_W || obj.transform.x + obj.transform.width > SCREEN_W)
    {
      if (objRig.velocityX > 0)
      {
        obj.transform.x = SCREEN_W - obj.transform.width;
      }
      if (objRig.velocityX < 0)
      {
        obj.transform.x = 0;
      }
    }
    
   
    obj.transform.y += objRig.velocityY;

    if (obj.transform.y + obj.transform.height > SCREEN_H)
    {
      obj.transform.y = SCREEN_H - obj.transform.height;
    }
    objRig.velocityX = 0;
    objRig.velocityY = 0;

    draw_rect(videoBuffer, obj.transform.x, obj.transform.y, obj.transform.width, obj.transform.height, obj.color);

    wait_VBLANK();
  }

  return 0;
}
