#pragma once
#include <vector>
#ifndef _EVENT_LISTENER_H_
#define _EVENT_LISTENER_H_
class Event;
class EventListener {
private:
	std::vector<Event*> _events;
public:
	EventListener();
	~EventListener();

	void addEvent(Event& event);
	void removeEvent(const Event& toRemove);

	void processQueue();

	inline std::vector<Event*> getEventQueue() { return this->_events; }

};

#endif // !_EVENT_LISTENER_H_
