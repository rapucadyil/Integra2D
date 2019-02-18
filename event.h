#pragma once
#ifndef _EVENT_H_
#define _EVENT_H_
#include "window.h"
#include "logger.h"
#include <iostream>
/* The base abstract class for any event in the game */
class Event {
protected:
	int _evtID;
	const char* _evtMessage;
	const char* _evtName;
public:
	Event() { }

	virtual void init(int id, const char* msg, const char* name, void(*callPtr)(void* opt1, void* opt2)) {
		this->_evtID = id;
		this->_evtMessage = msg;
		this->_evtName = name;
		this->evt_callback = callPtr;
	}

	virtual void init(int id, const char* msg, const char* name, void(*callPtr)(float first, float second)) {
		this->_evtID = id;
		this->_evtMessage = msg;
		this->_evtName = name;
		this->evt_callback_f = callPtr;
	}

	virtual void init(int id, const char* msg, const char* name, void(*callPtr)()) {
		this->_evtID = id;
		this->_evtMessage = msg;
		this->_evtName = name;
		this->evt_callback_n = callPtr;
	}

	~Event() {}

	virtual void notify() {

	}

	inline int getID() { return this->_evtID; }
	inline const char* getMessage() { return this->_evtMessage; }
	inline const char* getName() { return this->_evtName; }

	bool operator==(const Event& other) {
		return  (this->_evtID == other._evtID)
			&& (this->_evtName == other._evtName) && (this->_evtMessage == other._evtMessage);
	}
public:
	void(*evt_callback)(void* first, void* second);
	void(*evt_callback_f)(float first, float second);
	void(*evt_callback_n)();
};
/* EVENT CALLBACK FUNCTIONS */
inline void quit_event_callback() {
	Window::_closed = true;
}
inline void move_event_callback(float xspeed, float yspeed) {
	std::cout << "xspeed: " << xspeed << " yspeed: " << yspeed << std::endl;
}
#endif