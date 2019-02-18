#include "inputhandler.h"
#include "eventlistener.h"
#include "event.h"
#include "onkeypress.h"
#include <SDL.h>

InputHandler::InputHandler() {
	_inputListener = new EventListener();
	_windowListener = new EventListener();
}

InputHandler::~InputHandler() {
	delete _inputListener;
}

void InputHandler::handleInputEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_a) {
				Event* keypressed_a = new OnKeyPress(KEYCODE_A, move_event_callback);
				_inputListener->addEvent(*keypressed_a);
			}
			if (event.key.keysym.sym == SDLK_w) {
				Event* keypressed_w = new OnKeyPress(KEYCODE_W, move_event_callback);
				_inputListener->addEvent(*keypressed_w);
			}
			if (event.key.keysym.sym == SDLK_s) {
				Event* keypressed_w = new OnKeyPress(KEYCODE_S, move_event_callback);
				_inputListener->addEvent(*keypressed_w);
			}
			if (event.key.keysym.sym == SDLK_d) {
				Event* keypressed_w = new OnKeyPress(KEYCODE_D, move_event_callback);
				_inputListener->addEvent(*keypressed_w);
			}
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				Event* keypressed_esc = new OnKeyPress(KEYCODE_ESC, quit_event_callback);
				_inputListener->addEvent(*keypressed_esc);
			}
			break;
		case SDL_QUIT:
			Window::_closed = true;
			Logger::log("Closing down...", LT::INFO);
			break;
		case SDL_KEYUP:
			break;
		}
		_inputListener->processQueue();
	}
}