#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Font.h"

Font::Font(){

}

    void Font::DrawFontToTexture(SDL_Renderer* renderer,TTF_Font* font,const char* c,SDL_Color color,SDL_Texture **texture,SDL_Rect* rect){
    SDL_Surface* surface = TTF_RenderText_Solid(font,c,color);
    *texture = SDL_CreateTextureFromSurface(renderer,surface);
    rect->w = surface->w;
    rect->h = surface->h;
    SDL_FreeSurface(surface);
}