#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED
#include <iostream>
#include "SDL2/SDL.h"

using namespace std;


class Tile{
public:
    SDL_Rect * trect;


public:
    // Konstruktor klase Tile
    Tile(int x, int y, int w, int h){

        trect = new SDL_Rect;
        trect->x = x;
        trect->y = y;
        trect->w = w;
        trect->h = h;

    }
    // Konstruktor klase Tile inputstream
    Tile(istream &is){
        trect = new SDL_Rect;
        is >> trect->x >> trect->y >> trect->w >> trect->h;
    }

    ~Tile(){
        delete trect;
    }


    // Geteri za rect
    SDL_Rect* getRect(){
        return trect;
    }

    int getX(){
        return trect->x;
    }
    int getY(){
        return trect->y;
    }
    int getW(){
        return trect->w;
    }
    int getH(){
        return trect->h;
    }




};


#endif // TILE_H_INCLUDED
