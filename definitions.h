#pragma once
#include <iostream>
typedef unsigned int IGuint;
typedef const char* IGstring;
typedef float IGfloat;
typedef bool IGboolean;

/*----------------- SCREEN RESOLUTION -----------------*/
#define SCREEN_HEIGHT	480
#define SCREEN_WIDTH	640

/*----------------- ARCHETYPES FOR ECS ---------------*/
typedef enum Archetype {
	PLAYER		= 0,
	NPC			= 1,
	ENEMY		= 2,
	NONETYPE	= 3
}Archetype;


