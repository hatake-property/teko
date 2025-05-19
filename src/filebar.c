#include "filebar.h"

#include <stdio.h>
#include <string.h>
#include "portable.h"
#include "system.h"

void printfilebar(fileinfo *file){
	invertcolor();
	if(xsize >= strlen("teko"))
	{
		printf("teko");
		if(xsize >= strlen(file->path) + strlen("teko"))
		{
			for(int i = 0; i < xsize - strlen(file->path) - strlen("teko"); i ++)
			{
				printf(" ");
			}
			printf("%s", file->path);
		}
		else
		{
			for(int i = 0; i < xsize - strlen("teko"); i ++)
			{
				printf(" ");
			}
		}
	}
	else
	{
		for(int i = 0; i < xsize; i ++)
		{
			printf(" ");
		}
	}
	invertcolor();
	printf("\n");
}
