#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <iostream>
#include <fstream>

#include "drawable.h"
#include "tileset.h"
#include "level.h"
#include "spritesheet.h"
#include "sprite.h"
#include "movable.h"
#include "player.h"
#include "keventlistener.h"
#include "kolizija.h"
#include "key.h"
#include "chest.h"
#include "dirt.h"
#include "enemy.h"

using namespace std;

class Engine{
private:
    SDL_Window * window;
    SDL_Renderer * renderer;
    int frameCap = 60;

    map<string, Tileset*> tilesets;
    vector<Drawable*> drawables;
    vector<Movable*> movables;
    vector<EventListener*> eventListeners;
    vector<Sprite*> kolizije;
    vector<Tile*> blato;

    bool imaKljuc = false;



public:

    //Konstruktor klase Engine
    Engine(string ime= "G A M E  M A Z E"){
        SDL_Init(SDL_INIT_VIDEO);
        SDL_Init(IMG_INIT_PNG);

        window = SDL_CreateWindow(ime.c_str(), SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, 640, 480,
                                  SDL_WINDOW_RESIZABLE);

        renderer = SDL_CreateRenderer(window, -1,
                                      SDL_RENDERER_ACCELERATED);


    }

    // Destruktor klase Engine
    ~Engine(){
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }


    void run(){
        int maxDelay = 1000/frameCap;
        int frameStart = 0;
        int frameEnd = 0;

        bool running = true;
        SDL_Event event;


        ifstream spriteSheetStream("resources/creatures/rbss.txt");
        SpriteSheet *sheet = new SpriteSheet(spriteSheetStream,renderer);

        ifstream spriteSheetStream2("resources/creatures/kac.txt");
        SpriteSheet *sheetKey = new SpriteSheet(spriteSheetStream2,renderer);

        ifstream spriteSheetStream3("resources/creatures/kac.txt");
        SpriteSheet *sheetChest = new SpriteSheet(spriteSheetStream3,renderer);

        ifstream spriteSheetStream4("resources/creatures/skull.txt");
        SpriteSheet *sheetEnemy = new SpriteSheet(spriteSheetStream4,renderer);


        Sprite *sp = new Sprite(sheet);
        sp->setFrameSkip(4);


        Player *player = new Player(sp);

        Dirt *blok1 = new Dirt(0,64,224,30);
        Dirt *blok2 = new Dirt(352,32,224,30);
        Dirt *blok3 = new Dirt(192,192,320,30);
        Dirt *blok4 = new Dirt(96,320,416,30);
        Dirt *blok5 = new Dirt(320,416,320,30);
        Dirt *blok6 = new Dirt(96,256,352,30);
        blato.push_back(blok1);
        blato.push_back(blok2);
        blato.push_back(blok3);
        blato.push_back(blok4);
        blato.push_back(blok5);
        blato.push_back(blok6);

        Enemy *enemy = new Enemy(sheetEnemy);
        Enemy *enemy2 = new Enemy(sheetEnemy);
        Enemy *enemy3 = new Enemy(sheetEnemy);
        enemy2->spriteRect->x = 520;
        enemy2->spriteRect->y = 96;
        enemy3->spriteRect->x = 224;
        enemy3->spriteRect->y = 96;


        drawables.push_back(enemy3);
        movables.push_back(enemy3);

        kolizije.push_back(enemy3);

        drawables.push_back(enemy);
        movables.push_back(enemy);
        drawables.push_back(enemy2);
        movables.push_back(enemy2);
        kolizije.push_back(enemy);
        kolizije.push_back(enemy2);


        drawables.push_back(player);
        movables.push_back(player);
        eventListeners.push_back(player);

        Chest *chest = new Chest(sheetChest);
        drawables.push_back(chest);
        movables.push_back(chest);
        kolizije.push_back(chest);

        Key *key = new Key(sheetKey);
        drawables.push_back(key);
        movables.push_back(key);
        kolizije.push_back(key);






        while(running){


            frameStart = SDL_GetTicks();
            while(SDL_PollEvent(&event)){
                if(event.type == SDL_QUIT){
                    running = false;
                }else{
                    for(size_t i = 0; i < eventListeners.size();i++){
                        eventListeners[i]->listen(event);
                    }
                }
            }



            for(size_t i = 0; i < movables.size();i++){
                movables[i]->move();
            }


            for(size_t i=0; i<kolizije.size();i++){
                   bool p = sp->provera(kolizije[i]);
                    if(p == true){
                        if(kolizije[i]->isKey()){
                            drawables.erase(drawables.begin()+6);
                            kolizije.erase(kolizije.begin()+4);
                            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Bravo!","Imate cvetić!",window);
                            cout<<"Pokupili ste cvet"<<endl;
                            imaKljuc=true;
                        }
                        else if(kolizije[i]->isChest() && imaKljuc==true){
                            SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"Čestitamo:","Pobedili ste!",window);
                            running = false;
                        }
                        else if(kolizije[i]->isEnemy()) {
                        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"UPS!","Ubio vas je čuvar!",window);
                            running = false;
                            }

                    }
                    else{
                        continue;
                    }
            }



            for(size_t i=0;i<blato.size();i++){
                bool p = sp->proveraZemlje(blato[i]);
                if (p){

                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,"UPS!","Izgubili ste!",window);
                    running = false;
                }
                else if(!p){
                    continue;
                }


            }


            SDL_SetRenderDrawColor(renderer, 0, 0, 0 , 255);
            SDL_RenderClear(renderer);

            for(size_t i = 0; i < drawables.size(); i++){

                drawables[i]->draw(renderer);
            }




            SDL_RenderPresent(renderer);
            frameEnd = SDL_GetTicks();


            if(frameEnd - frameStart < maxDelay){
                SDL_Delay(maxDelay - (frameEnd- frameStart));
            }}
    }




    void addTileset(Tileset *tileset, const string &name) {
        tilesets[name] = tileset;
    }

    void addTileset(istream &inputStream, const string &name) {
        addTileset(new Tileset(inputStream, renderer), name);
    }

    void addTileset(const string &path, const string &name) {
        ifstream tilesetStream(path.c_str());
        addTileset(tilesetStream, name);
    }

    Tileset* getTileset(const string &name) {
        return tilesets[name];
    }

    void addDrawable(Drawable * drawable){
        drawables.push_back(drawable);
    }




};

#endif // ENGINE_H_INCLUDED
