#include "game_graphics.h"

class maze_game
{
private:
public:
    void start_game()
    {
        GAME_GRAPHICS graphics(800,600,32);
        graphics.set_screen();
    }
};
