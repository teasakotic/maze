#ifndef KOLIZIJA_H_INCLUDED
#define KOLIZIJA_H_INCLUDED

class Sprite;
class Kolizija{
public:
    virtual bool provera(Sprite *sprite )= 0;
    virtual bool proveraZemlje(Tile *tile)=0;
    virtual bool isKey()=0;
    virtual bool isChest()=0;
    virtual bool isEnemy()=0;


};

#endif // KOLIZIJA_H_INCLUDED
