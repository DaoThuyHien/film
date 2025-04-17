#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "graphics.h"
#include "defs.h"

using namespace std;


int main(int argc, char *argv[])
{
    Graphics graphics;
    graphics.init();

    Mix_Music *gMusic = graphics.loadMusic("music.mp3");
    graphics.play(gMusic);
    //Mix_Chunk *gJump = graphics.loadSound("assets\\jump.wav");

//    ScrollingBackground background;
//    background.setTexture(graphics.loadTexture(BACKGROUND_IMG));

    Sprite duck;
    SDL_Texture* duckTexture = graphics.loadTexture (DUCK_SPRITE_FILE);
    duck.init(duckTexture, DUCK_FRAMES, DUCK_CLIPS);

    bool quit = false;
    SDL_Event e;
    while( !quit ) {
        while( SDL_PollEvent( &e ) != 0 ) {
            if( e.type == SDL_QUIT ) quit = true;
        }

        //const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);

        //if (currentKeyStates[SDL_SCANCODE_UP] || currentKeyStates[SDL_SCANCODE_DOWN]) graphics.play(gJump);

        SDL_Delay(20);

        //background.scroll(1);
        //man.tick(); bird.tick();
        duck.tick();

        graphics.prepareScene();
        //graphics.render1(background);
        //graphics.render(100, 100, man);
        //graphics.render(150, 100, bird);
        graphics.render(100,100,duck);
        graphics.presentScene();
        SDL_Delay(200);
    }
//    SDL_DestroyTexture( background.texture );
//    SDL_DestroyTexture(manTexture); manTexture = NULL;
//    SDL_DestroyTexture(birdTexture); birdTexture = NULL;

    SDL_DestroyTexture(duckTexture); duckTexture = NULL;

    if (gMusic != nullptr) Mix_FreeMusic( gMusic );
    //if (gJump != nullptr) Mix_FreeChunk( gJump);
    graphics.quit();
    return 0;
}
