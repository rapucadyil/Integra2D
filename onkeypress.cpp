#include "onkeypress.h"
#include "eventlistener.h"
#include "logger.h"
#include "window.h"
#include <SDL.h>
#include <iostream>
void OnKeyPress::init(int pressed, void(*keycall)(float f, float s)) {
	Event::init(0, "Key pressed!", "KEYPRESS", keycall);
	this->_keyCode = pressed;
}

void OnKeyPress::init(int pressed, void(*keycall)()) {
	Event::init(0, "Key pressed!", "KEYPRESS", keycall);
	this->_keyCode = pressed;
}

void OnKeyPress::notify() {
	switch (_keyCode) {
	case KEYCODE_ESC:
		this->evt_callback_n();
		Logger::log("Closing down", LT::INFO);
		break;
	case KEYCODE_W:
		this->evt_callback_f(0.0f, 3.0f);
		Logger::log("Keypressed W", LT::INFO);
		break;
	case KEYCODE_A:
		this->evt_callback_f(-3.0f, 0.0f);
		Logger::log("Keypressed A", LT::INFO);
		break;
	case KEYCODE_S:
		this->evt_callback_f(0.0f, -3.0f);
		Logger::log("Keypressed S", LT::INFO);
		break;
	case KEYCODE_D:
		this->evt_callback_f(3.0f, 0.0f);
		Logger::log("Keypressed D", LT::INFO);
		break;
	}
}
