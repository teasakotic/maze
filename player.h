#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "drawable.h"
#include "movable.h"
#include "sprite.h"
#include "keventlistener.h"
#include "kolizija.h"

class Player : public Drawable,public Movable,public KEventListener{

public:
    Sprite *sprite;
    Player(Sprite *sprite):Drawable(),Movable(),KEventListener(){
        this->sprite = sprite;
    }
    void draw(SDL_Renderer *renderer){
        sprite->draw(renderer);
    }
    void move(){
        sprite->move();
    }
    void move(int dx,int dy){
        sprite->move(dx,dy);
    }



    void listen(SDL_KeyboardEvent &event) {
    if(event.type == SDL_KEYDOWN) {
        if(event.keysym.sym == SDLK_LEFT) {
            sprite->setState(sprite->getState()|Sprite::LEFT);
        } else if(event.keysym.sym == SDLK_RIGHT) {
            sprite->setState(sprite->getState()|Sprite::RIGHT);
        } else if(event.keysym.sym == SDLK_UP) {
            sprite->setState(sprite->getState()|Sprite::UP);
        } else if(event.keysym.sym == SDLK_DOWN) {
            sprite->setState(sprite->getState()|Sprite::DOWN);
        }
    } else if (event.type == SDL_KEYUP) {
        if(event.keysym.sym == SDLK_LEFT) {
            sprite->setState(sprite->getState()&~Sprite::LEFT);
        } else if(event.keysym.sym == SDLK_RIGHT) {
            sprite->setState(sprite->getState()&~Sprite::RIGHT);
        } else if(event.keysym.sym == SDLK_UP) {
            sprite->setState(sprite->getState()&~Sprite::UP);
        } else if(event.keysym.sym == SDLK_DOWN) {
            sprite->setState(sprite->getState()&~Sprite::DOWN);
        }
    }

}



};

#endif // PLAYER_H_INCLUDED
