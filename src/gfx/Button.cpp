#include "Button.h"

    Button::Button(const char* name,TTF_Font* font,SDL_Color color,SDL_Renderer* renderer){
        this->name = name;
        Font::DrawFontToTexture(renderer,font,name,color,&text_texture,&text_rect);
    }
    Button::~Button(){}
    void Button::setPosition(int x,int y){
        Button::x = x;
        Button::y = y;
        text_rect.x = x;
        text_rect.y = y;
    }
    void Button::setPosition(int pos){
        POSITION = pos;
    }
    void Button::render(SDL_Renderer* renderer){
        SDL_RenderCopy(renderer,text_texture,NULL,&text_rect);
    }