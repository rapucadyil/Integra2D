#pragma once
#include "event.h"
#ifndef _ON_KEY_PRESS_H_
#define _ON_KEY_PRESS_H_

/* ---------------------- KEYCODE DEFINES ----------------------------- */
#define KEYCODE_A		0
#define KEYCODE_B		1
#define KEYCODE_C		2
#define KEYCODE_D		3
#define KEYCODE_E		4
#define KEYCODE_F		5
#define KEYCODE_G		6
#define KEYCODE_H		7
#define KEYCODE_I		8
#define KEYCODE_J		9
#define KEYCODE_K		10
#define KEYCODE_L		11
#define KEYCODE_M		12
#define KEYCODE_N		13
#define KEYCODE_O		14
#define KEYCODE_P		15
#define KEYCODE_Q		16
#define KEYCODE_R		17
#define KEYCODE_S		18
#define KEYCODE_T		19
#define KEYCODE_U		20
#define KEYCODE_V		21
#define KEYCODE_W		22
#define KEYCODE_X		23
#define KEYCODE_Y		24
#define KEYCODE_Z		25
#define KEYCODE_ESC		26
#define KEYCODDE_UP		27
#define KEYCODDE_DOWN	28
#define KEYCODDE_LEFT	29
#define KEYCODDE_RIGHT	30
/* ---------------------- END KEYCODE DEFINES ------------------------- */
class OnKeyPress : public Event {
private:
	int _keyCode;

public:
	OnKeyPress(int pressed, void(*keycallPtr)(float f, float s)) {
		init(pressed, keycallPtr);
	}
	OnKeyPress(int pressed, void(*keycallPtr)()) {
		init(pressed, keycallPtr);
	}
	void init(int pressed, void(*keycall)(float f, float s));
	void init(int pressed, void(*keycall)());

	void notify() override;

};

#endif