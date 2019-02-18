#include "Sprite.h"
Sprite::Sprite(IGstring filepath, SDL_Renderer* ren) {
	_sprSurf = IMG_Load(filepath);
	_sprtTex = SDL_CreateTextureFromSurface(ren, _sprSurf);
    SDL_FreeSurface(_sprSurf);
}

Sprite::~Sprite() {
    
    SDL_DestroyTexture(_sprtTex);
    
}

void Sprite::draw(SDL_Renderer* ren, int x, int y, int width, int height) {
    dst = new SDL_Rect();
    dst->x = x;
    dst->y = y;
    dst->w = width;
    dst->h = height;
    SDL_RenderClear(ren);
    SDL_RenderCopyEx(ren, _sprtTex, src, dst, 0, NULL, flip);
    SDL_RenderPresent(ren);   
    //SDL_SetTextureAlphaMod(_sprtTex, 1);
}