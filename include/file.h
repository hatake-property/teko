#ifndef TEKO_FILE
#	define TEKO_FILE

typedef struct{
	char path[1024];
	char (*)content[0x10000];
	int contentsize;
	struct{int x, int y} cursor;
	struct{int x, int y} topleft;
}fileinfo;

void openfile(fileinfo *file, char *path);
void closefile(fileinfo *file);

#endif
