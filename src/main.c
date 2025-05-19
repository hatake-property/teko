#include <stdio.h>
#include "file.h"
#include "portable.h"
#include "system.h"

int main(int argc, char **argv){
	fileinfo file;
	int c;

	if(argc != 2)
	{
		return -1;
	}
	openfile(&file, argv[1]);
	gettermsize(&xsize, &ysize);
	noncanonical();
	while(1)
	{
		printfilebar();
		for(int i = 0; i < ysize - 3; i ++)
		{
			printf("\n");
		}
		printcmdbar();
		c = getchar();
		if(c == 'q' || c == 'Q')
		{
			break;
		}
	}
	canonical();
	closefile(&file);
}
