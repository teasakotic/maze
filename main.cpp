#include <iostream>
#include "engine.h"
#include "eventlistener.h"
#include "keventlistener.h"
#include "drawable.h"
#include "tile.h"
#include "tileset.h"
#include "level.h"
#include "spritesheet.h"
#include "sprite.h"
#include "movable.h"
#include "player.h"
#include "dirt.h"
#include "key.h"
#include "kolizija.h"
#include "chest.h"
#include "enemy.h"
using namespace std;



int main(int argc, char** argv)
{
    Engine * eng = new Engine();

    eng->addTileset("resources/tileset/ts.txt", "ts1");

    ifstream levelStream("resources/level/lvl1.txt");
    eng->addDrawable(new Level(levelStream, eng->getTileset("ts1")));

    eng->run();
    delete eng;
    return 0;


}
