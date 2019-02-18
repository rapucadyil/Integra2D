#include "Game.h"
#include <iostream>
#include <SDL_image.h>
using namespace std;
bool Game::init(const char* title, int xpos, int ypos, int width, int height, int flags) {

	//attempt window initialization 
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL init success\n";
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		
		if (m_pWindow != 0) {
			std::cout << "Window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

			if (m_pRenderer != 0) {
				std::cout << "Renderer creation success\n";
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
			}
			else {
				std::cout << "Renderer failed\n";
				return false;
			}
		}
		else {
			std::cout << "Window init failed\n";
			return false;
		}
	}
	else {
		std::cout << "SDL init failed\n";
		return false;
	}

	SDL_Surface* tmp = IMG_Load("spritesheet.png");
	this->currentImage = SDL_CreateTextureFromSurface(m_pRenderer, tmp);

	SDL_QueryTexture(currentImage, NULL, NULL, &textureWidth, &textureHeight);

	frameWidth = textureWidth / 5;
	frameHeight = textureHeight;

	playerRect.x = playerRect.y = 0;

	playerRect.w = frameWidth;
	playerRect.h = frameHeight;

	std::cout << "Init success\n";
	m_bRunning = true;
	return true;
}

void Game::render() {
	SDL_RenderClear(m_pRenderer);
	SDL_RenderCopy(m_pRenderer, currentImage, &playerRect, NULL);
	SDL_RenderPresent(m_pRenderer);
}

void Game::update()
{
	/* ANIM LOGIC ABSTRACT LATER */
	frameTime++;
	if (FPS / frameTime == 1) {
		frameTime = 0;
		playerRect.x += frameWidth;
		if (playerRect.x >= textureWidth) {
			playerRect.x = 0;
		}
	}
}

void Game::handleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				m_bRunning = false;
			break;
			default:
			break;
		}
	}
}

void Game::clean() {
	std::cout << "cleaning up\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}