#include "portable.h"

#include "setting.h"

#if SYSTEM == SYSTEM_WINDOWS
#	include <windows.h>
#elif SYSTEM == SYSTEM_UNIX
#	include <termios.h>
#else
#	err it is an operating system that is not supported
#endif

void canonical(void){
#if SYSTEM == SYSTEM_WINDOWS
	HANDLE terminal = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(terminal, &mode);
	mode |= (ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
	SetConsoleMode(terminal, mode);
#elif SYSTEM == SYSTEM_UNIX
	struct termios tio;
	tcgetattr(STDIN_FILENO, &tio);
	tio.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &tio);
#endif
}

void noncanonical(void){
#if SYSTEM == SYSTEM_WINDOWS
	HANDLE terminal = GetStdHandle(STD_INPUT_HANDLE);
	DWORD mode;
	GetConsoleMode(terminal, &mode);
	mode &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
	SetConsoleMode(terminal, mode);
#elif SYSTEM == SYSTEM_UNIX
	struct termios tio;
	tcgetattr(STDIN_FILENO, &tio);
	tio.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &tio);
#endif
}
