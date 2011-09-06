//Author sybarite

#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include "game_graphics.h"
#include <string>
#include <fstream>
class Map
{
private:
    SDL_Surface* background;
    std::ifstream filein;
    GAME_GRAPHICS* base_graphics;
public:
    Map(GAME_GRAPHICS* gr);
    void open_map(std::string path);
    void set_map();
};

class Tile
{
    private:
    //The attributes of the tile
    SDL_Rect box;

    //The tile type
    int type;

    public:
    //Initializes the variables
    Tile( int x, int y, int tileType );

    //Shows the tile
    void show();

    //Get the tile type
    int get_type();

    //Get the collision box
    SDL_Rect get_box();
};
#endif // MAP_H_INCLUDED
