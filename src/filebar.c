#include "filebar.h"

#include "stdio.h"
#include "portable.h"

char filepath[255];

void printfilebar(void){
	invertcolor();
	printf("~teko~    %s", filepath);
	invertcolor();
	printf("\n");
}
