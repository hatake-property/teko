#include "file.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void openfile(fileinfo *file, char *path){
	FILE *fp;

	fp = fopen(path, "r");
	strcpy(file->path, path);
	file->content = malloc(sizeof(char) * 0x100);
	file->contentsize = 0x100;
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
		file->content[0] = '\0';
		return;
	}
	for(int i = 0; ; i ++)
	{
		int c = fgetc(fp);
		if(i >= file->contentsize){
			void *p = realloc(file->content, sizeof(char) * (file->contentsize + 0x100));
			file->contentsize += 0x100;
			if(!p)
			{
				free(file->content);
				printf("insufficient memory: 0x%x byte memory", file->content);
				exit(EXIT_FAILURE);
			}
			if(c == EOF)
			{
				file->contentsize[i] = '\0';
				break;
			}
			else
			{
				file->contentsize[i] = c;
			}
		}
	}
	return;
}
