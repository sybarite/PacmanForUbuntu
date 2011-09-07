//Author Sybarite
//game_graphics.h
/*
This header file contains definations for a graphics base class which wil be used in the game.
Containing all the base functions which can be inherited by other classes in the project. Also
This file will contain the SDL_Surface object of screen which is the base screen to blit all the
images into. A child class most probably called the maze_screen.cpp will inherit this class, to form
the game screen with help of other support graphics classes which in turn also will inherit this class
as the parent class.

*/

#ifndef GAME_GRAPHICS_H_INCLUDED
#define GAME_GRAPHICS_H_INCLUDED
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>
class GAME_GRAPHICS
{
private:
    int SCREEN_HEIGHT;
    int SCREEN_WIDTH;
    int SCREEN_BPP;
protected:

public:
    //The screen object
    SDL_Surface* screen;
    //The frames per second
    static const int FRAMES_PER_SECOND = 30;

    //The functions
    //Constructor
    GAME_GRAPHICS(int WIDTH,int HEIGHT,int BPP);
    //Sets the default screen
    bool set_screen();

    //Generic function to load images
    SDL_Surface* load_image(std::string filename);
    //Function to apply images to a surface
    void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL);
    //A function to put a pixel in a particular sdl surface
    void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);

    //A function to get a pixel in a particular SDL surface
    Uint32 getpixel(SDL_Surface *surface, int x, int y);

    //Destructor
    ~GAME_GRAPHICS();
};
#endif // GAME_GRAPHICS_H_INCLUDED
