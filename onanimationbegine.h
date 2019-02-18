#pragma once
#include "event.h"
#ifndef _ON_ANIMATION_BEGIN_H_
#define _ON_ANIMATION_BEGIN_H_
class OnAnimationBegin : public Event {
public:
	OnAnimationBegin() {}

	void init();

//	void notify() override;
	
private:
	void animBeginCallback();
};


#endif