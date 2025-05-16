#include "file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void openfile(fileinfo *file, char *path){
	FILE *fp;

	fp = fopen(path, "r");
	strcpy(file->path, path);
	file->content = malloc(sizeof(char[0x10000]) * 1);
	file->contentsize = 1;
	file->cursor.x = 0;
	file->cursor.y = 0;
	file->topleft.x = 0;
	file->topleft.y = 0;
	if(!file->content)
	{
		printf("insufficient memory: no get memory\n");
		exit(EXIT_FAILURE);
	}

	if(!fp)
	{
		return;
	}
	while(fgets(file->content[file->contentsize - 1], 0x10000, fp) != NULL)
	{
		file->contentsize ++;
		void *p = realloc(file->content, sizeof(char[0x10000]) * file->contentsize);
		if(!p)
		{
			printf("insufficient memory: %dth line memory\n", file->contentsize);
			free(file->content);
			exit(EXIT_FAILURE);
		}
		file->content = p;
	}
	return;
}
