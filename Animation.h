#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED
#include "sprite.h"
#include <Vector>
#include <stdio.h>
class Animation
{
public:

    //The public members


    //The left and right spritesheets that will be used in the animation
    SDL_Surface* rightsheet;
    SDL_Surface* leftsheet;

     //current frame
    int frame;
    //animation status
    //The code: LEFT-1;RIGHT-2;UP-3;DOWN-4;
    int status;


    //Contains the clips of the Animations sequence for left,right,top,bottom and
    //up movements
    //I am making this a vector since i don't want to limit the animation frames
    std::vector<SDL_Rect> rightAnimationClips;
    std::vector<SDL_Rect> leftAnimationClips;

    //The reference of the sprite which is to be animated
    Sprite* sprite;

    //The public functions

    //The constructor
    Animation(Sprite* sp);

    //An all in one function to insert the animation clips
    //We take a string and the clip to add it in the appropriate vector
    //The code: LEFT-1;RIGHT-2;UP-3;DOWN-4;

    void insertClip(int direction,SDL_Rect r);

    /*This function will check the velocity of the sprite in the map
    and assign the appropriate clip for clip to blit on the sprite object.
    There will be a frame counter which will keep updating everyframe which clip to
    blit.
    */
    void animate();

    //Debug function
    void debug();
};
#endif // ANIMATION_H_INCLUDED
