#ifndef SPRITE_H_INCLUDED
#define SPRITE_H_INCLUDED

#include "drawable.h"
#include "spritesheet.h"
#include "movable.h"
#include "kolizija.h"

class Sprite : public Drawable,public Movable{
public:
    enum State:short int {STOP=0, LEFT=1, RIGHT=2, UP=4, DOWN=8,
                     LEFT_UP=LEFT|UP, LEFT_DOWN=LEFT|DOWN,
                     RIGHT_UP=RIGHT|UP, RIGHT_DOWN=RIGHT|DOWN};
    short int state;
    SpriteSheet *sheet;
    SDL_Rect *spriteRect;
    int currentFrame;
    int frameCounter;
    int frameSkip;
    bool deadly;

    Sprite(SpriteSheet *sheet, int width = 32, int height = 32): Drawable(),Movable(){
        state = STOP;
        this->sheet = sheet;
        currentFrame =0;
        frameCounter = 0;
        frameSkip = 1;

        spriteRect = new SDL_Rect();
        spriteRect->x = 0;
        spriteRect->y = 0;
        spriteRect->w = width;
        spriteRect->h = height;
    }


    int getFrameSkip(){
        return frameSkip;
    }
    void setFrameSkip(int frameSkip){
        if(frameSkip < 0 ){
            frameSkip = 0;
        }
        this->frameSkip = frameSkip+1;
    }
    short int getState(){
        return state;
    }
    void setState(short int state ){
        this->state = state;
    }
    void draw(SDL_Renderer *renderer){
        if(state&LEFT){
            sheet->drawFrame("walk_left", currentFrame, spriteRect,renderer);
        } else if(state&RIGHT){
            sheet->drawFrame("walk_right",currentFrame,spriteRect,renderer);
        } else if(state&UP){
            sheet->drawFrame("walk_up",currentFrame,spriteRect,renderer);
        } else if(state&DOWN){
            sheet->drawFrame("walk_down",currentFrame,spriteRect,renderer);
        }else if(state == STOP){
            sheet->drawFrame("walk_down",0,spriteRect,renderer);
        }
        frameCounter++;
        if(frameCounter%frameSkip == 0){
            currentFrame++;
            if(currentFrame >= 4){
                currentFrame = 0;
            }
            frameCounter = 0;
        }}

        void move(int dx,int dy){
            spriteRect->x += dx;
            spriteRect->y += dy;
        }

        void move(){
            if(state != 0){
                if((state & 1) && (spriteRect->x > 0)){
                    move(-2,0);
                }
                if((state & 2) && (spriteRect->x < 608)) {
                    move(2,0);
                }
                if((state & 4) && (spriteRect->y > 0)) {
                    move(0,-2);
                }
                if((state & 8) && (spriteRect->y < 448)) {
                    move(0,2);
                }}}

       virtual bool isKey(){
        return false;
    }
    virtual bool isChest(){
        return false;
    }
    virtual bool isEnemy(){
        return false;
    }


    bool provera(Sprite * sprite){


        SDL_Rect * rect1 = this->spriteRect;
        SDL_Rect * rect2 = sprite->spriteRect;

        if((rect1->x + rect1->w) >=(rect2->x)&&

            (rect1->x) <= (rect2->x + rect2->w) &&

            (rect1->y + rect2->h) >= (rect2->y) &&

            (rect1->y) <= (rect2->y + rect2->h)
           ){
                cout<<"Doslo je do kolizije"<<endl;
                return true;
            }
            return false;
    }



     bool proveraZemlje(Tile *tile){


        SDL_Rect * rect1 = this->spriteRect;
        SDL_Rect * rect2 = tile->trect;

        if((rect1->x + rect1->w) >=(rect2->x)&&

            (rect1->x) <= (rect2->x + rect2->w) &&

            (rect1->y + rect2->h) >= (rect2->y) &&

            (rect1->y) <= (rect2->y + rect2->h)
           ){
                return true;
            }
            return false;
    }




};

#endif // SPRITE_H_INCLUDED
