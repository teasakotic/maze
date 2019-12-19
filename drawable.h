#ifndef DRAWABLE_H_INCLUDED
#define DRAWABLE_H_INCLUDED
#include "SDL2/SDL.h"

class Drawable{
public:
    virtual void draw(SDL_Renderer * renderer)=0;
};



#endif // DRAWABLE_H_INCLUDED
