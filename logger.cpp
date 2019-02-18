#include "logger.h"
#include <iostream>
#include <Windows.h>
void Logger::log(const char* msg, LT type) {

	HANDLE hConsole;
	int err_color = 12;
	int info_color = 15;
	int warn_color = 14;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	switch (type) {
	case LT::ERR:
		SetConsoleTextAttribute(hConsole, err_color);
		std::cout << msg << std::endl;
		break;
	case LT::INFO:
		SetConsoleTextAttribute(hConsole, info_color);
		std::cout << msg << std::endl;
		break;
	case LT::WARNING:
		SetConsoleTextAttribute(hConsole, warn_color);
		std::cout << msg << std::endl;
		break;
	}
}