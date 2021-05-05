#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <String>
#include <vector>
using namespace std;

void DrawFontToTexture(SDL_Renderer* renderer,TTF_Font* font,const char* c,SDL_Color color,SDL_Texture **texture,SDL_Rect* rect){
    SDL_Surface* surface = TTF_RenderText_Solid(font,c,color);
    *texture = SDL_CreateTextureFromSurface(renderer,surface);
    rect->w = surface->w;
    rect->h = surface->h;
    SDL_FreeSurface(surface);
}

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
    800,600,flags);

    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    SDL_Event event;

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    bool quit = false;

    int i = 0;

    SDL_Color red = {255,0,0};
    SDL_Color green = {0,255,0};
    SDL_Color blue = {0,0,255};
    SDL_Color white = {255,255,255};
    SDL_Color black = {0,0,0};
    
    SDL_Texture* message;

    TTF_Font* sans_16px = TTF_OpenFont("PxPlus_IBM_VGA8.ttf",16);
    TTF_Font* sans_64px = TTF_OpenFont("PxPlus_IBM_VGA8.ttf",64);


    SDL_Rect rect;
    rect.x = 200;
    rect.y = 500;

    SDL_Texture* Title;


    SDL_Rect rect2;
    rect2.x = 100;
    rect2.y = 100;

    DrawFontToTexture(renderer,sans_16px,"Go mentally deranged ye,go brainless ye,go wacky AHHHHHHHHHHHHHHHHHHHHHH",red,&message,&rect);
    DrawFontToTexture(renderer,sans_64px,"SpacedReps",white,&Title,&rect2);

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
        i++;
        cout << i << endl;
        SDL_RenderPresent(renderer);
        }
    }
    SDL_DestroyTexture(message);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    SDL_Quit();
    return 0;
}

class Button {
    private :
    string name;
    public :
    int x,y;
    int POSITION = 0;
    SDL_Texture* text_texture;
    Button(string name){
        this->name = name;
    }
    ~Button(){}
    /*

    void render(SDL_Renderer* renderer){
        SDL_Rect rect;
        rect.x = x;
        rect.y = y;
        rect.w = 
        SDL_RenderCopy(renderer,text_texture,NULL,);
    }
    */

};