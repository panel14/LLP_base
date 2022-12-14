#pragma once
#include "../file.c"

int storageOpenOrCreate(char* filename);
int storageRetrive(int sd, char* filename);
int storageInsert(int sd, );
int storageUpdate(int sd, );
int storageClose(int sd);