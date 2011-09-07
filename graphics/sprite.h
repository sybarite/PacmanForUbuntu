#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include "game_graphics.h"
#include <string>
#include <stdio.h>
class Sprite
{
public:
    //The co-ordinates of the sprite in a map
    int x;
    int y;

    //The velocity of the sprite
    int xVel, yVel;
    //The SDL surface which will hold the image
    SDL_Surface* spriteSheet;
    //The SDL Rect object which will hold the sprite clip
    SDL_Rect clip;

    //SDL event
    SDL_Event* event;
    //The graphics Object refernce
    GAME_GRAPHICS* graphics;

    //Constructor
    Sprite(SDL_Surface* sheet,GAME_GRAPHICS* gr,SDL_Rect r)
    {
        spriteSheet=sheet;
        graphics=gr;
        clip=r;
        x=0;y=0;
        xVel=0;yVel=0;
    }
    //Showing the sprite on the screen
    void blitSprite(int x1, int y1)
    {
        graphics->apply_surface(x1,y1,spriteSheet,graphics->screen,&clip);
    }

    //debug function
    void debug()
    {
        int g;
        g=clip.x;
        printf("%d",g);
    }
    void handle_input(SDL_Event* evnt)
    {
        event=evnt;
        //If a key was pressed
        if( event->type == SDL_KEYDOWN )
        {
            //Adjust the velocity
            switch( event->key.keysym.sym )
            {
            case SDLK_UP:
                yVel-=clip.h/4;
                break;
            case SDLK_DOWN:
                yVel+=clip.h/4;
                break;
            case SDLK_LEFT:
                xVel-=clip.w/4;
                break;
            case SDLK_RIGHT:
                xVel+=clip.w/4;
                break;
            default:
                break;
            }
        }
        //If a key was released
        else if(event->type == SDL_KEYUP)
        {
            //Adjust the velocity
            switch(event->key.keysym.sym)
            {
            case SDLK_UP:
                yVel+=clip.h/4;
                break;
            case SDLK_DOWN:
                yVel-=clip.h/4;
                break;
            case SDLK_LEFT:
                xVel+=clip.w/4;
                break;
            case SDLK_RIGHT:
                xVel-=clip.w/4;
                break;
            default:
                break;
            }
        }

    }

    void move()
    {
        //Move the dot left or right
        x += xVel;
        //If the dot went too far to the left or right
        if((x<0)||(x+clip.w>graphics->screen->w))
        {
            //move back
            x-=xVel;
        }
        //Move the dot up or down
        y += yVel;
        //If the dot went too far up or down
        if((y<0)||(y+clip.h>graphics->screen->h))
        {
            //move back
            y-=yVel;
        }
        //blitSprite(x,y);
        debug();
    }
};
#endif // SPRITE_H_INCLUDED
