#include "Test.h"
#include "sprite.h"
#include "Timer.h"
#include "Animation.h"
void Test::game_loop()
{
    bool quit = false;
    //The frame rate regulator
    Timer fps;

    //The game graphics object
    GAME_GRAPHICS graphics(800,600,32);
    graphics.set_screen();

    SDL_Surface* sheetright=graphics.load_image("monster.png");
    SDL_Surface* sheetleft=graphics.load_image("monster.png");



    //Defining the clips for right,left animation
    SDL_Rect clipright[2];
    clipright[0].x=146;clipright[0].y=320;clipright[0].w=43;clipright[0].h=35;
    clipright[1].x=210;clipright[1].y=320;clipright[1].w=43;clipright[1].h=35;

    SDL_Rect clipleft[2];
    clipleft[0].x=146;clipleft[0].y=320;clipleft[0].w=43;clipleft[0].h=35;
    clipleft[1].x=92;clipleft[1].y=320;clipleft[1].w=43;clipleft[1].h=35;
    //*******
    Sprite pac_man(sheetright,&graphics,clipright[0]);
    Animation pacmanAnimation(&pac_man);
    pacmanAnimation.rightsheet=sheetright;
    pacmanAnimation.leftsheet=sheetleft;

    //inserting the clips
    pacmanAnimation.insertClip(2,clipright[0]);
    pacmanAnimation.insertClip(2,clipright[1]);

    pacmanAnimation.insertClip(1,clipleft[0]);
    pacmanAnimation.insertClip(1,clipleft[1]);

    pacmanAnimation.debug();

    //The event structure
    SDL_Event event;
    //While the user hasn't quit
    while(quit==false)
    {

        //While there's events to handle
        while(SDL_PollEvent(&event))
        {
            //Handle the input for moving pacman
            pac_man.handle_input(&event);
            //If the user has Xed out the window
            if(event.type== SDL_QUIT)
            {
                //Quit the program
                quit = true;
            }
        }


        //GameLogic
        pac_man.move();



        //Graphics rendering
        //Fill the screen white
        SDL_FillRect(graphics.screen,&graphics.screen->clip_rect,SDL_MapRGB(graphics.screen->format,0xFF,0xFF,0xFF));

        //Blitting the pacman sprite
        pacmanAnimation.animate();
        pac_man.blitSprite(pac_man.x,pac_man.y);


        //Update the screen
        if(SDL_Flip(graphics.screen)==-1)
        {
            quit = true;
        }

        //Cap the frame rate
        if(fps.get_ticks()<1000/graphics.FRAMES_PER_SECOND)
        {
            SDL_Delay((1000/graphics.FRAMES_PER_SECOND)-fps.get_ticks());
        }
    }
}

void Test::test_flip()
{

}
