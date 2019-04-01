#include <iostream>
#include <fstream>
#include <vector>
#include <SDL/SDL.h>
#ifndef GAME_H
#define GAME_H
class game{
	SDL_Surface* screen,*background,*block;
    SDL_Rect Camera;
    std::vector<std::vector<int> > map;
    bool direction[2];
    SDL_Surface* load_image(const char* filename);
    void loadmap(const char* filename);
    void showmap();
    void handleEvents();
    static const int SCREEN_WIDTH=640;
    static const int SCREEN_HEIGHT=480;
    public:
    game();
    ~game();
    void start();
};
#endif
