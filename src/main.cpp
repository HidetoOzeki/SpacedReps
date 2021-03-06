#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <String>
#include <vector>
#include "gfx/Button.h"
#include "gfx/Font.h"
using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;


bool hard(int score){
    return score > 80;
}
bool easy(int score){
    return score > 30;
}

void test(int score,bool (*judge)(int)){
    if((*judge)(score)){
    cout << "you have passed the test!" << endl;
    }else{
    cout << "you have failed the test!" << endl;
    }
}

int main(int arg,char* args[]){
    Uint32 flags = SDL_WINDOW_SHOWN;
    SDL_Window* window = SDL_CreateWindow("SpacedReps",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    WIDTH,HEIGHT,flags);

    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    SDL_Event event;

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    bool quit = false;

    SDL_Color red = {255,0,0};
    SDL_Color green = {0,255,0};
    SDL_Color blue = {0,0,255};
    SDL_Color white = {255,255,255};
    SDL_Color black = {0,0,0};
    
    SDL_Texture* message;
    SDL_Texture* Title;

    TTF_Font* IBM_VGA_16px = TTF_OpenFont("PxPlus_IBM_VGA8.ttf",16);
    TTF_Font* IBM_VGA_64px = TTF_OpenFont("PxPlus_IBM_VGA8.ttf",64);

    SDL_Rect rect;
    rect.x = 200;
    rect.y = 500;

    SDL_Rect rect2;
    rect2.x = 100;
    rect2.y = 100;

    const char* gowacky = "Go mentally deranged ye,go brainless ye,go wacky AHHHHHHHHHHHHHHHHHHHHHH";
    Font::DrawFontToTexture(renderer,IBM_VGA_16px,gowacky,red,&message,&rect);
    Font::DrawFontToTexture(renderer,IBM_VGA_64px,"SpacedReps",white,&Title,&rect2);

    Button button("Make a schedule",IBM_VGA_16px,white,renderer);
    button.setPosition(WIDTH/2,HEIGHT/2);

    int score = 65;
    test(score,hard);

    while(!quit){
        while(SDL_PollEvent(&event)){
        if(event.type==SDL_QUIT){
            quit = true;
            break;
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,message,NULL,&rect);
        SDL_RenderCopy(renderer,Title,NULL,&rect2);
        button.render(renderer);
        SDL_RenderPresent(renderer);
        }
    }
    SDL_DestroyTexture(message);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
    return 0;
}
