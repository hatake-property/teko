#include "cmdbar.h"

#include "portable.h"
#include "system.h"

void printcmdbar(void){
	invertcolor();
	for(int i = 0; i < xsize; i ++)
	{
		printf(" ");
	}
	invertcolor();
	printf("\n");
	return;
}
