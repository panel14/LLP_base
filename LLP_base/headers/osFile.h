#pragma once
int openOrCreateFile(char* filename, FILE* fp);
int deleteFile(char* filename);
int readFile(char* filename, unsigned char* buffer, long start, int offset);
int writeFile(char* filename, unsigned char* buffer, long start, int offset);
