#include <stdio.h>

#include "../headers/osFile.h"

int openOrCreateFile(char* filename, FILE* fp) {
	fp = fopen(filename, "a+");

	if (!fp) return -1;
	return 0;
}

int deleteFile(char* filename) {
	return remove(filename);
}