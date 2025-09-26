#ifndef FALLOUT_GAME_PIPBOY_H_
#define FALLOUT_GAME_PIPBOY_H_

#include "art.h"
#include "message.h"
#include "db.h"
#include "rect.h"

//namespace fallout {

typedef enum PipboyOpenIntent {
    PIPBOY_OPEN_INTENT_UNSPECIFIED = 0,
    PIPBOY_OPEN_INTENT_REST = 1,
} PipboyOpenIntent;

typedef void(PipboyRenderProc)(int a1);

int pipboy(int intent);
void pip_init();
int save_pipboy(DB_FILE* stream);
int load_pipboy(DB_FILE* stream);

//}

#endif /* FALLOUT_GAME_PIPBOY_H_ */
