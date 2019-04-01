#include <SDL/SDL.h>
#include <iostream>
#include <SDL/SDL_mixer.h>
 
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
 
int width = 640;
int height = 480;
 
int main(int argc, char** argv)
{
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_Surface *screen, *background, *image;
        screen = SDL_SetVideoMode(width, height, 32, SDL_SWSURFACE);
//      screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE|SDL_FULLSCREEN);
        bool running=true;
        const int FPS = 30;
        Uint32 start;
        const int speed = 5;
        int x,y;
        x = 0;
        y = 0;
        int i;
        i = 0;
        background = SDL_LoadBMP("background.bmp");
        image = SDL_LoadBMP("siblings.bmp");
        SDL_Rect imgloc = {200,0,50,100};
        SDL_Rect camera;
        camera.x = 0;
        camera.y = 0;
        camera.w = 640;
        camera.h = 480;
        bool b[2] = {0,0};
        
        if(i == 0)
        {
		 b[0] = 1;	
		}
		
		Mix_Music *music;
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 2048);
	music=Mix_LoadMUS("5-18 Sunset Hill Zone - Act 1.mp3");
	Mix_PlayMusic(music, -1);
	
        while(running) {
                start = SDL_GetTicks();
                SDL_Event event;
                while(SDL_PollEvent(&event)) {
                 switch(event.type) {
                  case SDL_QUIT:
                         running = false;
                   break;
                       case SDL_KEYDOWN:
                              switch(event.key.keysym.sym)
                           {
                                 case SDLK_RIGHT:
                                           b[0] = 1;
                                          break;
                                 case SDLK_LEFT:
                                     b[1] = 1;
                                   break;
                                 case SDLK_ESCAPE:
                                    running = false;
                                               break;
                                               case SDLK_g:
                              Mix_Chunk* Beeps;
	Beeps=Mix_LoadWAV("Beeps1.wav");
                                        Mix_PlayChannel(-1, Beeps, 0);
                                        break;
                    }
                                        break;
                  case SDL_KEYUP:
                    switch(event.key.keysym.sym)
                      {
                             case SDLK_RIGHT:
                                          b[0] = 0;
                                      break;
                               case SDLK_LEFT:
                                    b[1] = 0;
                                         break;
                                        }
                                        break;
                        }
                }
 
                //logic
                if(b[0])
                {
                        x += speed;
                        imgloc.x += speed +speed;
                        camera.x += speed;
                        if(camera.x >= 2000-640)
                                camera.x = 0;
                }
                else if(b[1])
                {
                        x -= speed;
                        camera.x -= speed;
                        if(camera.x <= 0)
                                camera.x = 2000-640;
                }
 
                SDL_Rect location = {x,y,640,480};
                SDL_Rect relcoord = {imgloc.x-x, imgloc.y-y};
                               std::cout << x << std::endl;
                //render
                SDL_BlitSurface(background,&camera,screen,NULL);
                if(collision(&location, &imgloc))
                SDL_BlitSurface(image,NULL,screen,&relcoord);
                           SDL_Flip(screen);

 
                              SDL_Flip(screen);
                if(1000/FPS > SDL_GetTicks()-start) {
                        SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
                }
        }
  /*      SDL_FreeSurface(background);*/
        SDL_Quit();
        return 0;
}
