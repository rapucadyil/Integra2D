#include <iostream>
#include "eventlistener.h"
#include "event.h"

#define DEBUG	0

EventListener::EventListener() {
	this->_events = std::vector<Event*>();
}
EventListener::~EventListener() {
	for (auto& ref : this->_events) 
		delete ref;
}

void EventListener::addEvent(Event& event) {
	this->_events.insert(this->_events.begin(), &event);
}

void EventListener::removeEvent(const Event& toRemove) {
	for (int o = 0; o < _events.size(); o++) {
		if (_events[o] == &toRemove) {
			_events.erase(_events.begin() + o);
		}
	}
}

void EventListener::processQueue() {
	for (auto& evt : this->_events) {
		evt->notify();
		removeEvent(*evt);
#if DEBUG
		std::cout << this->_events.size() << std::endl; 
#endif
	}
}