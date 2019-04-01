#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "SDL/SDL_getenv.h"
#include <iostream>
#include "foncts.h"


bool collision(SDL_Rect* rect1,SDL_Rect* rect2)
{
        if(rect1->y >= rect2->y + rect2->h)
                return 0;
        if(rect1->x >= rect2->x + rect2->w)
                return 0;
        if(rect1->y + rect1->h <= rect2->y)
                return 0;
        if(rect1->x + rect1->w <= rect2->x)
                return 0;
        return 1;
}


 void blitz(SDL_Surface* screen,SDL_Surface* chaos,SDL_Rect* rec)
 {              
			SDL_BlitSurface(chaos,NULL,screen,&*rec);  
			SDL_Flip(screen); 
			SDL_Delay(1000);
			SDL_FreeSurface(chaos);			   			                 
}

SDL_Surface* volume(SDL_Surface* screen,SDL_Surface* chaos,SDL_Rect* rec,int *e)
{
 switch(*e)
  {
   case 0: chaos= IMG_Load("./assets/images/volumeindicator/0.png");
   break;
   case 1: chaos= IMG_Load("./assets/images/volumeindicator/10.png");
   break;
   case 2: chaos= IMG_Load("./assets/images/volumeindicator/20.png");
   break;
   case 3: chaos= IMG_Load("./assets/images/volumeindicator/30.png");
   break;
   case 4: chaos= IMG_Load("./assets/images/volumeindicator/40.png");
   break;
   case 5: chaos= IMG_Load("./assets/images/volumeindicator/50.png");
   break;
   case 6: chaos= IMG_Load("./assets/images/volumeindicator/60.png");
   break;
   case 7: chaos= IMG_Load("./assets/images/volumeindicator/70.png");
   break;
   case 8: chaos= IMG_Load("./assets/images/volumeindicator/80.png");
   break;
   case 9: chaos= IMG_Load("./assets/images/volumeindicator/90.png");
   break;
   case 10: chaos= IMG_Load("./assets/images/volumeindicator/100.png");
   break;
  }
  
  
   return chaos;
}
