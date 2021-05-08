#ifndef BUTTON_H
#define BUTTON_H
#include <iostream>
#include <String>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Font.h"
class Button {
    private :
    std::string name;
    public :
    int x,y;
    int POSITION = 0;
    SDL_Texture* text_texture;
    SDL_Rect text_rect;
    Button(const char* name,TTF_Font* font,SDL_Color color,SDL_Renderer* renderer);
    ~Button();
    void setPosition(int x,int y);
    void setPosition(int pos);
    void render(SDL_Renderer* renderer);

};
#endif