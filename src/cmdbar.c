#include "cmdbar.h"

#include "portable.h"

void printcmdbar(void){
	invertcolor();
	for(int i = 0; i < 30; i ++)
	{
		printf(" ");
	}
	invertcolor();
	printf("\n");
	return;
}
