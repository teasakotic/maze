#ifndef TILESET_H_INCLUDED
#define TILESET_H_INCLUDED
#include <map>

#include "SDL2/SDL_image.h"
#include "tile.h"

class Tileset{
private:
    map<char, Tile*> tileset;
    SDL_Texture *texture;
    SDL_Rect *dest;

public:
    // Konstruktor klase Tileset
    Tileset(istream &is, SDL_Renderer * renderer){
        string path;
        is >> path;

        SDL_Surface *surface = IMG_Load(path.c_str());

        texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_FreeSurface(surface);

        while(!is.eof()){
            char slovo;
            is >> slovo;
            tileset[slovo] = new Tile (is);
        }
        dest = new SDL_Rect;

    }

    void drawTile(char slovo, int x, int y, SDL_Renderer * renderer){
        dest->x = x;
        dest->y = y;
        dest->w = tileset[slovo]->getW();
        dest->h = tileset[slovo]->getH();

        SDL_RenderCopy(renderer, texture, tileset[slovo]->getRect(), dest);

    }


};


#endif // TILESET_H_INCLUDED
