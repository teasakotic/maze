#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <vector>
#include "drawable.h"
#include "tileset.h"

class Level: public Drawable{

public:
    typedef vector<vector<char> > matricaLevela;
    typedef vector<char> redLevela;

private:
    Tileset * tileset;
    matricaLevela level;
public:

    // Konstruktor klase Level
    Level(istream &is, Tileset * tileset): Drawable(){
        this->tileset = tileset;
        int h, w;
        char slovo;

        is>> h >> w;
        // VIsina reda
        for(int i = 0; i < h; i++){
            level.push_back(redLevela());
            //Duzina reda
            for(int j = 0; j < w; j ++){
                is >> slovo;
                level[i].push_back(slovo);
            }

        }
    }

    ~Level(){
        delete tileset;
    }

    void draw(SDL_Renderer * renderer){
        for(size_t i = 0; i < level.size(); i++){
            for(size_t j = 0; j < level[i].size(); j++ ){
                tileset->drawTile(level[i][j], j*32, i*32, renderer);
            }
        }
    }

    const matricaLevela& getMatricaLevela() const{
        return level;
    }



};


#endif // LEVEL_H_INCLUDED
