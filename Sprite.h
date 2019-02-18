#include <SDL.h>
#include <SDL_image.h>
#include "definitions.h"
#pragma once
#ifndef _SPRITE_H_
#define _SPRITE_H_

class Sprite {
    private:
    SDL_Texture* _sprtTex;
    SDL_Surface* _sprSurf;
    
    public:
    SDL_Rect* src;
    SDL_Rect* dst;
    
    SDL_RendererFlip flip;
    
    public:
    Sprite(IGstring filepath, SDL_Renderer* ren);
    ~Sprite();
    
    void draw(SDL_Renderer* ren, int x, int y,  int width, int height);
    
};

#endif