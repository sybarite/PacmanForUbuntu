//Author Sybarite
/*
This is the implementation file for the map.h header file
*/
#include "map.h"
#include <iostream>

//The constructor to initialize the base_graphics object in the map class
Map::Map(GAME_GRAPHICS* gr)
{
    base_graphics = gr;
}

//the function to open a map given a path and associating with the class file OBJECT
void Map::open_map(std::string path)
{
	filein.open(path.c_str());
}

// Function to set the map
void Map::set_map()
{

}

