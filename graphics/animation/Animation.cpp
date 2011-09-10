#include "Animation.h"
//** Author notes this is a bare basic animation class for more sophistication more functionalites
//** will be added at a later date, as for now the library is used for research purposes.


// The constructor
Animation::Animation(Sprite* sp)
{
    sprite=sp;
    frame=0;
    status=2;
}

//An all in one function to insert the animation clips
//We take a string and the clip to add it in the appropriate vector
//The code: LEFT-1;RIGHT-2;UP-3;DOWN-4;
void Animation::insertClip(int direction,SDL_Rect r)
{
    switch(direction)
    {
    case 1:
        leftAnimationClips.push_back(r);
        printf("Adding clip \n");
        break;
    case 2:
        rightAnimationClips.push_back(r);
        printf("Adding clip \n");
        break;
    default:
        break;
    }
}

/*This function will check the velocity of the sprite in the map
    and assign the appropriate clip for clip to blit on the sprite object.
    There will be a frame counter which will keep updating everyframe which clip to
    blit.
*/
void Animation::animate()
{
    //If sprite is moving left
    if(sprite->xVel < 0)
    {
        //Set the animation to left
        status = 1;
        //Move to the next frame in the animation
        frame++;
    }
    //If sprite is moving right
    else if(sprite->xVel > 0)
    {
        //Set the animation to right
        status = 2;
        //Move to the next frame in the animation
        frame++;
    }
    //If sprite standing
    else
    {
        //Restart the animation
        frame = 0;
    }

    //Loop the animation
    if(status==1)
    {
        if(frame>=leftAnimationClips.size())
        {
            frame = 0;
        }
    }
    else
    {
        if(frame>=rightAnimationClips.size())
        {
            frame = 0;
        }
    }

    //Set the clip of the sprite
    if( status == 2 )
    {
        //sprite->spriteSheet=rightsheet;
        sprite->clip=rightAnimationClips[frame];
    }
    else if( status == 1 )
    {
        //sprite->spriteSheet=leftsheet;
        sprite->clip=leftAnimationClips[frame];
    }
}

//debug function
void Animation::debug()
{
    for(int i=0; i<rightAnimationClips.size(); i++)
    {
        int g,h,j,k;
        g=rightAnimationClips[i].x;
        h=rightAnimationClips[i].y;
        j=rightAnimationClips[i].h;
        k=rightAnimationClips[i].w;
        printf("\n%d\t%d\t%d\t%d\n",g,h,j,k);
    }
    for(int i=0; i<leftAnimationClips.size(); i++)
    {
        int g,h,j,k;
        g=leftAnimationClips[i].x;
        h=leftAnimationClips[i].y;
        j=leftAnimationClips[i].h;
        k=leftAnimationClips[i].w;
        printf("\n\n%d\t%d\t%d\t%d\n",g,h,j,k);
    }
}

