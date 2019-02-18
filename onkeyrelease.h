#pragma once
#include "event.h"
#ifndef _ON_KEY_RELEASE_H_
#define _ON_KEY_RELEASE_H_

class OnKeyRelease : public Event {
private:
	int _keyCode;

public:
	OnKeyRelease(int released) {
		init(released);
	}

	void init(int released);

//	void notify() override;

};


#endif