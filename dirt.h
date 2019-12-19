#ifndef DIRT_H_INCLUDED
#define DIRT_H_INCLUDED

#include "tile.h"


class Dirt : public Tile{
public:
    Dirt(int x, int y, int w, int h):Tile(x,y,w,h){

    }
    virtual bool isDeadly(){
        return true;
    }

};



#endif // DIRT_H_INCLUDED
