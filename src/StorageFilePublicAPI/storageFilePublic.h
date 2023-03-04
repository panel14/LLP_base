#pragma once
#include <stdio.h>
#include <stdbool.h>
//?
#include <stddef.h>

#include "../StorageFileInnerAPI/storageFileInner.h"
#include "../Utils/sstring.h"

enum storageOp {
	SUCCESS = 0,
	ID_FORMAT_FAIL,
	WRONG_ARGS_NUMBER_FAIL,
	TEMPLATE_FAIL,
	CONVERSION_FAIL,
	ID_NOT_EXIST_FAIL,
	FIELD_DOES_NOT_EXIST
};

int storageOpenOrCreateFile(char* filename, char* mode, FILE** fp);
void storageRetriveNode(FILE* fp, char** argv, size_t templateSize, const uint32_t* templateTypes, char** templateNames, size_t count);
enum storageOp storageInsertNode(FILE* fp, char** str, size_t templateSize, const uint32_t* templateTypes, char** templateNames);
enum storageOp storageUpdateNode(FILE* fp, char** str, size_t templateSize, const uint32_t* templateTypes, char** templateNames, size_t fieldsCount);
enum storageOp storageDeleteNode(FILE* fp, char* idStr, uint8_t isStr);
void storageCloseFile(FILE* fp);
void storageGetHelp();