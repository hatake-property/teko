#include "portable.h"

#if defined(_WIN32) || defined(_WIN64)
#	include <windows.h>
#elif defined(__linux__) || (defined(__APPLE__) && defined(__MACH))
#	include <termios.h>
#else
#	err it is an operating system that is not supported
#endif

void canonical(void){
#if defined(_WIN32) || defined(_WIN64)
	HANDLE terminal = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(terminal, &mode);
	mode |= (ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
	SetConsoleMode(terminal, mode);
#elif defined(__linux__) || (defined(__APPLE__) && defined(__MACH))
	struct termios tio;
	tcgetattr(STDIN_FILENO, &tio);
	tio.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &tio);
#endif
}

void noncanonical(void){
#if defined(_WIN32) || defined(_WIN64)
	HANDLE terminal = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(terminal, &mode);
	mode &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
	SetConsoleMode(terminal, mode);
#elif defined(__linux__) || (defined(__APPLE__) && defined(__MACH))
	struct termios tio;
	tcgetattr(STDIN_FILENO, &tio);
	tio.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &tio);
#endif
}
