#ifndef CHEST_H_INCLUDED
#define CHEST_H_INCLUDED
#include "sprite.h"

class Chest : public Sprite{
public:
    Chest(SpriteSheet *sheet,int widht=32,int height=32):Sprite(sheet,widht,height){


        spriteRect->x = 160;
        spriteRect->y = 418;

    }


    void draw(SDL_Renderer *renderer){
    if(state == STOP){
        sheet->drawFrame("chest",0,spriteRect,renderer);
    }
    frameCounter++;
        if(frameCounter%frameSkip == 0){
            currentFrame++;
            if(currentFrame >= 1){
                currentFrame = 0;
            }
            frameCounter = 0;
        }}

    virtual bool isChest(){
        return true;
    }
    virtual bool isKey(){
        return false;
    }
    virtual bool isEnemy(){
        return false;
    }
};



#endif // CHEST_H_INCLUDED
