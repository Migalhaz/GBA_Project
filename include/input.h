#ifndef INPUT_H 
#define INPUT_H

#define REG_KEYINPUT *((volatile uint16_t*)0x04000130)

#define KEY_A 0x0001
#define KEY_A_PRESSED(x) !((x) & KEY_A)

#define KEY_B 0x0002
#define KEY_B_PRESSED(x) !((x) & KEY_B)

#define KEY_SELECT 0x0004
#define KEY_SELECT_PRESSED(x) !((x) & KEY_SELECT)

#define KEY_START 0x0008
#define KEY_START_PRESSED(x) !((x) & KEY_START)

#define DPAD_RIGHT 0x0010
#define DPAD_RIGHT_PRESSED(x) !((x) & DPAD_RIGHT)

#define DPAD_LEFT 0x0020
#define DPAD_LEFT_PRESSED(x) !((x) & DPAD_LEFT)

#define DPAD_UP 0x0040
#define DPAD_UP_PRESSED(x) !((x) & DPAD_UP)

#define DPAD_DOWN 0x0080
#define DPAD_DOWN_PRESSED(x) !((x) & DPAD_DOWN)

#define KEY_R 0x0100
#define KEY_R_PRESSED(x) !((x) & KEY_R)

#define KEY_L 0x0200
#define KEY_L_PRESSED(x) !((x) & KEY_L)

#endif
