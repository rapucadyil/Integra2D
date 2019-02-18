#include "onkeyrelease.h"


void OnKeyRelease::init(int released) {
//	Event::init(0, "Key released!", "KEYRELEASE");
	this->_keyCode = released;
}

/*void OnKeyRelease::notify() {

}*/