#ifndef KEY_H_INCLUDED
#define KEY_H_INCLUDED
#include "sprite.h"


class Key : public Sprite{
public:
    Key(SpriteSheet *sheet,int width=32, int height=32):Sprite(sheet,width,height){
        state = STOP;
        spriteRect->x = 416;
        spriteRect->y = 96;
    }

    void draw(SDL_Renderer *renderer){
    if(state == STOP){
        sheet->drawFrame("key",0,spriteRect,renderer);
    }
    frameCounter++;
        if(frameCounter%frameSkip == 0){
            currentFrame++;
            if(currentFrame >= 1){
                currentFrame = 0;
            }
            frameCounter = 0;
        }}

    virtual bool isKey(){
        return true;
    }
    virtual bool isChest(){
        return false;
    }
    virtual bool isEnemy(){
        return false;
    }



};



#endif // KEY_H_INCLUDED
