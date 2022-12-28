#include <stdio.h>

#include "../headers/osFile.h"

int openOrCreateFile(char* filename, FILE* fp) {
	fp = fopen(filename, "a+");

	if (!fp) return -1;
	return 0;
}
//need in size_t offset and size_t return
int readFile(char* filename, unsigned char* buffer, long start, int offset) {
	if (fseek(filename, start, SEEK_CUR)) {
		return -1;
	}
	return fread(buffer, sizeof(unsigned char), offset, filename);
}
//need in size_t offset and size_t return
int writeFile(char* filename, unsigned char* buffer, long start, int offset) {
	if (fseek(filename, start, SEEK_CUR)) {
		return -1;
	}
	return fwrite(buffer, sizeof(unsigned char), offset, filename);
}

int deleteFile(char* filename) {
	return remove(filename);
}