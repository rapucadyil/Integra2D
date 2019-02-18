#pragma once
#ifndef _INPUT_HANDLER_H_
#define _INPUT_HANDLER_H_
class EventListener;
struct InputHandler {
	EventListener* _inputListener;
	EventListener* _windowListener;
	InputHandler();
	~InputHandler();

	void handleInputEvents();
};

#endif
