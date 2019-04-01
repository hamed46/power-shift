#intdef INTRODUCTIONSTAGE_H_INCLUDED
#define INTRODUCTIONSTAGE_H_INCLUDED

#include "GameEngine.h"
#include "Constantes.h"

typedef struct introVar introVar;

struct introVar
{
Stage *introStage;

SDL_Event event;
};

//
int startIntroduction();
//
void createIntroduction(introVar* introvar);
//
void disposeIntroduction(introVar* introvar);
//
void renderIntroduction(introVar introvar);
//
void updateIntroduction(float delta_s,introVar* introvar);
//
void eventIntroduction(introVar* introvar);

#endif // INTRODUCTIONSTAGE_H_INCLUDED
