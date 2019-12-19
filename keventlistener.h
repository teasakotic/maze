#ifndef KEVENTLISTENER_H_INCLUDED
#define KEVENTLISTENER_H_INCLUDED
#include "eventlistener.h"

class KEventListener: public EventListener{
public:
    // Metoda iz EventListenera
    virtual void listen(SDL_Event &event){
        if(event.type == SDL_KEYDOWN || event.type == SDL_KEYUP){
            listen(event.key);
        }
    }

    virtual void listen(SDL_KeyboardEvent &event)=0;

};


#endif // KEVENTLISTENER_H_INCLUDED
