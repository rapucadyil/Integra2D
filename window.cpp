#include <iostream>
#include <string>
#include <SDL.h>
#include "scene.h"
#include "window.h"
#include "inputhandler.h"
#include "logger.h"

bool Window::_closed = false;

Window::Window(IGstring title, int x, int y, int w, int h) {
	_windowInput = new InputHandler();
	_scenes = std::vector<Scene*>();
	init(title, x, y, w, h);
}

Window::~Window() {

	SDL_DestroyWindow(_window);
	SDL_Quit();
}


void Window::update(IGfloat dt) {
	_windowInput->handleInputEvents();
	sceneStateMachine(dt);
}

bool Window::shouldClose() {
	if (_closed)
		return true;
	return false;
}

void Window::addScene(Scene* scene) {
	_scenes.push_back(scene);
}


bool Window::init(IGstring title, int x, int y, int w, int h) {
	SDL_Init(SDL_INIT_VIDEO);
	_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_RENDERER_ACCELERATED | SDL_WINDOW_OPENGL);
	_renderer = SDL_CreateRenderer(_window, 0, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	if (_window == nullptr) {
		Logger::log("Failed to initialize SDL Window", LT::ERR);
		return false;
	}

	return true;
}

void Window::sceneStateMachine(IGfloat dt) {
	if(_currentScene->getActive()) {
		_currentScene->tick(dt, *_windowInput);
	}

}


