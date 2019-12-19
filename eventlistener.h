#ifndef EVENTLISTENER_H_INCLUDED
#define EVENTLISTENER_H_INCLUDED

#include "SDL2/SDL.h"

class EventListener{
public:
    virtual void listen(SDL_Event & event)= 0;
};


#endif // EVENTLISTENER_H_INCLUDED
