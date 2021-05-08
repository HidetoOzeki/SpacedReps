#ifndef FONT_H
#define FONT_H
class Font{
    public :
    Font();
    static void DrawFontToTexture(SDL_Renderer* renderer,TTF_Font* font,const char* c,SDL_Color color,SDL_Texture **texture,SDL_Rect* rect);
};
#endif