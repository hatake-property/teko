#include "portable.h"

#include "setting.h"

#if SYSTEM == SYSTEM_WINDOWS
#	include <stdlib.h>
#	include <windows.h>
#elif SYSTEM == SYSTEM_UNIX
#	include <stdlib.h>
#	include <termios.h>
#else
#	err it is an operating system that is not supported
#endif

int backcolor;
int forecolor;

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

void clear(void){
#if SYSTEM == SYSTEM_WINDOWS
	system("cls");
#elif SYSTEM == SYSTEM_UNIX
	system("clear");
#endif
}

void resetcolor(void){
#if SYSTEM == SYSTEM_WINDOWS
	HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);
	backcolor = 0;
	forecolor = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
	SetConsoleTextAttribute(terminal, backcolor | forecolor);
#elif SYSTEM == SYSTEM_UNIX
	backcolor = 40;
	forecolor = 37;
	printf("\e[%dm\e[%dm", backcolor, forecolor);
#endif
}

void invertcolor(void){
#if SYSTEM == SYSTEM_WINDOWS
	int num = backcolor;
	backcolor = forecolor * 0x10;
	forecolor = num / 0x10;
	HANDLE terminal = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(terminal, forecolor | backcolor);
#elif SYSTEM == SYSTEM_UNIX
	int num = backcolor;
	backcolor = 40 + forecolor % 10;
	forecolor = 30 + num % 10;
	printf("\e[%dm\e[%dm", backcolor, forecolor);
#endif
}
