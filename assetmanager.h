#pragma once
#include <SDL.h>
#include <SDL_image.h>
#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

class AssetManager {
public:
	inline static SDL_Surface* load(const char *filepath) {
		SDL_Surface *tmpSurface = IMG_Load(filepath);
		return tmpSurface;
	}
};


#endif