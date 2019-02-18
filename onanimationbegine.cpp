#include "onanimationbegine.h"
#include <iostream>
#include "eventlistener.h"

void OnAnimationBegin::init() {
//	Event::init(2, "Animation begun", "OnAnimationBegin");
}
/*
void OnAnimationBegin::notify() {
	std::cout << "Fired : " << this->_evtName << "Description : "<< this->_evtMessage << std::endl;
	animBeginCallback();
}
*/
void OnAnimationBegin::animBeginCallback() {
	/* start the animation logic over here */
}