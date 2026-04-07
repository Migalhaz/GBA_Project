#ifndef GAMESTATES_H
#define GAMESTATES_H

typedef enum{
    STATE_START,
    STATE_MENU,
    STATE_PLAYING,
    STATE_GAME_OVER
} GameState;

extern GameState currentState;

void set_state(GameState newState);

#endif
