#pragma once
#ifndef _LOGGER_H_
#define _LOGGER_H_

enum class LT {
	ERR,
	INFO,
	WARNING
};

struct Logger {

	const char* message;
	LT type;

	static void log(const char* msg, LT type);

};

#endif