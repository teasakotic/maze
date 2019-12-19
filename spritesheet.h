#ifndef SPRITESHEET_H_INCLUDED
#define SPRITESHEET_H_INCLUDED
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <map>
#include "tile.h"

typedef Tile Frame;
typedef vector<Frame*> Frames;

class SpriteSheet{
private:
    SDL_Texture * texture;
    map<string, Frames> animations;

public:
    SpriteSheet(istream &is, SDL_Renderer * renderer){
        string path;
        string animation;
        int totalFrames;
        is >> path;

        SDL_Surface * surface = IMG_Load(path.c_str());
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        while(!is.eof()){
            is >> animation;
            animations[animation] = Frames();

            is >> totalFrames;
            for(int i = 0; i < totalFrames; i++){
                animations[animation].push_back(new Frame(is));
            }
        }
    }
    void drawFrame(string animation, int frame, SDL_Rect * dest, SDL_Renderer * renderer){
        SDL_RenderCopy(renderer, texture, animations[animation][frame]->getRect(), dest);
    }
};


#endif // SPRITESHEET_H_INCLUDED
