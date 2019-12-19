#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include "sprite.h"

class Enemy : public Sprite{
public:
    bool moveCheck = true;
public:

    Enemy(SpriteSheet *sheet, int width=32,int height=32):Sprite(sheet,width,height){
        spriteRect->x =64;
        spriteRect->y = 96;
    }

    void draw(SDL_Renderer *renderer){
        if(state&LEFT){
            sheet->drawFrame("left", currentFrame, spriteRect,renderer);
        } else if(state&RIGHT){
            sheet->drawFrame("right",currentFrame,spriteRect,renderer);
        } else if(state&UP){
            sheet->drawFrame("up",currentFrame,spriteRect,renderer);
        } else if(state&DOWN){
            sheet->drawFrame("down",currentFrame,spriteRect,renderer);
        }else if(state == STOP){
            sheet->drawFrame("down",0,spriteRect,renderer);
        }
        frameCounter++;
        if(frameCounter%frameSkip == 0){
            currentFrame++;
            if(currentFrame >= 3){
                currentFrame = 0;
            }
            frameCounter = 0;
        }}

        virtual bool isEnemy(){
            return true;
        }

        virtual bool isKey(){
            return false;
        }
        virtual bool isChest(){
            return false;
        }

        void move(int dx,int dy){
            spriteRect->x += dx;
            spriteRect->y += dy;
        }


        void move(){

        if(this->spriteRect->y >=96 && moveCheck== true){
               if(this->spriteRect->y == 384){
                moveCheck = false;
               }
               else{
                        state=DOWN;
                        move(0,2);
               }
            }
        else if(this->spriteRect->y <= 384 && moveCheck == false){
            if(this->spriteRect->y == 96){
                moveCheck = true;
            }
            else{
                    state=UP;
                    move(0,-2);

            }
        }

        }

};


#endif // ENEMY_H_INCLUDED
